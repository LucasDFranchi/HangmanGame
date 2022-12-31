OUTDIR = ./out
SRCDIR = ./functions
GHPDIR = ./graphics

output: hangman functions main
	g++ $(OUTDIR)/main.o $(OUTDIR)/functions.o $(OUTDIR)/hangman.o -o output.exe

main: main.cpp
	g++ -Wall -c main.cpp -o $(OUTDIR)/main.o

functions: $(SRCDIR)/functions.cpp $(SRCDIR)/functions.hpp
	g++ -Wall -c $(SRCDIR)/functions.cpp -o $(OUTDIR)/functions.o

hangman: $(GHPDIR)/hangman.cpp $(GHPDIR)/hangman.hpp
	g++ -Wall -c $(GHPDIR)/hangman.cpp -o $(OUTDIR)/hangman.o
clean:
	rm -Rf $(OUTDIR)/*.o $(OUTDIR)/*.exe