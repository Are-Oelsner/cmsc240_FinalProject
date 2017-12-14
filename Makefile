default:
	g++ RandomTester.cpp

o:
	vim -p Vehicle.h Intersection.h Lane.h Section.h TrafficLight.h Random.h Clock.h Parser.h

clean:
	rm a.out
