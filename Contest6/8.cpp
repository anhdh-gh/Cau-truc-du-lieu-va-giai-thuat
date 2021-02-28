#include<bits/stdc++.h>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

// Dem so luong so 0,1,2,3,4 trong Y

long long demx(long long y[],long long m,long long x)
{
	long long d = 0;
	for(long long i = 0 ; i < m ; i++)
	{
		if(y[i] == x) d++;
		if(y[i] != x && d != 0) break;
	}	
	return d;
}

long long count(long long xi,long long y[],long long m,long long demy[])
{
	// x=0 => pair: 0 
	if(xi == 0) return 0;
	// x=1 => pair = So luong so 0 trong y[]
	if(xi == 1) return demy[0];
	// y > x => x^y > y^x => pair = vi tri n - vi tri phan tu dau tien > xi trong y
	long long ans = (y+m) - upper_bound(y,y+m,xi);
	// Truong hop ngoai le
	// xi > 1 => Moi y = 1 va y = 0 deo thoa man x^y > y^x
	ans += demy[0]+demy[1];
	// xi = 2, y = 3 or 4 Khong thoa man y > x => x^y > y^x
	if(xi==2) ans -= (demy[3]+demy[4]);
	// xi = 3, y = 2 thoa man x^y > y^x
	if(xi==3) ans += demy[2];
	return ans;
}

void process(long long x[],long long n,long long y[],long long m)
{
	sort(x,x+n);
	sort(y,y+m);	
	long long demy[5];
	for(long long i = 0 ; i <= 4 ; i++) demy[i] = demx(y,m,i);
	long long res = 0;
	for(long long i = 0 ; i < n ; i++)
		res += count(x[i],y,m,demy);
	cout<<res<<endl;
}

main()
{
	long long T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		long long x[n],y[m];
		nhap(x,n);
		nhap(y,m);
		process(x,n,y,m);
	}
}
//https://www.geeksforgeeks.org/find-number-pairs-xy-yx/
