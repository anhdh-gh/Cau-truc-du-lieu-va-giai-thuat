#include<bits/stdc++.h>
using namespace std;

long long tim(long long a[],long long b[],long long n)
{
	for(long long i = 0 ; i < n-1 ; i++)
		if(a[i]!= b[i]) return i+1;
	return n;	
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n],b[n-1];
		for(long long i = 0 ; i < n ; i++){cin>>a[i];}
		for(long long i = 0 ; i < n-1 ; i++){cin>>b[i];}
		cout<<tim(a,b,n)<<endl;
	}
}
