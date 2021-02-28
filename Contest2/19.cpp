#include<iostream>
using namespace std;

void in(long long a[],long long n)
{
	cout<<"[";
	for(long long i = 0 ; i < n ; i++)
	{
		if(i == n-1) cout<<a[i]<<"]\n";
		else cout<<a[i]<<" ";
	}
}

void sinh(long long a[],long long n)
{
	if(n == 1) return;
	for(long long i = 0 ; i < n-1; i++)
		a[i] += a[i+1];
	in(a,n-1);
	sinh(a,n-1);	
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		in(a,n);
		sinh(a,n);
	}
}
