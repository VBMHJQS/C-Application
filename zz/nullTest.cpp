#include <iostream>
using namespace std;

int main(){
int *ptr = NULL;
cout << "ptr 的值是 " << ptr;
//cout << "ptr 的值是 " << *ptr;
cout << endl;

if(ptr){
	cout<<"have"<<endl;
}else{
	cout<<"not have"<<endl;
}

return 0;
}
