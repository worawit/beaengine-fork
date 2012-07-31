
CC = gcc
CFLAGS = -O3 
CFLAGS_SO = -fPIC -shared -fvisibility=hidden -DBUILD_BEA_ENGINE_DLL

OUTDIR = build
SRC = BeaEngine.c
ALLSRCS = $(SRC) $(wildcard beaengine/*.h) $(wildcard Includes/*.[ch]) $(wildcard Includes/instr_set/*.[ch])

OUTOBJ = $(OUTDIR)/libBeaEngineFork.o
OUTLIBA = $(OUTDIR)/libBeaEngineFork.a
OUTSO = $(OUTDIR)/libBeaEngineFork.so

all: shared static

$(OUTSO): $(ALLSRCS)
	$(CC) $(CFLAGS) $(CFLAGS_SO) -o $@ $(SRC)
	strip -s $@
	cp $(OUTSO) python/beafork/

$(OUTLIBA): $(OUTOBJ)
	ar rs $@ $(OUTOBJ)

$(OUTOBJ): $(ALLSRCS)
	$(CC) -c -O2 -o $@ $(SRC)

$(OUTDIR):
	mkdir $(OUTDIR)

shared: $(OUTDIR) $(OUTSO)

static: $(OUTDIR) $(OUTLIBA)

clean:
	rm $(OUTOBJ) $(OUTLIBA) $(OUTSO)

