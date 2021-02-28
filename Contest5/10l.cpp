#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],c[1005][1005],n,m;
long long tinh()
{
	long long i,j;
	memset(c,0,sizeof(c));
	c[1][1] = a[1][1];
	for(i = 1 ; i <= n ; i++) c[i][1] = c[i-1][1]+a[i][1];
	for(i = 1 ; i <= m ; i++) c[1][i] = c[1][i-1]+a[1][i];
	for(i = 2 ; i <= n ; i++)
		for(j = 2 ; j <= m ; j++)
			c[i][j] = min(c[i][j-1],min(c[i-1][j],c[i-1][j-1]))+a[i][j];		
	return c[n][m];
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(long long i = 1 ; i <= n ; i++)
			for(long long j = 1 ; j <= m ; j++)
				cin>>a[i][j];
		cout<<tinh()<<endl;
	}
}
