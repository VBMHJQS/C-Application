#include "iconvpp.h"
#include <string>
#include <iostream>


using namespace std;


int main()
{
	// name="acceptdeptid" value="蜗家购物网" url="http://go.swojia.com"
	string acceptdeptid="蜗家购物网";
	cout<<acceptdeptid<<endl
	string out;
	iconvpp::converter conv("GB2312","UTF-8");
	conv.convert(acceptdeptid,out);

	cout<<out<<endl;
	return 0;
}
