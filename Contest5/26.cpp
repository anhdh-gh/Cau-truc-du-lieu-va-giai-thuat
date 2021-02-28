#include<bits/stdc++.h>
using namespace std;
long long c; // Trong luong max co the cho duoc
long long n; // So luong con bo
long long w[105]; // Trong luong moi con bo
long long F[105][25005]; // La gia tri max bang cach cho cac con bo 1,2,3,...,i voi gioi han trong luong la j

void init()
{
	cin>>c>>n;
	for(long long i = 1 ; i <= n ; i++)	
		cin>>w[i];
	for(long long i = 0 ; i <= n ; i++)
		F[0][i] = 0; // Trong luong toi da khi cho 0 con bo
}

long long process()
{
	for(long long i = 1 ; i <= n ; i++)
		for(long long j = 0 ; j <= c ; j++)
		{
			F[i][j] = F[i-1][j]; // Truong hop khong cho con bo thu i
			if(j >= w[i] && F[i][j] < F[i-1][j-w[i]]+w[i])
				F[i][j] = F[i-1][j-w[i]]+w[i];
		}
	return F[n][c];
}

main()
{
	init();
	cout<<process()<<endl;
}

