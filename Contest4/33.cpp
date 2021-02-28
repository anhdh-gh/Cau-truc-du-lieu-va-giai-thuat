#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;

// Cah lam nay dung
//long long powm(long long n,long long k)
//{
//	if(k==0) return 1;
//	long long x = powm(n,k/2)%m;
//	if(k%2==0) return (x*x)%m;
//	return (((n%m)*x)%m*x)%m;
//}

// cach lam cua thay - sai
//long long powm(long long n,long long k)
//{
//	if(k==0) return 1;
//	long long x = powm(n,k/2);
//	if(k%2==0) return x*x%m;
//	return ((n*x)%m*x)%m;
//}

long long powm(long long n,long long k)
{
	if(k==0) return 1;
	long long x = powm(n,k/2);
	if(k%2==0) return (x%m*x%m)%m;
	return (n*(x%m*x%m)%m)%m;  // dang ra phai: ((n%m)*(x%m*x%m)%m)%m
}

long long dao(long long n)
{
	if(n==0) return 0;
	vector<long long>d;
	while(n!=0)
	{
		d.push_back(n%10);
		n /= 10;
	}
	long long res = 0,coso = 1;
	for(long long i = d.size()-1 ; i >= 0 ; i--)
	{
		res += coso*d[i];
		coso *= 10;
	}
	return res;
}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		k = dao(n);
		if(k==1) cout<<n<<endl;
		else cout<<powm(n,k)%m<<endl;
	}
}
