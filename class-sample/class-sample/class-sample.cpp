// class-sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;


class Shape{
public:
	Shape(){cout<<"Shape..."<<endl;}
	Shape(const Shape& obj)
	{
		cout<<"Copy called"<<endl;
	}

	void* operator new(size_t size)
	{
		cout<<"new...."<<endl;
		void* storage=malloc(size);
		if(NULL == storage) {
			throw "allocation fail : no free memory";
		}
		return storage;
	}


	void operator delete (void*){

	}

};

int _tmain(int argc, _TCHAR* argv[])
{

	Shape obj;
	Shape obj2=obj;
	Shape obj3(obj);
	Shape* ptrShape=new Shape();
    Shape* ptrShapeOver= new Shape();
	
	std::vector<int> myvector;
	std::vector<int> twovector;
	std::vector<int> threvector;
	//myvector.push_back(3);
	//twovector.push_back(1);
	threvector.push_back(2);
	int sum (0);
	int all (0);
	int list_value (0);
	if (!myvector.empty() && !twovector.empty() && !threvector.empty()) {
		std::cout<<"Vector not empty"<<endl;
	}

	for (int i=1;i<=5;i++) {
		myvector.push_back(i);
	}

	while (!myvector.empty())
	{
		//std::cout<<"in vector loop"<<endl;
		//sum += myvector.back();
		all = myvector.front();
		std::cout<<all<<endl;
		myvector.erase(myvector.begin());
		//myvector.pop_back();
	}
	
	std::cout << "total: " << sum << '\n';

	//Use list vs vector
	// constructors used in the same order as described above:
	std::list<int> mylist; // empty list of ints
	for (int i=1;i<=10;i++) {
		mylist.push_back(i);
	}

	while (!mylist.empty()) {
	list_value = mylist.front();
	std::cout<<list_value<<endl;
	mylist.pop_front();
	}
	

	system("pause");
	return 0;
}

