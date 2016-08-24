#include <iostream>
using namespace std;

int main(){
	int *uninit; // int指针未初始化
	int *nullptr = NULL; // 初始化为NULL
	void *vptr; // void指针未初始化
	int val = 1;
	int *iptr;
	int *castptr;

	// void类型可以存储任意类型的指针或引用
	iptr = &val;
	vptr = iptr;
	cout<<"iptr= " <<iptr<<endl;
	cout<<"vptr= " <<vptr<<endl;

	// 通过显示转换，我们可以把一个void指针转成
	cout<<"vptr= " <<*(int *)vptr<<endl;


	// 打印null和未初始化指针
	//	cout<<"uninit= " <<*uninit<<endl;
	//	cout<<"nullptr= " <<*nullptr<<endl;
	// 不知道你会得到怎样的返回值，会是随机的垃圾地址吗？
	// printf("*nullptr=%d\n", nullptr);
	// 这里会产生一个段错误
	// printf("*nullptr=%d\n", nullptr);

//	int myarray[4] = {1,2,3,0};
//	int *ptr = myarray;
//	cout<<"*ptr= " <<*ptr<<endl;
//	cout<<"*ptr= " <<*(ptr+2)<<endl;

	// 数组变量是常量，不能做下面的赋值
	// myarray = ptr
	// myarray = myarray2
	// myarray = &myarray2[0]

	struct person {
		int age;
		char *name;
	};
	struct person first;
	struct person *ptr;

	first.age = 21;
	char *fullname="full name";
	first.name = fullname;
	ptr = &first;

	cout<<"age= " <<first.age<<endl;
	cout<<"age= " <<first.name<<endl;
	cout<<"name= " <<ptr->name<<endl;

	return 0;
}

