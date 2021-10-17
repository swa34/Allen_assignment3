#include <iostream>
#include <fstream>
#include<vector>

#include <sstream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
  DoublyLinkedList<int> intList;
  DoublyLinkedList<float> dbList;
  DoublyLinkedList<string> stringList;
  char input;
  vector<int> arr;
  cout << "Enter list type (i - int, f - float, s - std::string):";
  cin >> input;
  cout << "Test line " << input << endl;
  if (input == 'i') {
	ifstream fs;
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
		case 'b': {
		  int lb=0;
		  int ub=0;
		  cout << "Enter lower bound: ";
		  cin >> lb;
		  cout << "Enter upper bound: ";
		  cin >> ub;
		  cout << "Original List: ";
		  intList.print();
		  cout << "\nModified List: ";
		  intList.deleteSubsection(lb,ub);
		  intList.print();
		  break;
		}
		case 'd': {
		  string str;
		  string s;
		  int x;
		  cout << "Number to delete: ";
		  cin.ignore();
		  getline(cin, str);
		  istringstream iss(str);
		  while (iss >> x) {
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
		  break;
		}
		case 'l': {

		  cout << "The length is: " << intList.lengthIs() << endl;

		  break;
		}
		case 'm': {
		  intList.print();
		  cout << "\nMode: " << intList.mode();
		  break;
		}

		case 's': {
		  cout << "Original List: ";
		  intList.print();
		  cout << "\nSwapped List: ";
		  intList.swapAlternate();
		  intList.print();
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
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\float-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	float n;
	while (fs >> n) {
	  //arr.push_back(n);
	  dbList.insertItem(n);
	}
	//dbList.print();
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
		  float num;
		  cout << "Item to insert: ";
		  cin >> num;
		  cout << num << endl;
		  dbList.insertItem(num);
		  cout << endl;
		  dbList.print();

		  // cout << endl;

		  break;
		}
		case 'd': {
		  string str;
		  string s;
		  float x;
		  cout << "Number to delete: ";
		  cin.ignore();
		  getline(cin, str);
		  istringstream iss(str);
		  while (iss >> x) {
			dbList.deleteItem(x);

		  }
		  dbList.print();

		  break;
		}
		case 'p': {
		  dbList.print();
		  break;
		}
		case 'r': {
		  dbList.printReverse();
		  break;
		}
		case 'm': {
		  dbList.print();
		  cout << "\nMode: " << dbList.mode();
		  break;
		}
		case 's': {
		  cout << "Original List: ";
		  dbList.print();
		  cout << "\nSwapped List: ";
		  dbList.swapAlternate();
		  dbList.print();
		  break;
		}
		case 'l': {

		  cout << "The length is: " << dbList.lengthIs() << endl;

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
///*START of STRING *********/
  } else if (input == 's') {
	ifstream fs;
	fs.open(R"(C:\Users\scott\CLionProjects\Allen_assignment3\string-input)", fstream::in); // reads input file
	//fs.open(argv[1], fstream::in); // reads input file
	string str;
	while (getline(fs, str)) {
	  //arr.push_back(n);
	  stringList.insertItem(str);
	}
	//stringList.print();
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
		  string num;
		  cout << "Item to insert: ";
		  cin.ignore();
		  getline(cin, num);
		 // stringList.insertItem(num);
		   stringList.sorting(num);
		  cout << endl;
		  stringList.print();

		  cout << endl;

		  break;
		}
		case 'd': {
		  string str;
		  float x;
		  cout << "Number to delete: ";
		  cin.ignore();
		  getline(cin, str);
		  istringstream iss(str);
		  while (iss >> x) {
			dbList.deleteItem(x);

		  }
		  dbList.print();

		  break;
		}
		case 'p': {
		  stringList.print();
		  break;
		}
		case 'r': {

		  stringList.printReverse();
		  break;
		}
		case 'm': {
		  stringList.print();
		  cout << "\nMode: " << stringList.mode();
		  break;
		}
		case 's': {
		  cout << "Original List: ";
		  stringList.print();
		  cout << "\nSwapped List: ";
		  stringList.swapAlternate();
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

  } else {
	cout << "Invalid entry";
  }
}




