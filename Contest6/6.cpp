#include<bits/stdc++.h>
using namespace std;

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
		sort(a,a+n);
		for(long long i = 0 ; i < n ; i++)
			cout<<a[i]<<" ";
		cout<<endl;		
	}
}
