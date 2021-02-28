#include<bits/stdc++.h>
using namespace std;
long long a[505][505],c[505][505],n,m;
long long tinh()
{
	long long i,j,kq = 1;
	memset(c,0,sizeof(c));
	for(i = 1 ; i <= n ; i++) c[i][1] = a[i][1];
	for(i = 1 ; i <= m ; i++) c[1][i] = a[1][i];
	for(i = 2 ; i <= n ; i++)
		for(j = 2 ; j <= m ; j++)
		{
			if(a[i][j]==1)
				c[i][j] = min(c[i][j-1],min(c[i-1][j],c[i-1][j-1]))+1;
			else c[i][j] = 0;
			kq = max(kq,c[i][j]);			
		}
	return kq;
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
