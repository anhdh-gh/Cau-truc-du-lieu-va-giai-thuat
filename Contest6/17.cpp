#include<bits/stdc++.h>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

main()
{
	long long T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		long long a[n],b[m];
		nhap(a,n);
		nhap(b,m);
		sort(a,a+n);
		sort(b,b+m);
		cout<<a[n-1]*b[0]<<endl;
	}
}
