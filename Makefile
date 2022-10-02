CC	= gcc -m64 -w

#.. What optimization level for the compilers?
#COPT	= -O2
COPT	= -g


GRARC	 = sort.a
GRSRCS	 = swap.c selectSort.c main.c
GROBJS	 = swap.o selectsort.o main.o insertsort.o bubblesort.o mergesort.o quicksort.o heapsort.o
HEADER   = sort.h

runsort: $(GROBJS)
	$(CC) $(COPT) -o runsort $(GROBJS) 

main.o: main.c sort.h
	$(CC) $(COPT) -c main.c -o main.o
swap.o: swap.c sort.h
	$(CC) $(COPT) -c swap.c -o swap.o
selectsort.o: selectSort.c sort.h
	$(CC) $(COPT) -c selectSort.c -o selectsort.o
insertsort.o: insertSort.c sort.h
	$(CC) $(COPT) -c insertSort.c -o insertsort.o
bubblesort.o: bubbleSort.c sort.h
	$(CC) $(COPT) -c bubbleSort.c -o bubblesort.o
mergesort.o: mergeSort.c sort.h
	$(CC) $(COPT) -c mergeSort.c -o mergesort.o
quicksort.o: quickSort.c sort.h
	$(CC) $(COPT) -c quickSort.c -o quicksort.o
heapsort.o:heapSort.c sort.h
	$(CC) $(COPT) -c heapSort.c -o heapsort.o
clean   :
	rm -f $(GROBJS) runsort
