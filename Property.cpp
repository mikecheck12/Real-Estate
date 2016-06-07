#include "Property.h"

using namespace std;

Property::Property() {}

Property::Property(string location)
{
	address = location;
}
/*
Property::Property(bool r, double val, string location)
{
	rental = r;
	value = val;
	address = location;
}*/

string Property::toString()
{
	stringstream ss;
	ss << "Address: " << address << endl;
	//ss << "Value: " << value << endl;
	//ss << "rental" << rental << endl;
	return ss.str();
}