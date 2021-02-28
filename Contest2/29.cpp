#include<iostream>
using namespace std;

long long gt(long long n)
{
	long long t = 1;
	for(long long i = 2 ; i <= n ; i++)
		t *= i;
	return t;
}

main()
{
	long long T,m,n;
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		long long a[m][n];
		for(long long i = 0 ; i < m ; i++)
			for(long long j = 0 ; j < n ; j++)
				cin>>a[i][j];
		cout<<gt(m+n-2)/(gt(m-1)*gt(m+n-2-m+1))<<endl;
	}
}
