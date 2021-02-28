#include<bits/stdc++.h>
using namespace std;
// Phep chap: P(n,k) = n(n-1)...(n-k+1)    k < n
//				     = 0					k > n
long long m = 1e9+7;
long long tinh(long long n,long long k)
{
	long long p = 1;
	for(long long i = n ; i >= n-k+1 ; i--)
		p = ((p%m)*(i%m))%m;
	return p;
}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cout<<tinh(n,k)<<endl;
	}
}
