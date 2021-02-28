#include<bits/stdc++.h>
using namespace std;
long long solve(long long n,long long s,long long m)
{
	if(7*m > 6*n) return -1;
	long long sn = (s*m)/n;
	long long du = (s*m)%n;
	if(du > 0) sn++;
	return sn;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n,s,m;
		cin>>n>>s>>m;
		cout<<solve(n,s,m)<<endl;
	}
}
