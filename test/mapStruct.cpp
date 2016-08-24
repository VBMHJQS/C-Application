#include <iostream>
#include <string>
#include <map>


using namespace std;

// 用户标识
struct UserIden{
	string userId;
	string brokerName;
	string investorAccountId;

	bool operator <(const UserIden& ui) const
	{
		return userId < ui.userId;
	}
};


map<UserIden,int>* pmap = NULL;
int main(){
	UserIden ui1;
	UserIden ui2;
	UserIden ui3;

	ui1.userId = "1";
	ui1.brokerName = "深圳";
	ui1.investorAccountId = "123";

	ui2.userId = "2";
	ui2.brokerName ="广东";
	ui2.investorAccountId = "456";

	ui3.userId = "3";
	ui3.brokerName = "香港";
	ui3.investorAccountId = "789";


	cout << ui1.userId << endl;
	cout << ui1.brokerName << endl;
	cout << ui1.investorAccountId << endl;

	pmap = new map<UserIden,int>();

	(*pmap)[ui1]=110;
	(*pmap)[ui2]=112;
	(*pmap)[ui3]=119;
	cout<<"========================================="<<endl;
	map<UserIden, int>::iterator  faIter;
	for(faIter = pmap->begin(); faIter != pmap->end(); faIter++)
	{
		UserIden ui = faIter->first;
		cout << ui.userId << endl;
		cout << ui.brokerName << endl;
		cout << ui.investorAccountId << endl;
		cout <<"pid: " <<faIter->second<<endl;

	}
	cout<<"========================================="<<endl;

	map<UserIden, int>::iterator itor = pmap->find(ui2);
	if(itor == pmap->end()){
		cout<<"no"<<endl;

	}else{
		cout<<"find id: " <<itor->second<<endl;
	}

}
