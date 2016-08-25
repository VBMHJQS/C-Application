#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Field{
	int count;
	string name;
	double price;
};

int main(){

	Field field;
	field.count = 10;
	field.name = "wangxc";
	field.price = 10.20;
	
	Field *pfield = &field;
	cout << pfield->count << " " << pfield->name << " " << pfield->price << " " << endl;

	Field fd2;
	memcpy(&fd2, pfield,sizeof(Field));
	cout << fd2.count << " " << fd2.name << " " << fd2.price << " " << endl;
	return 0;
}