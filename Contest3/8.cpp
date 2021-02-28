#include<bits/stdc++.h>
using namespace std;

struct hd{
	long long s;
	long long f;
	
};

bool comp(hd x,hd y){return (x.f < y.f);}

main()
{
	long long T,n,dem,temp;
	cin>>T;
	while(T--)
	{
		cin>>n;
		hd a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i].s;
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i].f;
		sort(a,a+n,comp);
		dem = 1;
		temp = a[0].f;
		for(long long i = 1 ; i < n ; i++)
			if(a[i].s >= temp)
			{
				dem++;
				temp = a[i].f;
			}
		cout<<dem<<endl;
	}
}
