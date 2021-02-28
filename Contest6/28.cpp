#include<bits/stdc++.h>
using namespace std;

void in(long long a[],long long n,long long &dem)
{
	cout<<"Buoc "<<dem++<<": ";
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void insertion_sort(long long a[],long long n) // Sap xep do chen
{
	long long dem = 0,x,j;
	for(long long i = 0 ; i < n ; i++)
	{
		x = a[i];
		for(j = i-1 ; j >= 0 ; j--)
			if(x < a[j]) a[j+1] = a[j]; // dich chuyen
			else break;
		a[j+1] = x; // Chen vao
		in(a,i+1,dem);
	}
}

main()
{
	long long T,n;
	cin>>n;
	long long a[n];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	insertion_sort(a,n);
}
