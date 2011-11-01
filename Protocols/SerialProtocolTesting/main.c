#include <stdio.h>
#include <stdlib.h>

#include "..\common\serial\SerialProtocol.h"










SerialData ser;



/* The transmit function will pass the data back to the process function (loopback behavior)
 * In an MCU, the transmit function might send data through the USART interface
 * In a computer, the transmit function might send the byte to a com port
 * NOTE: data will never be 0 or 255 (these values are likely results of a frame error,
                                      so they are ignored)
 */
void Transmit(byte data)
{
//    printf(" %d", data);
    ProcessDataChar(&ser, data);
}

/* Called when the whole packet is transferred
 * Beware: This may be called in interrupt context
 * within a MCU, so don't take a long time
 * processing junk!
 */
void TransmitPacketComplete (void)
{
    printf("\n");
    printf("Packet Transfer Complete\n");
}

/* Called when the whole packet is received
 * Beware: This may be called in interrupt context
 * within a MCU, so don't take a long time
 * processing junk!
 */
void ReceivePacketComplete (SerialData * s)
{
    printf("\n\nSerial Receive Complete: Address = %d, Length = %d\n   Data: ", s->receive_address, s->receive_data_count);
    unsigned char i = 0;

    /* Do something with the data here!*/
    for (i = 0; i<s->receive_data_count; i++)
    {
        printf("%d ", s->receive_data[i]);
    }
    printf("\n");
}

/* Called when serial data receive has an error
 * Beware: This may be called in interrupt context
 * within a MCU, so don't take a long time
 * processing junk!
 */
void ReceiveDataError (byte errCode)
{
    printf("Serial Receive Data Error: %d\n", errCode);
}


int main()
{
    SerialDataInitialize(&ser);

    // Setup function pointers
    ser.TransmitPacketComplete = &TransmitPacketComplete;
    ser.Transmit = &Transmit;
    ser.ReceivePacketComplete = &ReceivePacketComplete;
    ser.ReceiveDataError = &ReceiveDataError;

    // Setup the serial data buffer
    unsigned char i;
    for (i = 0; i<20; i++)
    {
        ser.transmit_data[i] = i;
    }

    if (SerialTransmit(&ser, 202, 20)!= 0)
    {
        printf("Error!\n");
    }
    else
    {
        // Emulate hardware serial operation
        while (SerialTransferInProgress(&ser))
        {
            SerialByteTransmitComplete(&ser);
        }
    }

    if (SerialTransmit(&ser, 92, 4)!= 0)
    {
        printf("Error!\n");

    }
    else
    {
        // Emulate hardware serial operation
        while (SerialTransferInProgress(&ser))
        {
            SerialByteTransmitComplete(&ser);
        }
    }

    return 0;
}
