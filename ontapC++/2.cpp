#include<iostream>
using namespace std;
int main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		if(a[0] == a[a.size()-1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
