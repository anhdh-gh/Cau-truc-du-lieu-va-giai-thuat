#include<bits/stdc++.h>
using namespace std;
// Idea: Thuat toan selection sort => So lan hoan doi it nhat

long long swap(long long &a,long long &b,long long &dem)
{
	dem++;
	long long temp = a;
	a = b;
	b = temp;
}

long long process(long long a[],long long n)
{
	long long dem = 0,min_index;
	for(long long i = 0 ; i < n-1 ; i++)
	{
		min_index = i;
		for(long long j = i+1 ; j < n ; j++)
			if(a[j] < a[min_index])
				min_index = j;
		if(i != min_index) swap(a[i],a[min_index],dem);
	}
	return dem;
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
		cout<<process(a,n)<<endl;
	}
}
