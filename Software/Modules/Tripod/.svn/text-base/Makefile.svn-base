SYSTEM     = atmega644p
COMMON_DIR = ../../Common
PROJECT    = Tripod

OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.c,%.o,$(wildcard */*.c))

default: test

include $(COMMON_DIR)/Makefile.app

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o $@

test: comm serial $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(COMM_LIB) $(SERIAL_LIB) $(LIBDIRS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(OBJECTS)
	rm -f $(PROJECT).map $(PROJECT).elf $(PROJECT).hex $(PROJECT).eep

