#include <iostream>
#include <string>
using namespace std;

struct Men{
	int id;
	string name;
	double price;
};

int main(){
	Men men;
	//men.id =12;
	//men.name ="test";
	men.price =12.03;

	cout << "men.id: " << men.id << endl;
	string temp;
	cout << men.name.length() << endl;
	if(men.name.length()==0){
		temp = "0";
	}else{
		temp = men.name;
		cout<<"12312312"<<endl;
	}
	cout << "men.name: " << temp << endl;
	cout << "men.price: " << men.price << endl;
}
