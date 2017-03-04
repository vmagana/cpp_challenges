// toggle-bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define BIT_ON 0x01  // 0000 0001

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	
	size_t fMercedes=0x00;
	cout<<fMercedes<<endl;
	
	size_t state=0;
	
	for (size_t i=0;i<10;i++) {
	state ? state=0: state=1;
	//(condition) ? (if_true) : (if_false)
	cout<<"Loop"<<state<<endl;
	}
	return 0;
}
