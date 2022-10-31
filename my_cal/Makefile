flq: flq.o achieve.o F_achieve.o
	g++ -o flq achieve.o F_achieve.o flq.o
flq.o: flq.cpp flqh.h
	g++ -c flq.cpp
achieve.o: achieve.cpp flqh.h
	g++ -c achieve.cpp
F_achieve.o: F_achieve.cpp
	g++ -c F_achieve.cpp

clean:
	rm flq.o achieve.o F_achieve.o flq
