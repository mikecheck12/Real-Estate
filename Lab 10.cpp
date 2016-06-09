#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

//PRINT PROPERTIES FUNCTION
void printVector(vector<Property*> properties)
{
	for (int i = 0; i < properties.size(); i++)
	{
		properties[i]->toString();
	}
}

/*
//LOAD FILE FUNCTION
void loadFile(string fileName, vector<Property*> properties)
{
	string propertyType;
	bool rental;
	double value;
	bool occupied;
	string address;
	bool discount;
	double disRate;

	ifstream fin;
	fin.open(fileName);

	while(!fin.eof())
	{
		fin >> propertyType;

		if (propertyType == "Residential")
		{
			fin >> rental;
			fin >> value;
			fin >> occupied;
			fin >> address;

			Property *property_1 = new Residential(occupied, rental, value, address);
			properties.push_back(property_1);
		}
		else if (propertyType == "Commercial")
		{
			fin >> rental;
			fin >> value;
			fin >> discount;
			fin >> disRate;
			fin >> address;

			Property *property_1 = new Commercial(discount, disRate, rental, value, address);
			properties.push_back(property_1);
		}
	}
}*/

//LOAD FILE FUNCTION
void loadFile(string fileName, vector<Property*>& properties)
{
	string line;

	//File variables
	string type;
	bool rental;
	double value;
	bool occupied;
	string address;
	bool discount;
	double disRate;

	ifstream fin;
	fin.open(fileName);

	/*if (fin.is_open())
	{
		cout << "Open" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}*/

	while (getline(fin, line))
	{		
		stringstream ss;
		string invalidLine = ss.str();
		ss.clear();
		ss << line;

		ss >> type;
		if (type == "Residential")
		{
			ss >> rental;
			if (rental != 1 && rental != 0)
			{
				cout << "Unknown property type ignored" << endl;
				cout << invalidLine;				
			}
			else {
				ss >> value;
				if (value < 0)
				{
					cout << "Unknown property type ignored" << endl;
					cout << invalidLine;
				}
				else {
					ss >> occupied;
					if (occupied != 1 && occupied != 0)
					{
						cout << "Unknown property type ignored" << endl;
						cout << invalidLine;
					}
					else{
						getline(ss, address);

						Property *property_1 = new Residential(occupied, rental, value, address);
						properties.push_back(property_1);
					}
				}
			}
		}

		else if (type == "Commercial")
		{
			ss >> rental;
			if (rental != 1 && rental != 0)
			{
				cout << "Unknown property type ignored" << endl;
				cout << invalidLine;
			}
			else {
				ss >> value;
				if (value < 0)
				{
					cout << "Unknown property type ignored" << endl;
					cout << invalidLine;
				}
				else {
					ss >> discount;
					if (discount != 1 && discount != 0)
					{
						cout << "Unknown property type ignored" << endl;
						cout << invalidLine;
					}
					else {
						ss >> disRate;
						if (disRate > 1 || disRate < 0)
						{
							cout << "Unknown property type ignored" << endl;
							cout << invalidLine;
						}
						else {
							getline(ss, address);

							Property *property_1 = new Commercial(discount, disRate, rental, value, address);
							properties.push_back(property_1);
						}
					}
				}
			}
		}
		else
		{
			cout << "Unknown property type ignored" << endl;
			cout << invalidLine;
		}
	}
}

int main()
{
	vector<Property*> properties;

	string fileName;

	cout << "Please enter filename: " << endl;
	getline(cin, fileName);

	loadFile(fileName, properties);

	cerr << "left function" << endl;
	cerr << properties.size() << endl;

	printVector(properties);


	system("pause");
	return 0;
}