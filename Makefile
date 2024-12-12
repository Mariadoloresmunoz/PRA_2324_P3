bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

testTableEntry: bin/testTableEntry
	./bin/testTableEntry

bin/testHashTable: testHashTable.cpp HashTable.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

testHashTable: bin/testHashTable
	./bin/testHashTable

bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

testBSTree: bin/testBSTree
	./bin/testBSTree

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

testBSTreeDict: bin/testBSTreeDict
	./bin/testBSTreeDict

clean:
	rm -rf *.o *.gch bin
