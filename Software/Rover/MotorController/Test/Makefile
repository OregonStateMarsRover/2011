# Compiles TetMotorController.c test app

SYSTEM     = x86
COMMON_DIR = ../../../Common
OBJECTS    = TestMotorController.o
PROJECT    = TestMotorController

default: app

include $(COMMON_DIR)/Makefile.app

MotorController.o: ../MotorController.c
	$(CC) $(INCLUDES) $(CFLAGS) -c ../MotorController.c

TetsMotorController.o: TestMotorController.c
	$(CC) $(INCLUDES) $(CFLAGS) -c TestMotorController.c

app: comm serial TestMotorController.o MotorController.o
	$(CC) $(LDFLAGS) $(OBJECTS) MotorController.o $(COMM_LIB)  $(SERIAL_LIB) $(LIBDIRS) $(LIBS) -o $(TARGET)

clean:
	rm -f TestMotorController.o MotorController.o
	rm -f $(PROJECT).map $(PROJECT).elf $(PROJECT).hex $(PROJECT).eep
