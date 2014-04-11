all:
	g++ -g -std=c++0x src/scratch.cpp src/Event.cpp src/OrderedSet.cpp src/Queue.cpp src/Customer.cpp src/CustomerArrival.cpp src/Server.cpp src/Simulator.cpp -o scratch
