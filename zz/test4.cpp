#include <iostream>
using namespace std;

int main(){
	int a = 4;
	int *za;
	za = &a;
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "za: " << za << endl;
	cout << "*za: " << *za << endl;
	cout << "&za: " << &za << endl;
	cout << "*(&za): " << *(&za) << endl;
	cout << "**(&za): " << **(&za) << endl;

//	a = 5;
//	cout<<"a=5重新赋值后的变化" << endl;
//
//	cout << "a: " << a << endl;
//	cout << "&a: " << &a << endl;
//	cout << "za: " << za << endl;
//	cout << "*za: " << *za << endl;
//	cout << "&za: " << &za << endl;
//	cout << "*(&za): " << *(&za) << endl;
//	cout << "**(&za): " << **(&za) << endl;
//	// 地址没有变，值改变


	int b = 10;
	int *zb;
	zb = &b;
	za = &b;
	cout <<"指针重新赋值后的变化"<<endl;

	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "za: " << za << endl;
	cout << "*za: " << *za << endl;
	cout << "&za: " << &za << endl;
	cout << "*(&za): " << *(&za) << endl;
	cout << "**(&za): " << **(&za) << endl;


}
