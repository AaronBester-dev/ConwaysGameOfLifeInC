all: cgol dcgol

cgol: cgol.o playCGOL.o printGrid.o
	gcc -ansi -Wall cgol.o playCGOL.o printGrid.o -o cgol

dcgol: dcgol.o 
	gcc -ansi -Wall dcgol.o  -o dcgol

dcgol.o: dcgol.c
		gcc -ansi -Wall -c dcgol.c



cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c
playCGOL.o: playCGOL.c
	gcc -ansi -Wall -c playCGOL.c
printGrid.o: printGrid.c
		gcc -ansi -Wall -c printGrid.c

clean:
	rm cgol cgol.o printGrid.o playCGOL.o dcgol.o dcgol dPlayCGOL.o dPrintGrid.o
