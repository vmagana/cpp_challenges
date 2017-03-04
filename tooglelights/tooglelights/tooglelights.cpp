// tooglelights.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	ifstream lightsfile("lights.txt");
	//int *image = new int[1000][1000];
	//size_t size_row=end(grid) - begin(grid);
	//size_t size_col=end(grid[0]) - begin(grid[0]);
	size_t counter=0;
	size_t total=0;
	vector< vector<size_t> > grid;
	grid.resize(1000);
	for(int i=0;i<grid.size();i++) {
		grid[i].resize(1000);
	}
	
	for(int i=0;i<1000;i++) {
		for(int j=0;j<1000;j++) {
			grid[i][j]=0;
		}
	}

	//size_t start_x,start_y,end_x,end_y;
	string line="",light_action="",start_x="",start_y="",end_x="",end_y="";
	smatch wordmatch;
	regex turnon_regex(".*(turn on\\s+)([0-9]{1,3})(\,)([0-9]{1,3})(.*through\\s+)([0-9]{1,3})(\,)([0-9]{1,3}).*");
	regex turnoff_regex(".*(turn off\\s+)([0-9]{1,3})(\,)([0-9]{1,3})(.*through\\s+)([0-9]{1,3})(\,)([0-9]{1,3}).*");
	regex toggle_regex(".*(toggle\\s+)([0-9]{1,3})(\,)([0-9]{1,3})(.*through\\s+)([0-9]{1,3})(\,)([0-9]{1,3}).*");
	regex action_regex("(^\\w.*\\s+)([0-9]{1,3})(\,)([0-9]{1,3})(.*through\\s+)([0-9]{1,3})(\,)([0-9]{1,3}).*");

	//std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e );
	//std::regex_iterator<std::string::iterator> rend;

	//while (rit!=rend) {
	//	std::cout << rit->str() << std::endl;
	//	++rit;
	//}

	if ( lightsfile.is_open() ) {
		while (getline(lightsfile,line)) {
			if (regex_match(line,wordmatch,action_regex)) {
				
				//for (size_t i = 0; i < wordmatch.size(); ++i) {
				//	std::ssub_match sub_match = wordmatch[i];
				//	std::string piece = sub_match.str();
				//	std::cout << "  submatch " << i << ": " << piece << '\n';
				//}

				light_action=wordmatch[1];
				start_x=wordmatch[2];
				start_y=wordmatch[4];
				end_x=wordmatch[6];
				end_y=wordmatch[8];

				if(light_action == "turn on ") {
					for(int i=atoi(start_x.c_str());i<=atoi(end_x.c_str());i++) {
						for (int j=atoi(start_y.c_str());j<=atoi(end_y.c_str());j++) {
							//cout<<"Before"<<grid[i][j]<<endl;
							grid[i][j]++;
							//cout<<"After"<<grid[i][j]<<endl;
						}
					}
				} else if (light_action == "turn off ") {
					for(int i=atoi(start_x.c_str());i<=atoi(end_x.c_str());i++) {
						for (int j=atoi(start_y.c_str());j<=atoi(end_y.c_str());j++) {
							//cout<<"Before"<<grid[i][j]<<endl;
							if (grid[i][j] != 0) {
								grid[i][j]--;
							}
							//cout<<"After"<<grid[i][j]<<endl;
						}
					}
				} else if (light_action == "toggle ") {
					for(int i=atoi(start_x.c_str());i<=atoi(end_x.c_str());i++) {
						for (int j=atoi(start_y.c_str());j<=atoi(end_y.c_str());j++) {
							//if (grid[i][j] == 0 ? grid[i][j] = 1 : grid[i][j] = 0);
							//cout<<"Before"<<grid[i][j]<<endl;
							grid[i][j] = grid[i][j] +  2;
							//cout<<"After"<<grid[i][j]<<endl;
							//cout<<grid[i][j]<<endl;
						}
					}
				}
				
				
			}
		}
	}



				for(int i=0;i<1000;i++) {
					for (int j=0;j<1000;j++) {
						cout<<grid[i][j];
						if(grid[i][j] != 0) {
							counter++;
							total += grid[i][j];
						}
					}
				}
	
	
	
	
	cout<<"Counter: "<<counter<<endl;
	cout<<"Total: "<<total<<endl;
	
	return 0;
}

//542387 is too low
//543903

//Brightness level
//14190930  is too low

