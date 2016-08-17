#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int main(){

	// 字符串转换整形
	istringstream stream1;
	string string1 = "25";
	stream1.str(string1);
	int i;
	stream1 >> i;
	cout << i << endl;  // displays 25
	return 0;
}
