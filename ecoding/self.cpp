#include <iconv.h>
#include <iostream>
#include <string.h>

using namespace std;
int main(){


	iconv_t cd = iconv_open("gb2312","utg-8");

	char text[]="hello 大家好";//待转文本
	const char *ins=text;//待转文本的指针，用于iconv参数兼容。
	char outtext[200];//申请200个字符串的输出空间
	char *outs=outtext;//空间的指针

	size_t il,ol=100;//待转文本长度和输出文本长度，字节数表示
	il=strlen(text);//得出待转文本长度，可能有问题，待测试

	cout<<"in=> "<<ins<<endl;
	iconv(cd,&ins, &il, &outs, &ol);//该函数递归执行，所有参数的内存都在外部，il,outs,ol的值都在函数执行输入后变化.
	//

	cout << "output=>"<<outtext <<" ol=>"<<ol<< endl;
	//由于outs指针已经指向未知领域，只有outtext指向的是原起始位置，输出转换后的正确值。

	iconv_close(cd);
	return 0;
}
