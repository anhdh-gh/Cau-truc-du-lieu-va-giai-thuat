#include<bits/stdc++.h>
using namespace std;

long long binary_search(long long a[],long long n,long long x)
{
	sort(a,a+n);
	long long l = 0,h = n-1,m;
	while(l <= h)
	{
		m = (h+l)/2;
		if(x == a[m]) return 1;
		else if(x < a[m]) {h = m-1;}
		else if(x > a[m]) {l = m+1;}	
	}
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
		cout<<binary_search(a,n,x)<<endl;
	}
}
