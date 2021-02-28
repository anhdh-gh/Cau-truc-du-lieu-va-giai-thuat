#include<iostream>
using namespace std;
long long n,m,a[100][100];
void nhap()
{
	long long x,y;
	cin>>n>>m;
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < n ; j++)
			a[i][j] = 0;
	for(long long i = 0 ; i < m ; i++)
	{
		cin>>x>>y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
}

void TRY(long long i,long long dem,long long &max)
{
	for(long long j = 0 ; j < n ; j++)  // chay dinh
		if(a[i][j] == 1)
		{
			dem++;
			a[i][j] = 0;		// loai bo canh
			a[j][i] = 0;
			if(dem > max) max = dem;
			TRY(j,dem,max);
			// quay lui
			dem--;
			a[i][j] = 1;		
			a[j][i] = 1;
		}
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		nhap();
		long long dem = 0,max = 0;
		for(long long i = 0 ; i < n ; i++) // chay dinh
			TRY(i,dem,max);
		cout<<max<<endl;		
	}
}
