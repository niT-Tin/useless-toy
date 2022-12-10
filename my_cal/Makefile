
CXXFLAGS = 

flq: flq.o achieve.o F_achieve.o
	g++ -o flq $(CXXFLAGS) achieve.o F_achieve.o flq.o
flq.o: flq.cpp flqh.h
	g++ -c $(CXXFLAGS) flq.cpp
achieve.o: achieve.cpp flqh.h
	g++ -c $(CXXFLAGS) achieve.cpp
F_achieve.o: F_achieve.cpp
	g++ -c $(CXXFLAGS) F_achieve.cpp

clean:
	rm flq.o achieve.o F_achieve.o flq
