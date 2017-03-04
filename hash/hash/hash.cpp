// hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "md5.h"
#include <string>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char key[]="ckczppom";
	MD5 md5;
	size_t num=117946;
	char *hash_value;
	//cout<<hash_value<<endl;
	size_t still_zero=0;
	for (num;num<10000000;num++) {
		char digits[9];
		sprintf(digits, "%s%d", key,num);
		hash_value=md5.digestString( digits );
		cout<<hash_value<<endl;
		if(hash_value[0] == '0' && hash_value[1] == '0' && hash_value[2] == '0' && hash_value[3] == '0' && hash_value[4] == '0' && hash_value[5] == '0') {
			cout<<"Found Value: "<<hash_value<<endl;
			break;
		}
	}
	
	
	
	
	
	return 0;
}

