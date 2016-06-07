#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Property
{
private:
	string address;
	double value;
	bool rental;

public:
	//Constructor
	Property();
	//Property(bool r, double val, string location);
	Property(string location);


	//Returns property information
	string toString();
};
