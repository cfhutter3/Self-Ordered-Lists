#include <string>
#include <iostream>
#include "MoveToFrontSOL.h"
#include "CountSOL.h"
#include "TransposeSOL.h"
#include <fstream>

using namespace std;

enum Mode{COUNT, MOVETOFRONT, TRANSPOSE};

void testSOL(Mode mode, SelfOrderedListADT<char>* SOL);
void testSOL(Mode mode, SelfOrderedListADT<string>* SOL);


int main() {
	//char tests
	testSOL(COUNT, new CountSOL<char>);
	testSOL(MOVETOFRONT, new MoveToFrontSOL<char>);
	testSOL(TRANSPOSE, new TransposeSOL<char>);
	
	//string tests
	testSOL(COUNT, new CountSOL<string>);
	testSOL(MOVETOFRONT, new MoveToFrontSOL<string>);
	testSOL(TRANSPOSE, new TransposeSOL<string>);

	/*SelfOrderedListADT<int>* SOL = new CountSOL<int>;

	for (int i{ 0 }; i < 5; i++) {
		SOL->add(i);
	}
	cout << endl << "-----------------" << endl;
	SOL->printlist();

	SOL->find(4);
	cout << endl << "-----------------" << endl;
	SOL->printlist();
	SOL->find(2);
	cout << endl << "-----------------" << endl;
	SOL->printlist();
	SOL->find(3);
	cout << SOL->getCompares() << endl;
	SOL->printlist();*/
	
	system("pause");
	return 0;
}

void testSOL(Mode mode, SelfOrderedListADT<char>* SOL) {
	if (mode == MOVETOFRONT) {
		cout << "MOVE TO FRONT SOL CHAR TESTS:\n";
	}
	else if (mode == COUNT) {
		cout << "COUNT SOL CHAR TESTS:\n";
	}
	else if (mode == TRANSPOSE) {
		cout << "TRANSPOSE SOL CHAR TESTS:\n";
	}
	for (int i{ 65 }; i < 73; i++) {
		SOL->add(i);
	}
	SOL->find('F');
	SOL->find('D');
	SOL->find('F');
	SOL->find('G');
	SOL->find('E');
	SOL->find('G');
	SOL->find('F');
	SOL->find('A');
	SOL->find('D');
	SOL->find('F');
	SOL->find('G');
	SOL->find('E');
	SOL->find('H');
	SOL->find('I');
	
	cout << " Total compares: " << SOL->getCompares() << endl;
	cout << " List size of list: " << SOL->size() << endl;
	cout << " Final list structure with frequencies:\n";
	SOL->printlist();
	cout << endl;
}

void testSOL(Mode mode, SelfOrderedListADT<string>* SOL) {
	string word;
	ifstream file;
	file.open("test.txt");
	if (mode == MOVETOFRONT) {
		cout << "MOVE TO FRONT SOL STRING TESTS:\n";
	}
	else if (mode == COUNT) {
		cout << "COUNT SOL STRING TESTS:\n";
	}
	else if (mode == TRANSPOSE) {
		cout << "TRANSPOSE SOL STRING TESTS:\n";
	}

	while (file) {
		file >> word;
		SOL->find(word);
	}
	file.close();
	cout << " Total compares: " << SOL->getCompares() << endl;
	cout << " List size of list: " << SOL->size() << endl;
	cout << " Final list structure with frequencies:\n";
	SOL->printlist(10);
	cout << endl;
}