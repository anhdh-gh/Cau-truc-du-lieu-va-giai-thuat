#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,a[100],k,np[100],chuaxet;

void xuat(vector<long long>c)
{
	chuaxet = 1;
	cout<<"[";
	for(long long i = 0 ; i < c.size()-1 ; i++)
		cout<<c[i]<<" ";
	cout<<c[c.size()-1]<<"] ";
}

void nhap()
{
	cin>>n>>k;
	for(long long i = 1 ; i <= n ; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
}

void kt()
{
	long long sum = 0;
	vector<long long>c;
	for(long long i = 1 ; i <= n ; i++)
		if(np[i] == 1)
		{
			sum += a[i];
			c.push_back(a[i]);
		}
	if(sum == k) xuat(c);
	c.clear();
}

void TRY(long long i)
{
	for(int j = 1 ; j >= 0 ; j--)
	{
		np[i] = j;
		if(i==n) kt();
		else TRY(i+1);
	}
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		chuaxet = 0;
		nhap();
		TRY(1);
		if(chuaxet == 0) cout<<-1;
		cout<<endl;
	}
}
