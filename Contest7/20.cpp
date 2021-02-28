#include<bits/stdc++.h>
using namespace std;

long long tim(long long a[],long long n,long long i)
{
	for(long long j = i+1 ; j < n ; j++)
		if(a[j] > a[i])
			return a[j];
	return -1;
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
		for(long long i = 0 ; i < n ; i++)
			cout<<tim(a,n,i)<<" ";
		cout<<endl;
	}
}
