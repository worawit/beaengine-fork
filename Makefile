
CC = gcc
CFLAGS = -O3 -fPIC -shared
SRC = BeaEngine.c
ALLSRCS = $(SRC) $(wildcard beaengine/*.h) $(wildcard Includes/*.[ch]) $(wildcard Includes/instr_set/*.[ch])

all: shared lite

libBeaEngine.so: $(ALLSRCS)
	$(CC) $(CFLAGS) -o $@ $(SRC)
	strip -s $@

libBeaEngineLite.so: $(ALLSRCS)
	$(CC) $(CFLAGS) -DBEA_LIGHT_DISASSEMBLY -o $@ $(SRC)
	strip -s $@

shared: libBeaEngine.so

lite: libBeaEngineLite.so

clean:
	rm libBeaEngine.so libBeaEngineLite.so

