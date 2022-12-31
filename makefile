OUTDIR = ./out
SRCDIR = ./functions

output: functions main
	g++ $(OUTDIR)/main.o $(OUTDIR)/functions.o -o output.exe

main: main.cpp
	g++ -Wall -c main.cpp -o $(OUTDIR)/main.o

functions: $(SRCDIR)/functions.cpp $(SRCDIR)/functions.hpp
	g++ -Wall -c $(SRCDIR)/functions.cpp -o $(OUTDIR)/functions.o

clean:
	rm -Rf $(OUTDIR)/*.o $(OUTDIR)/*.exe