CC = clang
CXX = clang++

SparseVectorTest:
	${CXX} -std=c++11 -g -O2 -c -o SparseVectorTest.o SparseVectorTest.cpp
	${CXX} -std=c++11 -o SparseVectorTest SparseVectorTest.o roaring.o

roaring:
	${CC} -O2 -c -o roaring.o roaring.c

.PHONY: clean
clean:
	@rm SparseVectorTest.o SparseVectorTest
