#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct UserIden{
	int userId;
	string brokerName;
	double investorAccountId;

	bool operator <(const UserIden& ui) const
	{
		return userId < ui.userId;
	}
};

int main()
{
    int a[20];
    memset(a, 0, sizeof(a));
    cout << "a[0] = " << a[0] << '\n';

    UserIden ui;
    memset(&ui, 0, sizeof(ui));
    cout << "userId = " << ui.userId << endl;
    cout << "investorAccountId = " << ui.investorAccountId << endl;
    cout << "brokerName = " << ui.brokerName << endl;
}
