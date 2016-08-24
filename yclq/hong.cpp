#include <iostream>
using namespace std;

void printFunction(){
	cout<<__FILE__<<": " <<__FUNCTION__<<endl;
}

int main ()
{
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    printFunction();
    return 0;
}
