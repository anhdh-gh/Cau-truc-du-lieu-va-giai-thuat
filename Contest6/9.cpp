#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n,k,dem;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		//sort(a,a+n);
		dem = 0;
		for(long long i = 0 ; i < n-1 ; i++)
			for(long long j = i+1 ; j < n ; j++)
				if(a[i]+a[j]==k) dem++;
		cout<<dem<<endl;
	}
}
