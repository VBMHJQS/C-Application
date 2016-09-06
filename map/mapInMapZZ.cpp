#include <iostream>
#include <map>

using namespace std;

int main(){

	map<int,map<int,int> >*multiMap; //对于这样的map嵌套定义，
	map<int, int> temp;    //定义一个map<int, string>变量，对其定义后在插入multiMap
	temp[9] = 9;
	temp[10] = 10;

	multiMap = new map<int,map<int,int> >;

	(*multiMap)[10] = temp;
	(*multiMap)[10][11]=11;
	(*multiMap)[5][30]=30;
	map<int,map<int,int> >::iterator multitr;  // 以下是如何遍历本multiMap
	map<int,int>::iterator intertr;
	for(multitr=multiMap->begin();multitr!=multiMap->end();multitr++)
	{
		for(intertr= multitr ->second.begin(); intertr != multitr ->second.end(); intertr ++)
			cout<< multitr ->first<<" "<<intertr->first<<" ("<<intertr -> second <<")"<<endl;
	}

	map<int,map<int,int> >::iterator iter = multiMap->find(10);
	if(iter == multiMap->end()){
		cout<<"not found "<< endl;
	}else{
		map<int,int> tmp = iter->second;
		tmp[8] = 8;
		(*multiMap)[10] = tmp;
	}

	cout<<"添加后"<<endl;
	for(multitr=multiMap->begin();multitr!=multiMap->end();multitr++)
	{
		for(intertr= multitr ->second.begin(); intertr != multitr ->second.end(); intertr ++)
			cout<< multitr ->first<<" "<<intertr->first<<" ("<<intertr -> second <<")"<<endl;
	}
}
