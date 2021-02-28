#include<iostream>
using namespace std;

void nhap(long long a[],long long k)
{
	for(long long i = 0 ; i < k ; i++)
		cin>>a[i];
}

void xuat(long long a[],long long k)
{
	for(long long i = 0 ; i < k ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void xuly(long long a[],long long n,long long k)
{
	long long i;
	for(i = k-1 ; i >= 0 ; i--)
		if(a[i] != n-k+i+1)
		{
			a[i] += 1;
			break;
		}
	if(i < 0) 
		for(long long j = 0 ; j < k ; j++)
			a[j] = j+1;
	else
		for(long long j = i+1 ; j < k ; j++)
			a[j] = a[i]+j-i;	
}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long a[k];
		nhap(a,k);
		xuly(a,n,k);
		xuat(a,k);
	}
}
