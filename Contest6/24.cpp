#include<bits/stdc++.h>
using namespace std;

long long find_pivot(long long a[],long long n,long long low,long long high)
{
	if(high < low) return -1;
	if(high == low) return low;
	long long mid = (low+high)/2;
	if(mid > low && a[mid] < a[mid-1]) return mid-1;
	if(mid < high && a[mid] > a[mid+1]) return mid;
	// if a[low] >= a[mid] => pivot nam ben trai
	if(a[low] >= a[mid]) return find_pivot(a,n,low,mid-1);
	// Con lai => nam ben phai
	return find_pivot(a,n,mid+1,high);
}

long long binary_search(long long a[],long long n,long long low,long long high,long long x)
{
	long long l = low,h = high,m;
	while(l <= h)
	{
		m = (h+l)/2;
		if(x == a[m]) return m;
		else if(x < a[m]) {h = m-1;}
		else if(x > a[m]) {l = m+1;}	
	}
	return -1;
}

long long process(long long a[],long long n,long long x)
{
	long long p = find_pivot(a,n,0,n-1);
	if(p == -1) //Khong co pivot => mang da duoc sort
		return binary_search(a,n,0,n-1,x);
	return max(binary_search(a,n,0,p,x),binary_search(a,n,p+1,n-1,x));
}

main()
{
	long long T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		cout<<process(a,n,x)+1<<endl;
	}
}
//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
