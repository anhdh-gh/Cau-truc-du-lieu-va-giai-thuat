#include<iostream>
#include<algorithm>
using namespace std;

long long stop;

void in(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i];
	cout<<" ";
}

void sinh(long long a[],long long n)
{
	stop = 0;
	long long i;
	for(i = n-1; i > 0 ; i--)
		if(a[i] < a[i-1])
		{
			stop = 1;
			break;
		}
	for(long long j = n-1 ; j >= i ; j--)
		if(a[j] < a[i-1]) 
		{
			swap(a[j],a[i-1]);
			break;
		}
	sort(a+i,a+n,greater<long long>());
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			a[i] = n-i;
		in(a,n);
		sinh(a,n);
		while(stop == 1)
		{
			in(a,n);
			sinh(a,n);
		}
		cout<<endl;
	}
}
