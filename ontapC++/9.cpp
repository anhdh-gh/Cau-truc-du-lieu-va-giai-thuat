#include<iostream>
using namespace std;

long long check_increase(string a)
{
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i] > a[i+1]) return 0;
	return 1;
}

long long check_reduction(string a)
{
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i] < a[i+1]) return 0;
	return 1;
}

int main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		if(check_increase(a) == 1 || check_reduction(a) == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
