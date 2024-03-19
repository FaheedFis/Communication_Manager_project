CXX = g++
CXXFLAGS = -Wall

proj5: proj5.cpp Manager.o Communicator.o Message.o Lqueue.o
	$(CXX) $(CXXFLAGS) proj5.cpp Manager.o Communicator.o Message.o Lqueue.o -o proj5

Manager.o: Manager.h Manager.cpp Communicator.o Message.o Lqueue.o
	$(CXX) $(CXXFLAGS) -c Manager.cpp

Communicator.o: Communicator.h Communicator.cpp Message.o Lqueue.o
	$(CXX) $(CXXFLAGS) -c Communicator.cpp

Message.o: Message.h Message.cpp
	$(CXX) $(CXXFLAGS) -c Message.cpp

Lqueue.o: Lqueue.cpp
	$(CXX) $(CXXFLAGS) -c Lqueue.cpp

clean:
	rm *.o
	rm *~

run1:
	./proj5 proj5_data1.txt

val1:
	valgrind ./proj5 proj5_data1.txt

run2:
	./proj5 proj5_data2.txt

val2:
	valgrind ./proj5 proj5_data2.txt

run3:
	./proj5 proj5_data3.txt

val3:
	valgrind ./proj5 proj5_data3.txt

submit:
	cp Message.h Message.cpp Lqueue.cpp Manager.h Manager.cpp Communicator.h Communicator.cpp ~/cs202proj/proj5


###*************COMMANDS TO TEST Lqueue****************
lqueue_test: Lqueue.cpp lqueue_test.cpp
	$(CXX) $(CXXFLAGS) Lqueue.cpp lqueue_test.cpp -o lqueue_test

test:
	valgrind ./lqueue_test
