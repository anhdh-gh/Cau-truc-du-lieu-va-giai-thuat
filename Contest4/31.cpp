#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7,n;
struct Matran{
	long long a[10][10];
	void nhap();
	void In();
};

void Matran::nhap()
{
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < n ; j++)
			cin>>a[i][j];
}

void Matran::In()
{
	for(long long i = 0 ; i < n ; i++)
	{
		for(long long j = 0 ; j < n ; j++)
			cout<<a[i][j]%m<<" ";
		cout<<endl;		
	}
}

Matran operator*(Matran x,Matran y)
{
	Matran res;
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < n ; j++)
		{
			res.a[i][j] = 0;
			for(long long k = 0 ; k < n ; k++)
				res.a[i][j] = res.a[i][j]%m+((x.a[i][k]%m*y.a[k][j]%m)%m)%m;
		}
	return res;
}

Matran powMatran(Matran x,long long k)
{
	if(k==1) return x;
	Matran temp = powMatran(x,k/2);
	if(k%2==0) return temp*temp;
	return temp*temp*x;
}

main()
{
	long long T,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		Matran A;
		A.nhap();
		A = powMatran(A,k);
		A.In();
	}
}
