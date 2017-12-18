#Makefile Variables
CC = g++     
LD = $(CC)
CCFLAGS = -Wall -Wno-deprecated --std=c++11 -g -c   
LDFLAGS = -Wall --std=c++11 -Wno-deprecated -g
OBJS = main.o Intersection.o Lane.o Section.o Clock.o Parser.o TrafficLight.o Vehicle.o Random.o
TESTS = SectionTester MainTester ParserTester
################################################################################

#compiles main from .o files
main: $(OBJS) 
	$(LD) $(LDFLAGS) $(OBJS) -o $@

r: 									#runs main
	./main simulation.config

gdb:
	gdb ./main 

v:
	valgrind -v --leak-check=full ./main 

clean: 							#removes executable and output file
	rm main
	rm SectionTester
	rm ParserTester
	rm mainTester

reallyclean: clean 	#cleans and removes all .o files
	rm *.o

o:
	vim main.cpp +":tabf Section.cpp" +":vsplit Section.h" +":tabf Lane.cpp" +":vsplit Lane.h" +":tabf Intersection.cpp" +":vsplit Intersection.h" +":tabf Vehicle.cpp" +":vsplit Vehicle.h"

test: $(TESTS) 			#TODO finish

################################################################################
# O Compilers -- reduces recompilation TODO finish
################################################################################
main.o: main.cpp Intersection.cpp TrafficLight.cpp Clock.cpp Random.cpp
	$(CC) $(CCFLAGS) $<

Intersection.o: Intersection.cpp Lane.cpp Section.cpp
	$(CC) $(CCFLAGS) $<

Lane.o: Lane.cpp Section.cpp
	$(CC) $(CCFLAGS) $<

Section.o: Section.cpp 
	$(CC) $(CCFLAGS) $<
	
Clock.o: Clock.cpp 
	$(CC) $(CCFLAGS) $<

Random.o: Random.cpp 
	$(CC) $(CCFLAGS) $<

Vehicle.o: Vehicle.cpp Section.cpp Lane.cpp Random.cpp
	$(CC) $(CCFLAGS) $<

################################################################################
# Tester O Compilers -- reduces recompilation TODO finish
################################################################################
SectionTester: SectionTester.cpp Section.cpp
	$(CC) $(LDFLAGS) SectionTester.cpp Section.cpp -o $@

