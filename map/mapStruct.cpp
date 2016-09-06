#include <iostream>
#include <cstring>
#include <map>


using namespace std;

// 用户标识
struct UserIden{
	string userId;
	string brokerName;
	//string investorAccountId;

	bool operator <(const UserIden& ui) const
	{
		return (userId < ui.userId) || (userId == ui.userId && brokerName < ui.brokerName)|| (userId == ui.userId && brokerName == ui.brokerName);
	}
};


map<UserIden,int>* pmap = NULL;
int main(){
	UserIden ui1;
	//memset(ui1, 0, sizeof(ui1));
	UserIden ui2;
	UserIden ui3;
	UserIden ui4;

//	cout << ui.userId << endl;
//	cout << ui.brokerName << endl;
//	cout << ui.investorAccountId << endl;

		ui1.userId = "1";
		ui1.brokerName = "深圳";
		//ui1.investorAccountId = "123";

		ui2.userId = "2";
		ui2.brokerName ="广东";
		//ui2.investorAccountId = "456";

		ui3.userId = "3";
		ui3.brokerName = "123";
		//ui3.investorAccountId = "789";

		ui4.userId = "3";
		ui4.brokerName = "123";
		//ui4.investorAccountId = "790";
	//
	//
		pmap = new map<UserIden,int>();
	//
		(*pmap)[ui1]=110;
		(*pmap)[ui2]=112;
		(*pmap)[ui3]=119;
		(*pmap)[ui4]=120;
		cout<<"========================================="<<endl;
		map<UserIden, int>::iterator  faIter;
		for(faIter = pmap->begin(); faIter != pmap->end(); faIter++)
		{
			UserIden ui = faIter->first;
			cout << ui.userId << endl;
			cout << ui.brokerName << endl;
			//cout << ui.investorAccountId << endl;
			cout <<"pid: " <<faIter->second<<endl;

		}
		cout<<"========================================="<<endl;
	//	UserIden uiT;
	//	uiT.userId = "3";
	//	uiT.brokerName = "香港";
	//
	//	map<UserIden, int>::iterator itor = pmap->find(uiT);
	//	if(itor == pmap->end()){
	//		cout<<"no"<<endl;
	//
	//	}else{
	//		cout<<"find id: " <<itor->second<<endl;
	//	}

}
