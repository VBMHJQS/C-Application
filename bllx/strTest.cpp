#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1 = "hellow";
	string str2 = "World_test";
	string str3;
	string str4 = "";

	int len;

	str3 = str1;

	cout << "str3 : " << str3 << endl;

	str3 = str1 + str2;
	cout << "str1 + str2:" << str3 << endl;

	len = str3.size();
	cout << "str3.size(): " << len << endl;

	if(str4!=""){
		cout << "str4 is not null"  << endl;
	}else{
		cout << "str4 is null"  << endl;
	}

	string::size_type idx = str2.find("test");
	if ( idx != string::npos ){
		cout << "字符串含有“" << "test" << "”。\n";
	}else{
		cout << "字符串没有“" << "test" << "”。\n";
	}

	return 0;
}
