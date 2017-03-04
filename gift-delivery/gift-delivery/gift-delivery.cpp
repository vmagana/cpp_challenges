// gift-delivery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char move;
	size_t grid[200][200]={0};
	size_t start_row=100;
	size_t start_col=50;
	size_t santa_row=start_row;
	size_t santa_col=start_col;
	size_t robo_row=start_row;
	size_t robo_col=start_col;
	size_t size_row=end(grid) - begin(grid);
	size_t size_col=end(grid[0]) - begin(grid[0]);
	grid[start_row][start_col]=1;
	bool santa=0;
	/*
	for (size_t i=0;i<10;i++) {
	state ? state=0: state=1;
	//(condition) ? (if_true) : (if_false)
	cout<<"Loop"<<state<<endl;
	}
	*/

	ifstream gfile("delivery.txt");
	if (gfile.is_open()) {
		while(gfile.get(move)) {
			santa ? santa=0 : santa=1;
			if (move == '^') {
				if(santa) {
					santa_row=santa_row - 1;
					grid[santa_row][santa_col]=1;
				} else {
					robo_row=robo_row - 1;
					grid[robo_row][robo_col]=1;
				}
			} else if (move == 'v') {
				if(santa) {
					santa_row=santa_row + 1;
					grid[santa_row][santa_col]=1;
				} else {
					robo_row=robo_row + 1;
					grid[robo_row][robo_col]=1;
				}
			} else if (move == '>') {
				if(santa) {
					santa_col=santa_col + 1;
					grid[santa_row][santa_col]=1;
				} else {
					robo_col=robo_col + 1;
					grid[robo_row][robo_col]=1;
				}
			} else if (move == '<') {
				if(santa) {
					santa_col=santa_col - 1;
					grid[santa_row][santa_col]=1;
				} else {
					robo_col=robo_col - 1;
					grid[robo_row][robo_col]=1;
				}
			} else {
				cout<<"No move"<<endl;
			}
		}
	}

	size_t counter=0;
	for (size_t i=0;i<size_row;i++) {
		for (size_t j=0;j<size_col;j++) {
			if (j < size_col - 1) {
				cout<<grid[i][j];
			} else {
				cout<<grid[i][j]<<endl;
			}

			if (grid[i][j] == 1) {
				counter++;
			}
		}
	}
	
	cout<<"COUNT"<<counter<<endl;
	return 0;
}

