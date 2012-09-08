Binary_Tree:Binary_Tree_Test_Client.o Binary_Tree_Impl.o
	g++ -o Binary_Tree Binary_Tree_Test_Client.o Binary_Tree_Impl.o

Binary_Tree_Test_Client.o: Binary_Tree_Test_Client.cpp
	g++ -c Binary_Tree_Test_Client.cpp

Binary_Tree_Impl.o: Binary_Tree_Impl.cpp
	g++ -c Binary_Tree_Impl.cpp


clean:
	rm -f *.o

clean_all:
	rm -f *.o Binary_Tree
