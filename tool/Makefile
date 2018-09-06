CC=g++
INCLUDE=../include
SOURCE=../source/

dumpfile: filefunc.o dumpfile.o
	$(CC) $^ -o $@ -I$(INCLUDE)

filefunc.o: $(SOURCE)filefunc.cpp
	$(CC) -c -o $@ $^ -I$(INCLUDE)

dumpfile.o: dumpfile.cpp
	$(CC) -c -o $@ $^ -I$(INCLUDE)


clean:
	rm *.o dumpfile
