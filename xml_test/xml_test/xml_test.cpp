// xml_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
	
using namespace std;

class Animal
{
private:
	std::string m_name;
	
protected:
    std::string m_strName;
	std::string m_tempName;
 
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    //Animal(std::string strName)
    //    : m_strName(strName)
    //{
    //}
 
public:
	Animal(std::string strName) 
		: m_strName(strName) {}
	
	virtual std::string GetSecond() { return m_tempName; }
    virtual std::string GetName() { return m_strName; }
	virtual void SetName(std::string name) {m_tempName = name;}
    //virtual const char* Speak() =0; //pure virtual function, makes this an abstract class
	virtual const char* Speak() { return "OOOOO"; }
	std::string got() { return m_tempName;}
	std::string get() { return m_strName;}
	std::string callin(std::string (Animal::*ptrfunc)()) {
		return (this->*ptrfunc)();
	}

	bool setstring(std::string & first, std::string & last, std::string & after) {
		first=GetName();
		last="2lastname";
		after="3after";
		
		return 0;
	}


};
 
class Cat: public Animal
{
public:
    Cat(std::string strName)
        : Animal(strName)
    {
    }
 
	virtual std::string GetName() { return m_strName; }
    virtual const char* Speak() { return "Meow"; }
};
 
class Dog: private Animal
{
public:
    Dog(std::string strName)
        : Animal(strName)
    {
    }
	

	//virtual std::string GetSecond() { return m_tempName; }
	virtual void SetName(std::string tname) {m_tempName=tname;}
	//virtual std::string GetName() { std::string value=GetSecond();return value; } 
	virtual const char* Speak() { return "Woof"; }
};


class Cow: public Animal
{
public:
    Cow(std::string strName)
        : Animal(strName)
    {
    }
 
    virtual const char* Speak() { return "Moo"; }
	virtual const char* Silent() { return "Quiet"; }
};
 
void go(Animal &);
int main()
{
	Animal animal("AnimalMine");
 	Cat cat("Kitten");
	cat.SetName("OUTSIDE");
	Animal *master=&cat;
	Animal &two=cat;
	Cow cow("Willma");
	Dog d("Alvin");
	d.SetName("Plays");
	
	std::string myfirst,mylast,myafter;
	bool res=animal.setstring(myfirst, mylast, myafter);
	cout<<myfirst<<" " <<mylast<<" "<<myafter<<endl;
	//std::string (Animal::*getptr)()=&Animal::get;
	//std::string name=master->callin(getptr);
	
	
	system("pause");
}



void go (Animal &rAnimal) {
	cout<<rAnimal.GetName() << " says " << rAnimal.Speak() << endl;
}


	
	
	
	
	

