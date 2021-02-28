#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		for(long long i = n-1 ; i >= n-k ; i--)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
