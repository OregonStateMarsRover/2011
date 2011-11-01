SYSTEM     = xmega
COMMON_DIR = ../Common
PROJECT    = AnalogController

OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.c,%.o,$(wildcard */*.c))

default: rover

include $(COMMON_DIR)/Makefile.app

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -std=c99 -c  $< -o $@

rover: comm serial $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(COMM_LIB) $(SERIAL_LIB) $(LIBDIRS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(OBJECTS)
	rm -f $(PROJECT).map $(PROJECT).elf $(PROJECT).hex $(PROJECT).eep

