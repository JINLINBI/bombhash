CC=g++
CFLAGS=
INCLUDE=../include

test: test_tree.o restrict_tree.o
	g++ -g $^ -I$(INCLUDE)  -o $@

restrict_tree.o: ../source/restrict_tree.cpp
	$(CC) -c -o $@  $^ $(CFLAGS) -I$(INCLUDE)

test_tree.o: test_tree.cpp restrict_tree.o
	$(CC) -c -o $@  $^ $(CFLAGS) -I$(INCLUDE)

.PHONY:
	./test
clean:
	rm *.o && rm test
