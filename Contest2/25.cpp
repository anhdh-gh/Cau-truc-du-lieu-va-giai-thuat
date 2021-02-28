#include<iostream>
#include<algorithm>
using namespace std;

long long n,a[1000],ok;

void check(long long i,long long sum,long long s)
{
	s += a[i];
	if(s > sum) return;
	if(s == sum) ok = 1;
	else 
		for(long long j = i+1 ; j <= n ; j++)
			if(s < sum && ok == 0) check(j,sum,s);
}

long long xuly(long long sum)
{
	for(long long i = 0 ; i <= n ; i++)
	{
		long long s = 0;
		ok = 0;
		check(i,sum,s);	
		if(ok == 1) return 1;
	}	
	return 0;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long sum = 0;
		for(long long i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		if(sum%2!=0) cout<<"NO";
		else
		{
			if(xuly(sum/2) == 1) cout<<"YES";
			else cout<<"NO";
		}
		cout<<endl; 
	}
}
