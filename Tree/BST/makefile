BST:BST_Test_Client.o BST_Impl.o
	g++ -o BST BST_Test_Client.o BST_Impl.o

BST_Test_Client.o: BST_Test_Client.cpp
	g++ -c BST_Test_Client.cpp

BST_Impl.o: BST_Impl.cpp
	g++ -c BST_Impl.cpp


clean:
	rm -f *.o

clean_all:
	rm -f *.o BST
