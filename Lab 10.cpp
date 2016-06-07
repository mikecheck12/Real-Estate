#include "Property.h"

using namespace std;

void printVector(vector<Property*> properties)
{
	for (int i = 0; i < properties.size(); i++)
	{
		properties[i]->toString();
	}
}

int main()
{
	vector<Property*> properties;

	string address;
	//string file;
	//cout << "Please enter filename: " << endl;
	//getline(cin, file);

	cout << "Please enter address: " << endl;
	getline(cin, address);

	Property *property_1 = new Property(address);
	properties.push_back(property_1);

	cout << properties.size() << endl;

	printVector(properties);


	system("pause");
	return 0;
}