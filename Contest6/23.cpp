#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n+5]={0},i;
		for(i = 1 ; i <= n-1 ; i++)
		{
			cin>>x;
			a[x] = x;
		}
		for(i = 1 ; i <= n ; i++)
			if(a[i]==0) break;
		cout<<i<<endl;
	}
}
