CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0
CFLAGS =
LDFLAGS= -lcrypto

OBJS =     main.o    \
	    hashfunc.o    \
            filefunc.o

BUILDDIR = ../build/
TARGET =    ../build/test
$(TARGET):   $(foreach i,$(OBJS), ../build/$(i))
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)main.o: main.cpp
	$(CXX) $(CFLAGS) -I../include -o ../build/$@ -c $<

$(BUILDDIR)filefunc.o: filefunc.cpp
	$(CXX) $(CFLAGS) -I../include -o ../build/$@ -c $<

$(BUILDDIR)hashfunc.o: hashfunc.cpp
	$(CXX) $(CFLAGS) -I../include -o ../build/$@ -c $<

.PHONY: all
all:$(TARGET)

clean:
	rm -f $(foreach i,$(OBJS), ../build/$(i)) $(TARGET)
