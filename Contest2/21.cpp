#include<iostream>
#include<algorithm>
using namespace std;
string input;
void in(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cout<<input[a[i]-1];
	cout<<" ";
}

long long stop;
void sinh(long long a[],long long n)
{
	stop = 0;
	long long i;
	for(i = n-1; i > 0 ; i--)
		if(a[i] > a[i-1])
		{
			stop = 1;
			break;
		}
	for(long long j = n-1 ; j >= i ; j--)
		if(a[j] > a[i-1]) 
		{
			swap(a[j],a[i-1]);
			break;
		}
	sort(a+i,a+n);
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>input;
		n = input.size();
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			a[i] = i+1;
		in(a,n);
		sinh(a,n);
		while(stop == 1)
		{
			in(a,n);
			sinh(a,n);
		}
		cout<<endl;		
	}
}

