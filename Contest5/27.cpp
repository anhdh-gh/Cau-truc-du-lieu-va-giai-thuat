#include<bits/stdc++.h>
using namespace std;
long long F[1005][1005];
//F[i][j]: La gia tri lon nhat bang cach chon cac do vat 1,2,3,...,i voi gioi han trong luong la j
long long n;// So luong do vat
long long v;// Trong luong cai tui
long long a[1005];// Moi do vat co trong luong la a[i]
long long c[1005];// Moi do vat co gia tri la c[i]

void init()
{
	cin>>n>>v;
	for(long long i = 1 ; i <= n ; i++)
		cin>>a[i];
	for(long long i = 1 ; i <= n ; i++)
		cin>>c[i];
	for(long long i = 0 ; i <= v ; i++)
		F[0][i] = 0;// Gia tri max khi chon 0 do vat voi gioi han trong luong la i
}

long long process()
{
	init();
	for(long long i = 1 ; i <= n ; i++)	
		for(long long j = 0 ; j <= v ; j++)
		{
			F[i][j] = F[i-1][j]; // Truong hop khong chon duoc do vat thu i vs limit trong luong la j
			if(j >= a[i] && F[i][j] < F[i-1][j-a[i]]+c[i]) // Truong hop neu chon duoc do vat thu i vs limit trong luong la j. => Gia tri max F[i][j] = Gia tri cua i-1 do vat voi trong luong la j- a[i] + gia tri c[i]
				F[i][j] = F[i-1][j-a[i]]+c[i];
		}
//	for(long long i = 0 ; i <= n ; i++)
//	{
//		for(long long j = 0 ; j <= v ; j++)
//			cout<<F[i][j]<<" ";
//		cout<<endl;
//	}
	return F[n][v];//Gia tri max khi chon cac do vat 1,2,...,n voi gioi han trong luong la v
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cout<<process()<<endl;	
	}
}
