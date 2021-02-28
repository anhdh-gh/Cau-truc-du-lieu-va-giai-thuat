#include<iostream>
using namespace std;
void input(long long a[][100],long long &n,long long &m)
{
	cin>>n>>m;
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < m ; j++)
			cin>>a[i][j];
}

void output(long long b[][100],long long n,long long T)
{
	cout<<"Test "<<T<<":\n";
	for(long long i = 0 ; i < n ; i++)
	{
		for(long long j = 0 ; j < n ; j++)
			cout<<b[i][j]<<" ";	
		cout<<endl;	
	}
}

void xuly(long long a[][100],long long n,long long m,long long T)
{
	long long b[100][100];
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < n ; j++)
		{
			b[i][j] = 0;
			for(long long k = 0 ; k < m ; k++)
				b[i][j] += a[i][k]*a[j][k];				
		}
	output(b,n,T);
}

int main()
{
	long long T,n,m,a[100][100];
	cin>>T;
	for(long long i = 1 ; i <= T ; i++)
	{
		input(a,n,m);
		xuly(a,n,m,i);
	}
	return 0;
}
