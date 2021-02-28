#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		long long a[m+n];
		for(long long i = 0 ; i < m+n ; i++)
			cin>>a[i];
		sort(a,a+m+n);
		for(long long i = 0 ; i < m+n ; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
