#include<bits/stdc++.h>
using namespace std;

void in(long long a[],long long n,long long &dem)
{
	cout<<"Buoc "<<dem++<<": ";
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void selection_sort(long long a[],long long n) // Sap xep do chon
{
	long long dem = 1,min_idx;
	for(long long i = 0 ; i < n-1 ; i++)
	{
		min_idx = i;
		for(long long j = i+1 ; j < n ; j++)
			if(a[j] < a[min_idx]) min_idx = j;
		swap(a[i],a[min_idx]);
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
	selection_sort(a,n);
}
