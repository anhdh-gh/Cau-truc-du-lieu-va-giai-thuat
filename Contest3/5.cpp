#include<bits/stdc++.h>
using namespace std;

long long sum(long long i,long long a[],long long j)
{
	long long tong = 0;
	for(long long k = i; k < j ; k++)
		tong += a[k];
	return tong;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n,k,MAX;
		cin>>n>>k;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n,greater<long long>());
		MAX = max(k,n-k); // tham lam lay nhieu so lon nhat co the
		cout<<sum(0,a,MAX)-sum(MAX,a,n)<<endl;
	}
}
