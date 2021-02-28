#include<bits/stdc++.h>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

void xuat(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void process(long long a[],long long n)
{
	vector<long long>b;
	b.insert(b.begin(),a,a+n);
	sort(a,a+n);
	for(long long i = 0 ; i < n ; i++)
		if(a[i] != b[i]) 
		{
			cout<<i+1<<" ";
			break;
		}		
	for(long long i = n-1 ; i >= 0 ; i--)
		if(a[i] != b[i]) 
		{
			cout<<i+1<<endl;
			return;
		}
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		nhap(a,n);
		process(a,n);
	}
}
