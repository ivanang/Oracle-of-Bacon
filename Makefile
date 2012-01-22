oracle: OracleOfBacon.cpp OracleNode.o HashTableDictionary.o ArrayList.o DNode.o LinkedQueue.o QNode.o
	g++ -g oracle OracleOfBacon.cpp OracleNode.o HashTableDictionary.o ArrayList.o DNode.o LinkedQueue.o QNode.o

OracleNode.o: OracleNode.h OracleNode.cpp
	g++ -g -c OracleNode.cpp

HashTableDictionary.o: Dictionary.h HashTableDictionary.h HashTableDictionary.cpp
	g++ -g -c HashTableDictionary.cpp

ArrayList.o: List.h ArrayList.h ArrayList.cpp
	g++ -g -c ArrayList.cpp

DNode.o: ArrayList.h DNode.h DNode.cpp
	g++ -g -c DNode.cpp

LinkedQueue.o: Queue.h LinkedQueue.h LinkedQueue.cpp
	g++ -g -c LinkedQueue.cpp

QNode.o: QNode.h QNode.cpp
	g++ -g -c QNode.cpp

clean:
	rm *.o oracle
