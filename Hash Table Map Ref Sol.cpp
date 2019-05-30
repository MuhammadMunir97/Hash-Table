// Hash Table Map Ref Sol.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>


using namespace std;
string inputFileNameStr = "names.txt";
//define namePair using C++  pair template class (2 strings - first & last name)
typedef pair<string, string> namePair;
//prototype
void displayid(unsigned int id);
//define stl::hash function for namePair keys
namespace std {

    template <> class hash <namePair> {
    public:

        size_t operator() (const namePair &namePair) const {

            return hash<string>() (namePair.first) ^ hash<string>() (namePair.second);

        }//size_t operator()

    };//class hash

};//namespace std

void displayid(unsigned int id)
{
	if (id != 0)
	{
		cout << "The corresponding key pair exists with the key: " << id << endl;
	}
	else
	{
		cout << "The corresponding key pair does not exist" << endl;
	}
}

int main(int argc, char* argv[]) {

	ifstream          inputFileStreamObj;

	inputFileStreamObj.open(inputFileNameStr, ios::in);
	if (inputFileStreamObj.fail()) {
		cout << "File could not be opened !" << endl;
		return (EXIT_FAILURE);
	}
	
    //define hashTable as namepair keys and integer value identifications (inline)
    unordered_map<namePair, unsigned int> hashTable;

	string name, last;
	unsigned int id;
	while (inputFileStreamObj >> name >> last >> id)
	{
		hashTable[namePair(name, last)] = id;
	};
    //set in the hash table number ids for some namePair keys
    hashTable[namePair("Mark",   "Nelson")  ] = 40561;
    hashTable[namePair("Andrew", "Binstock")] = 40562;

	
    //look up ids using name keys in hash table
	cout << "Mark, " << "Nelson " << endl;
	displayid(hashTable[namePair("Mark", "Nelson")]);
	cout << "Andrew, " << "Binstock " << endl;
	displayid(hashTable[namePair("Andrew", "Binstock")]);
	cout << "Cristiano, " << "Ronaldo " << endl;
	displayid(hashTable[namePair("Cristiano", "Ronaldo")]);
	cout << "Lionel, " << "Messi " << endl;
	displayid(hashTable[namePair("Lionel", "Messi")]);
	cout << "Andrew, " << "Binstock " << endl;
	displayid(hashTable[namePair("Andrew", "Binstock")]);
	cout << "John, " << "Terry " << endl;
	displayid(hashTable[namePair("John", "Terry")]);
	cout << "James, " << "Rodriguez " << endl;
	displayid(hashTable[namePair("James", "Rodriguez")]);
	cout << "james, " << "david " << endl;
	displayid(hashTable[namePair("james", "david")]);
	cout << "And, " << "stock " << endl;
	displayid(hashTable[namePair("And", "stock")]);
	cout << "drew, " << "Biock " << endl;
	displayid(hashTable[namePair("drew", "Biock")]);
	
    for (pair<namePair, unsigned int> element : hashTable) {
        cout << setw(20) << left << element.first.first;
        cout << setw(20) << left << element.first.second;
        cout << setw(20) << left << element.second         << endl;
    }//for
    cout << endl << endl;

    return 0;

}

