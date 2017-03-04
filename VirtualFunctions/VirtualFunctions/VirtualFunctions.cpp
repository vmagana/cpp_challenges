// VirtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>  // I/O 
using std::cout;
using std::endl;

#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>


//Without Using namespace to avoid typing std::  all the time
//using std::cout;
//using std::endl;

//Using namespace std
//using namepsace std;
class Employee {
public:
  Employee(std::string theName, float thePayRate);

	std::string getName() const;
	float getPayRate() const;

	float pay(float hoursWorked) const;

protected:
	std::string name;
	float payRate;
};



Employee::Employee(std::string theName, float thePayRate)
{
  name = theName;
  payRate = thePayRate;
}

std::string Employee::getName() const
{
  return name;
}

float Employee::getPayRate() const
{
  return payRate;
}

float Employee::pay(float hoursWorked) const
{
  return hoursWorked * payRate;
}



std::string Employee::getName() const
{
  return name;
}

float Employee::getPayRate() const
{
  return payRate;
}

float Employee::pay(float hoursWorked) const
{
  return hoursWorked * payRate;
}

