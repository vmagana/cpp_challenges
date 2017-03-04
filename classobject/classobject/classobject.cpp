// classobject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//using namespace std;
#include "class.h"
#include "windows.h"

//Constructor
// without login, login routine must be done explicitly
VSphereAPI::VSphereAPI(bool debug_)
  : debug(debug_),
    dbg(debug_)
{

}


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	VSphereAPI* vSphereAPIobj;
	//VSphereAPI* vSphereAPIobj = new VSphereAPI(true);
	//bool bval = vSphereAPIobj->dbg;
	//cout<<"debug value: "<<bval<<endl;

	cout<<"BEFORE"<<endl;

	int i = 1;
	if (i == 0) {
	if (vSphereAPIobj) {
		printf("T IS NULL\n");
		exit(1);
	}
	}
	//printf("The value: %i = ",(t != NULL ? t : false) );
	
	return 0;
}

