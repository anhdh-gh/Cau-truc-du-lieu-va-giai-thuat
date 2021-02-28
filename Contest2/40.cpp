#include<iostream>
using namespace std;
long long C[100][100],x[100],n,Cmin = 999999,chuaxet[100] = {0},cost = 0,FOPT = 999999,g;

void nhap()
{
	cin>>n;
	for(long long i = 1 ; i <= n ; i++)
		for(long long j = 1 ; j <= n ; j++)
		{
			cin>>C[i][j];
			if(i != j && C[i][j] < Cmin) Cmin = C[i][j];
		}
}

void TRY(long long i)
{
	for(long long j = 2 ; j <= n ; j++)
		if(chuaxet[j] == 0)
		{
			x[i] = j;
			chuaxet[j] = 1;
			cost += C[x[i-1]][x[i]];
			g = cost + (n-i+1)*Cmin;
			if(i == n && (cost + C[x[i]][x[1]]) < FOPT) 
				FOPT = cost + C[x[i]][x[1]];
			else if(g < FOPT) TRY(i+1);
			chuaxet[j] = 0;
			cost -= C[x[i-1]][x[i]];
		}
}

main()
{
	x[1] = 1;
	nhap();
	TRY(2);
	cout<<FOPT;
}
