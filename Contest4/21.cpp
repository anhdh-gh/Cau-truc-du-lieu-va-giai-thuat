#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;
long long powm(long long n,long long k)
{
	if(k==0) return 1;
	long long x = powm(n,k/2)%m;
	if(k%2==0) return (x*x)%m;
	return (((n%m)*x)%m*x)%m;
}

// cach lam cua thay - sai
//long long powm(long long n,long long k)
//{
//	if(k==0) return 1;
//	long long x = powm(n,k/2);
//	if(k%2==0) return x*x%m;
//	return ((n*x)%m*x)%m;
//}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cout<<powm(n,k)%m<<endl;
	}
}
