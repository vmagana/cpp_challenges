// wire_signal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

using namespace std;

struct signal {
	string wirename;
	string wirevalue;
};

int _tmain(int argc, _TCHAR* argv[])
{
	signal signalstruct;
	vector<signal> collection;
	vector<string> output;
	map<string,string> signals;
	signal luces;
	string line;
	//regex filter_regex(".*(^[0-9]{1,}\\s+)(\\w*\\s+)(\\w*)(.*->\\s+)(\\w*).*");
	regex filter_regex(".*(^[0-9]{1,})(\\s+->\\s+)(\\w*).*");
	smatch wordmatch;
	ifstream wirefile("wire.txt");
	if(wirefile.is_open()) {
		while(getline(wirefile,line)) {
			if (regex_match(line,wordmatch,filter_regex)) {
				output.push_back(line);
			}
		}
	}
	
	sort(output.begin(),output.end());
	for (vector<string>::iterator i=output.begin();i != output.end();i++) {
		if (regex_match(*i,wordmatch,filter_regex)) {
				cout<<wordmatch.size()<<endl;
				cout<<wordmatch[1]<<endl;
				cout<<wordmatch[2]<<endl;
				cout<<wordmatch[3]<<endl;
				//cout<<wordmatch[4]<<endl;
				//cout<<wordmatch[5]<<endl;
				signals[wordmatch[3]]=wordmatch[1];
				
				//This is setting a structure and then adding it to a vector of that type of structure
				signalstruct.wirename=wordmatch[3];
				signalstruct.wirevalue=wordmatch[1];
				collection.push_back(signalstruct);
				cout<<*i<<endl;
			}
	}
	
	for(vector<signal>::iterator i = collection.begin();i!=collection.end();i++) {
		cout<<"Name"<<i->wirename<<"Value"<<i->wirevalue<<endl;
	}


	for(map<string,string>::iterator n = signals.begin() ;n != signals.end(); n++) {
		cout<<n->first<<n->second<<endl;
	}
		
	regex bfilter_regex(".*(^[a-z]\\s+).*");
	smatch bwordmatch;
	//ifstream bwirefile("wire.txt");
	if(wirefile.is_open()) {
		while(getline(wirefile,line)) {
			if (regex_match(line,bwordmatch,bfilter_regex)) {
				cout<<line<<endl;
				//output.push_back(line);
			}
		}
	}






	return 0;
}

