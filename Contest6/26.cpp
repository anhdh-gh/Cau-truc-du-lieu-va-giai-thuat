#include<bits/stdc++.h>
using namespace std;

void in(long long a[],long long n,long long &dem)
{
	cout<<"Buoc "<<dem++<<": ";
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void interchange_sort(long long a[],long long n) // Sap xep do cho truc tiep
{
	long long dem = 1;
	for(long long i = 0 ; i < n-1 ; i++)
	{
		for(long long j = i+1 ; j < n ; j++)
			if(a[i] > a[j])
				swap(a[i],a[j]);
		in(a,n,dem);
	}
}

main()
{
	long long T,n;
	cin>>n;
	long long a[n];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	interchange_sort(a,n);
}
