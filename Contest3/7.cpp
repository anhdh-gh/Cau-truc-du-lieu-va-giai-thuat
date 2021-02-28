#include<bits/stdc++.h>
using namespace std;

long long tong(long long a[],long long b[],long long n)
{
	long long sum = 0;
	for(long long i = 0 ; i < n ; i++)
		sum += a[i]*b[i];
	return sum;
}	

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n],b[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		for(long long i = 0 ; i < n ; i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n,greater<long long>());
		cout<<tong(a,b,n)<<endl;		
	}
}
