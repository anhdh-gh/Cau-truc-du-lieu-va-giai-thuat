#include<bits/stdc++.h>
using namespace std;

// Tim vi tri dat phan tu vach ngan
// Chia ra lam hai mang left <= p < right
long long Partition(long long a[],long long n,long long low,long long high)
{
	long long p = a[high]; // Lay phan tu cuoi lam vach ngan
	// Chia ra lam 2 array left <= p < right
	long long left[high-low+1],right[high-low+1],il=0,ir=0;
	for(long long i = low ; i <= high-1 ; i++)
		if(a[i] <= p) left[il++] = a[i];
		else right[ir++] = a[i];
	// Gan lai mang a
	for(long long i = 0 ; i < il ; i++)
		a[low++] = left[i];
	a[low++] = p; // Insert p vao vi tri vach ngan
	p = low-1; // Vi tri vach ngan
	for(long long i = 0 ; i < ir ; i++)
		a[low++] = right[i];	
	return p;
}

void Quick_sort(long long a[],long long n,long long low,long long high)
{
	if(low < high)
	{
		long long p = Partition(a,n,low,high);
		Quick_sort(a,n,low,p-1);
		Quick_sort(a,n,p+1,high);
	}
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
		Quick_sort(a,n,0,n-1);
		//sort(a,a+n);
		for(long long i = 0 ; i < n ; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
