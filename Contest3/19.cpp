#include<bits/stdc++.h>
using namespace std;

long long ucln(long long a,long long b)
{
	if(a%b==0) return b;
	else return ucln(b,a%b);
}

void tru(long long &x,long long &y,long long mau)
{
	// quy dong
	long long tu = y;
	x *= mau;
	y *= mau;
	mau *= y;
	// tru
	x -= tu;
	//rut gon
	long long u = ucln(x,y);
	x /= u;
	y /= u;
}

void xuly(long long x,long long y)
{
	if(y == 0 || x == 0){return;}
	if(y%x==0) {cout<<"1/"<<y/x<<endl;return;}
	while(y%x!=0)
	{
		long long mau = y/x+1; //+1 lam tron
		cout<<"1/"<<mau<<" + ";
		tru(x,y,mau);
	}
	cout<<"1/"<<y;
	cout<<endl;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long x,y;
		cin>>x>>y;
		xuly(x,y);
	}
}
//We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction, then recur for the remaining part. For example, consider 6/14, we first find ceiling of 14/6, i.e., 3. So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42.
