#include<bits/stdc++.h>
using namespace std;

// Ham mix
void Merge(long long a[],long long n,long long low,long long mid,long long high)
{
	// Chia ra lam hai mang
	long long left[mid-low+1],right[high-mid],il=0,ir=0;
	for(long long i = low ; i <= mid ; i++)
		left[il++] = a[i];
	for(long long i = mid+1 ; i <= high ; i++)
		right[ir++] = a[i];
	// Tron va gan lai vao mang a
	long long i = 0,j = 0;
	while(i < il && j < ir)
	{
		if(left[i] <= right[j])
			a[low++] = left[i++];
		else a[low++] = right[j++];
	}
	// Gan not cac phan tu 
	while(j < ir) a[low++] = right[j++];
	while(i < il) a[low++] = left[i++];
}

void Merge_sort(long long a[],long long n,long long low,long long high)
{
	if(low < high)
	{
		long long mid = (low+high)/2;
		Merge_sort(a,n,low,mid);
		Merge_sort(a,n,mid+1,high);
		Merge(a,n,low,mid,high);
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
		Merge_sort(a,n,0,n-1);
		//sort(a,a+n);
		for(long long i = 0 ; i < n ; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
