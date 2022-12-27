output: main.o 
	g++ -Wall main.cpp -o output.exe

clean:
	rm *.o *.exe