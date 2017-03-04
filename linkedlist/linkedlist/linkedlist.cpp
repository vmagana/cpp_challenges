// linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
 	list<int> L;
	list<string> Lstr;
	Lstr.push_front("First");
	Lstr.push_front("Second");
	Lstr.push_front("Third");
	Lstr.assign(
	L.push_back(0);              // Insert a new element at the end
	L.push_front(0);             // Insert a new element at the beginning
	L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
	L.push_back(5);
	L.push_back(6);

	list<int>::iterator i;
	std::string hello="TEST";
	int test = 123;
	for(i=L.begin(); i != L.end(); ++i) 
	cout << *i << " " << endl;
	cout << "NUMBER: " << test << endl;
	cout << "STRING: " << hello << endl; 
	
	

	return 0;
}

                