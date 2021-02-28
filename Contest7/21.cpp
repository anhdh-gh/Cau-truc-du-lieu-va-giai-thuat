#include<bits/stdc++.h>
using namespace std;

long long Greater(long long a[],long long n,long long i)
{
	for(long long j = i+1 ; j < n ; j++)
		if(a[j] > a[i])
			return j;
	return -1;
}

long long Smaller(long long a[],long long n,long long i)
{
	if(i < 0) return -1;
	for(long long j = i+1 ; j < n ; j++)
		if(a[j] < a[i])
			return a[j];
	return -1;
}

void in(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void process(long long a[],long long n)
{
	long long Res[n],r=0;
	for(long long i = 0 ; i < n ; i++)
		Res[r++] = Smaller(a,n,Greater(a,n,i));
	in(Res,r);
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
			cin>>a[i];
		process(a,n);
	}
}
