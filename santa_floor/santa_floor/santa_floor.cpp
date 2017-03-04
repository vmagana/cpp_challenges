// santa_floor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream myfile("santa.txt");
	char chr;
	int up=0;
	int down=0;
	int floor=0;
	int position=0;
	bool firsttime=true;
	if (myfile.is_open() ) {
		while (myfile.get(chr)) {
			if (chr == '(' ) {
				floor++;
				up++;
				cout<<"Up to Floor: "<<floor<<endl;
			} else if (chr == ')' ) {
				floor--;
				down++;
				cout<<"Down to Floor: "<<floor<<endl;
			} else {
				cout<<"Something else"<<chr<<endl;
			}

			if (floor == -1 && firsttime) {
				position=up + down;
				cout<<"Position"<<up + down<<endl;
				firsttime=false;

			}
		}
		cout<<"Santa is on Floor: "<<floor<<endl;
		cout<<"Moved up:"<<up<<endl;
		cout<<"Moved down:"<<down<<endl;
		cout<<"Diff"<<up - down<<endl;
		cout<<"Position"<<position<<endl;

	}
		 
	
	return 0;
}

