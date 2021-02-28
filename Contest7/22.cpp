#include<bits/stdc++.h>
using namespace std;

long long sr(long long a[],long long n,long long i)
{
	long long j = i+1;
	while(j < n && a[j] >= a[i]) j++;
	return j-i-1;
}

long long sl(long long a[],long long n,long long i)
{
	long long j = i-1;
	while(j >= 0 && a[j] >= a[i]) j--;
	return i-j-1;
}

long long process(long long a[],long long n)
{
	long long MAX = 0;
	for(long long i = 0 ; i < n ; i++)
		MAX = max(MAX,a[i]*(1 + sl(a,n,i) + sr(a,n,i)));
	return MAX;
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
		cout<<process(a,n)<<endl;
	}
}
