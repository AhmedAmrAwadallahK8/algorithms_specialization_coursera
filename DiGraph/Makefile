CC = g++
CFLAGS = -Wall -g3 -static

main: main.o test_sparse_digraph.o sparse_digrph.o divertex.o file_reader.o
	$(CC) $(CFLAGS) -o output main.o test_sparse_digraph.o sparse_digrph.o divertex.o file_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test_sparse_digraph.o: tests/test_sparse_digraph.cpp
	$(CC) $(CFLAGS) -c tests/test_sparse_digraph.cpp

sparse_digrph.o: src/sparse_digrph.cpp
	$(CC) $(CFLAGS) -c src/sparse_digrph.cpp

divertex.o: src/divertex.cpp
	$(CC) $(CFLAGS) -c src/divertex.cpp

file_reader.o: ../FileHandling/src/file_reader.cpp
	$(CC) $(CFLAGS) -c ../FileHandling/src/file_reader.cpp