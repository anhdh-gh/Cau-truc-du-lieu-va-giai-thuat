#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;

struct Matran{
	long long a[2][2];
	Matran()
	{
		a[0][0] = 0;
		a[0][1] = 1;
		a[1][0] = 1;
		a[1][1] = 1;
	}
};

Matran operator*(Matran x,Matran y)
{
	Matran res;
	for(long long i = 0 ; i < 2 ; i++)
		for(long long j = 0 ; j < 2 ; j++)
		{
			res.a[i][j] = 0;
			for(long long k = 0 ; k < 2 ; k++)
				res.a[i][j] = res.a[i][j]%m+((x.a[i][k]%m*y.a[k][j]%m)%m)%m;
		}
	return res;
}

Matran powMatran(Matran x,long long n)
{
	if(n==1) return x;
	Matran temp = powMatran(x,n/2);
	if(n%2==0) return temp*temp;
	return temp*temp*x;
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		Matran f;
		f = powMatran(f,n);
		cout<<f.a[0][1]%m<<endl;
	}
}
//https://kienthuc24h.com/ung-dung-nhan-ma-tran-vao-tinh-fibonacci-lon/

//	|0 1|^n * |fb(0) = 0 |   = | fb(n)  |
//    |1 1|	  |fb(1) = 1 |	   | fb(n+1)|
//    
//or just need
//	|0 1|^n = |fb(n-1) fb(n)  |
//	|1 1|  	  |fb(n)   fb(n+1)|
//example
//n = 6
//
//A^6 = |5  8|
//	  |8 13|
//=> fb(n) = A[0][1];

