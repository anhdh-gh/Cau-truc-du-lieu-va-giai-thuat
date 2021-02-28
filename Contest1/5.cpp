#include<iostream>
using namespace std;

long long stop;

void in(long long a[],long long k)
{
	for(long long i = 0 ; i < k ; i++)
		cout<<a[i];
	cout<<" ";
}

void sinh(long long a[],long long n,long long k)
{
	stop = 0;
	long long i;
	for(i = k-1 ; i >= 0 ; i--)
		if(a[i] != n-k+i+1)
		{
			stop = 1;
			a[i] += 1;
			break;
		}
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
		for(long long i = 0 ; i < k ; i++)
			a[i] = i+1;
		in(a,k);
		sinh(a,n,k);
		while(stop == 1)
		{
			in(a,k);
			sinh(a,n,k);
		}
		cout<<endl;
	}
}
