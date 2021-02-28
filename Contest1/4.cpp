#include<iostream>
using namespace std;

long long stop;

void sinh(string &a,long long n)
{
	stop = 0;
	long long i;
	for(i = n-1 ; i >= 0 ; i--)
		if(a[i] == 'A') 
		{
			stop = 1;
			a[i] = 'B';
			break;
		}
		else a[i] = 'A';	
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		string a;
		for(long long i = 0 ; i < n ; i++)
			a.push_back('A');
		cout<<a<<" ";
		sinh(a,n);
		while(stop == 1)
		{
			cout<<a<<" ";
			sinh(a,n);
		}
		cout<<endl;
	}
}
