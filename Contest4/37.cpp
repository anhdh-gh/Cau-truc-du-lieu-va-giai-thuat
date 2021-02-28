#include<bits/stdc++.h>
using namespace std;

long long bs(long long a[],long long n,long long x)
{
	for(long long i = n-1 ; i >= 0 ; i--)
		if(a[i] <= x) return i+1;
	return -1;
		
}	

main()
{
	long long T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		cout<<bs(a,n,x)<<endl;
	}
}
