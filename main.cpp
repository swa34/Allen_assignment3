#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include <sstream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
  DoublyLinkedList<int> intList;
  DoublyLinkedList<float> dbList;
  DoublyLinkedList<string> stringList;
  char input;
  int fileInput;
  vector<int> arr;
  cout << "Enter list type (i - int, f - float, s - std::string):";
  cin >> input;
  cout << "Test line " << input << endl;
  if (input == 'i') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\int-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	int n;
	while (fs >> n) {
	  //arr.push_back(n);
	  intList.insertItem(n);
	}
	//intList.print();
	fs.close();
	cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m),\n"
			"printReverse(r), swapAtl(s), quit (q)" << endl;
	bool loop = true;
	char character; // character input when entering a command

	while (loop) {
	  cout << "\nEnter a command: ";
	  cin >> character;
	  cout << "\n";

	  switch (character) {
		case 'i': {
		  int num;
		  cout << "Number to insert: ";
		  cin >> num;
		  intList.insertItem(num);
		  cout << endl;
		  intList.print();

		  cout << endl;

		  break;
		}
		case 'd': {
		  int num;
		  string str;
		  float flt;
		  string s;
		  int x;
		  cout << "Number to delete: ";
		  cin.ignore();
		  getline( cin, str );
		  istringstream iss(str);
		  while(iss >> x){
			intList.deleteItem(x);

		  }
		  intList.print();


		  break;
		}
		case 'p': {
		  intList.print();
		  stringList.print();
		  dbList.print();
		  break;
		}
		case 'r': {
		  intList.printReverse();
		  intList.print();
		  stringList.printReverse();
		  stringList.print();
		  break;
		}
		case 'q': { // quit command that stops the while loop and exits the program
		  cout << "Quitting program..." << endl;
		  loop = false;
		  break;
		}
		default: { // this will print when the command is invalid
		  cout << "Invalid command, try again!" << endl;
		  break;
		}

	  }
	}
  } else if (input == 'f') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\float-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	float n;
	while (fs >> n) {
	  //arr.push_back(n);
	  dbList.insertItem(n);
	}
	//dbList.print();
	fs.close();

  } else if (input == 's') {
	ifstream fs;
	"C:\\Users\\scott\\CLionProjects\\Allen_assignment2\\input.txt";
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\string-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	string str;
	while (getline(fs, str)) {
	  //arr.push_back(n);
	  stringList.insertItem(str);
	}
	//stringList.print();
	fs.close();

  } else {
	cout << "Invalid entry";
  }
//  cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m),\n"
//		  "printReverse(r), swapAtl(s), quit (q)" << endl;
//  bool loop = true;
//  char character; // character input when entering a command
//
//  while (loop) {
//	cout << "\nEnter a command: ";
//	cin >> character;
//	cout << "\n";
//
//	switch (character) {
//	  case 'i': {
//		int num;
//		cout << "Number to insert: ";
//		cin >> num;
//		intList.insertItem(num);
//		cout << endl;
//		intList.print();
//
//		cout << endl;
//
//		break;
//	  }
//	  case 'd': {
//		int num;
//		string str;
//		float flt;
//		string s;
//		int x;
//		cout << "Number to delete: ";
//		cin.ignore();
//		getline( cin, str );
//		  istringstream iss(str);
//		  while(iss >> x){
//		  intList.deleteItem(x);
//
//		}
//           intList.print();
//
//
//		break;
//	  }
//	  case 'p': {
//		intList.print();
//		stringList.print();
//		dbList.print();
//		break;
//	  }
//	  case 'r': {
//		intList.printReverse();
//		intList.print();
//		stringList.printReverse();
//		stringList.print();
//		break;
//	  }
//	  case 'q': { // quit command that stops the while loop and exits the program
//		cout << "Quitting program..." << endl;
//		loop = false;
//		break;
//	  }
//	  default: { // this will print when the command is invalid
//		cout << "Invalid command, try again!" << endl;
//		break;
//	  }
//
//	}
//  }
}

