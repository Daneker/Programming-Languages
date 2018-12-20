
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wall -std=c++14 -O3
CPP = g++ -flto


main : Makefile   main.o listtest.o vectortest.o map.o
	$(CPP) $(Flags) -o main   main.o listtest.o vectortest.o map.o

main.o : Makefile   main.cpp   vectortest.h listtest.h timer.h
	$(CPP) -c $(Flags) main.cpp -o  main.o


listtest.o : Makefile   listtest.cpp   listtest.h 
	$(CPP) -c $(Flags) listtest.cpp -o  listtest.o


vectortest.o : Makefile   vectortest.cpp   vectortest.h 
	$(CPP) -c $(Flags) vectortest.cpp -o  vectortest.o

map.o : Makefile map.cpp map.h
	$(CPP) -c $(Flags) map.cpp -o map.o


