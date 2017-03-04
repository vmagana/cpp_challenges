// giftboxes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


struct Gift {
	size_t len;
	size_t wid;
	size_t hgt;
	size_t surface;
	size_t extra;
	size_t total;
	size_t ribbon_total;
};



int _tmain(int argc, _TCHAR* argv[])
{
	vector<Gift> GList;
	string line;
	size_t fpos=0;
	size_t npos=0;
	size_t lpos=0;
	int index=0;
	Gift box={};
	cout<<"SIZE"<<box.ribbon_total<<endl;
	box.ribbon_total=0;
	int totalarea=0;
	ifstream gfile("gifts.txt");
	if ( gfile.is_open() )
	{
		while (getline(gfile, line))
		{
			cout<<line<<endl;
			fpos = line.find('x');
			box.len = atoi( line.substr(0,fpos).c_str() );
			cout<<box.len<<endl;
			npos = line.find('x',fpos + 1);
			box.wid = atoi( line.substr(fpos + 1,npos).c_str() );
			cout<<box.wid<<endl;
			lpos = line.find('x',npos + 1);
			box.hgt = atoi( line.substr(npos + 1,lpos).c_str() );
			cout<<box.hgt<<endl;

			size_t a=box.len * box.wid;
			size_t b=box.wid * box.hgt;
			size_t c=box.hgt * box.len;
			box.surface=2*a + 2*b + 2*c;
			cout<<"Box surface area"<<box.surface<<endl;

			size_t smallest_surface=0;
			if (a <= b && a <= c) {
				smallest_surface = a;
			} else if (b <= a && b <= c) {
				smallest_surface = b;
			} else {
				smallest_surface = c;
			}

			size_t ribbon=0;
			size_t boxvol=box.len*box.wid*box.hgt;
			if (box.len >= box.wid && box.len >= box.hgt) {
				ribbon=box.wid+box.wid+box.hgt+box.hgt+boxvol;
			} else if (box.wid >= box.len && box.wid >= box.hgt) {
				ribbon=box.len+box.len+box.hgt+box.hgt+boxvol;
			} else {
				ribbon=box.wid+box.wid+box.len+box.len+boxvol;
			}

			box.ribbon_total=box.ribbon_total + ribbon;
			
			cout<<"Smallest surface is"<<smallest_surface<<endl;

			box.extra=smallest_surface;
			box.total=box.surface + box.extra;
			cout<<"Total Paper needed"<<box.total<<endl;
			totalarea=totalarea + box.surface + smallest_surface;
			GList.push_back(box);

		}	
	}
	
	gfile.close();

	cout<<"TotalSize: "<<totalarea<<endl;
	cout<<"Ribbon Total: "<<box.ribbon_total<<endl;
	size_t total_paper=0;
	for (size_t index=0;index < GList.size();index++) {
		cout<<"Size"<<GList[index].total<<"Index"<<index<<endl;
		total_paper += GList[index].total;
	}

	cout<<"TOTAL: "<<total_paper<<endl;


	return 0;
}

