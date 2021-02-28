#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long m = 123456789;
// cong thuc 2^(k-1)
long long powm(long long n,long long k)
{
	if(k==0) return 1;
	long long x = powm(n,k/2);
	if(k%2==0) return (x%m*x%m)%m;
	return ((n%m)*(x%m*x%m)%m)%m;
}

main()
{
	faster();
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<powm(2,n-1)<<endl;
	}
}
