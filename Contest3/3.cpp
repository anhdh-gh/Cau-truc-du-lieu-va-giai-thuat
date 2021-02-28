#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;
main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		long long sum = 0;
		for(long long i = 0 ; i < n ; i++)
			sum += a[i]*i;
		cout<<sum%m<<endl;
	}	
}
