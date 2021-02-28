#include<bits/stdc++.h>
using namespace std;
long long n,x;

struct so{
	long long i; // vi tri
	long long a; // so thuc
	long long b; // abs(x - a)
};
// Neu ma gia tri bang nhau thi cai nao xuat hien truoc in truoc
bool cmp(so a1,so a2)
{
//	if(a1.b == a2.b) return a1.i < a2.i;
//	else return a1.b < a2.b;
	return a1.b < a2.b;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		so a[n];
		for(long long i = 0 ; i < n ; i++)
		{
			a[i].i = i;
			cin>>a[i].a;
			a[i].b = abs(x - a[i].a);
		}
		//sort(a,a+n,cmp);
		stable_sort(a,a+n,cmp);
		for(long long i = 0 ; i < n ; i++)
			cout<<a[i].a<<" ";
		cout<<endl;
	}
}
