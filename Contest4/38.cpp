#include<bits/stdc++.h>
using namespace std;
vector<long long>res;

main()
{
	long long T,m,n,k;
	cin>>T;
	while(T--)
	{
		cin>>m>>n>>k;
		long long a[m],b[n];
		for(long long i = 0 ; i < m ; i++){cin>>a[i];res.push_back(a[i]);}
		for(long long i = 0 ; i < n ; i++){cin>>b[i];res.push_back(b[i]);}
		sort(res.begin(),res.end());
		cout<<res[k-1]<<endl;
		res.clear();
	}
}
