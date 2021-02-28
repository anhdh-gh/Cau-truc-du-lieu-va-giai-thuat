#include<bits/stdc++.h>
using namespace std;

void in(long long a[],long long n,long long &dem)
{
	cout<<"Buoc "<<dem++<<": ";
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void bubble_sort(long long a[],long long n) // Sap xep do noibot
{
	long long dem = 1,ok;
	for(long long i = n-1 ; i >= 1 ; i--)
	{
		ok = 0;
		for(long long j = 0 ; j <= i-1 ; j++)
			if(a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
				ok = 1;
			}	
		if(ok == 0) return;
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
	bubble_sort(a,n);
}
