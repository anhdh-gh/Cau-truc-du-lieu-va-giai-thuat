#include<iostream>
using namespace std;

long long stop;

void sinh(string &a,long long n)
{
	stop = 0;
	long long i;
	for(i = n-1 ; i >= 0 ; i--)
		if(a[i] == '0') 
		{
			stop = 1;
			a[i] = '1';
			break;
		}
		else a[i] = '0';	
}

long long kt(string a,long long n,long long k)
{
	long long count = 0;
	for(long long i = 0 ; i < n ; i++)
		if(a[i] == '1') count++;
	if(count == k) return 1;
	return 0;
}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		string a;
		for(long long i = 0 ; i < n ; i++)
			a.push_back('0');
		if(kt(a,n,k)==1) cout<<a<<endl;
		sinh(a,n);
		while(stop == 1)
		{
			if(kt(a,n,k)==1) cout<<a<<endl;
			sinh(a,n);
		}
	}
}
