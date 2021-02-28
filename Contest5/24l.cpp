#include<bits/stdc++.h>
using namespace std;
long long c[30][30];
void tinh()
{
	long long i,j;
	for(i = 0 ; i <= 25 ; i++) c[i][0] = 1;
	for(j = 0 ; j <= 25 ; j++) c[0][j] = 1;
	for(i = 1 ; i <= 25 ; i++)
		for(j = 1 ; j <= 25 ; j++)
			c[i][j] = c[i-1][j]+c[i][j-1]; // khong di chuyen cheo
}

main()
{
	long long T,n,m;
	cin>>T;
	tinh();
	while(T--)
	{
		cin>>n>>m;
		cout<<c[n][m]<<endl;
	}
}

