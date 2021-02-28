#include<bits/stdc++.h>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

void xuat(vector<long long>a)
{
	for(long long i = 0 ; i < a.size() ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void process(long long a[],long long n,long long b[],long long m)
{
	vector<long long>h,g;
	h.insert(h.begin(),a,a+n);
	h.insert(h.end(),b,b+m);
	sort(h.begin(),h.end());
	for(long long i = 0 ; i < h.size()-1 ; i++)
		if(h[i]==h[i+1])
		{
			g.push_back(h[i]);
			h.erase(h.begin()+i--);
		}
	xuat(h);
	xuat(g);
}

main()
{
	long long T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		long long a[n],b[m];
		nhap(a,n);
		nhap(b,m);
		process(a,n,b,m);
	}
}
