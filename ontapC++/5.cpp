#include<iostream>
using namespace std;
int main()
{
	string a;
	{
		getline(cin,a);
		if((a[0]-48)+(a[4]-48) == (a[8]-48)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
