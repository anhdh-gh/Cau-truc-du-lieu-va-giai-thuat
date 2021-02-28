#include<iostream>
#include<vector>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

void xuat(long long a[],long long n,long long b[],long long m,long long p,long long T)
{
	vector<long long>c;
	for(long long i = 0 ; i < p ; i++)
		c.push_back(a[i]);
	for(long long i = 0 ; i < m ; i++)
		c.push_back(b[i]);
	for(long long i = p ; i < n ; i++)
		c.push_back(a[i]);
	cout<<"Test "<<T<<":\n";
	for(long long i = 0 ; i < c.size() ; i++)
		cout<<c[i]<<" ";
	cout<<endl;	
}

int main()
{
	long long T,a[100],b[100],n,m,p;
	cin>>T;
	for(long long i = 1 ; i <= T ; i++)
	{
		cin>>n>>m>>p;
		nhap(a,n);
		nhap(b,m);
		xuat(a,n,b,m,p,i);
	}
	return 0;
}
