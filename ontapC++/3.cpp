#include<iostream>
using namespace std;

long long check(long long a[],long long n)
{
	for(long long i = 0 ; i <= n/2 ; i++)
		if(a[i] != a[n-1-i]) return 0;
	return 1;
}

void nhap(long long a[],long long &n)
{
	cin>>n;
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

int main()
{
	long long T,n,a[100];
	cin>>T;
	while(T--)
	{
		nhap(a,n);
		if(check(a,n)==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
