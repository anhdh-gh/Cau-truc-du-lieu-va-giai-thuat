#include<bits/stdc++.h>
using namespace std;

// a[i] - a[j] < k
// a[j] > a[i]-k;
// sort
// Lap i tu n-1 down 1
// upper_bound return lai phan tu dau tien trong mang > a[i]-k
// Vi mang da sort => cac phan tu co vi tri >= upper_bound deu > a[i]-k && vi tri do phai < i
// So luong ptu = vi tri i - vi tri upper_bound(0,i,a[i]-k)
// dem += so luong ptu;

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long a[n],dem=0;
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		for(long long i = n-1 ; i >= 1 ; i--)
		{
			long long vt = (a+i) - upper_bound(a,a+i,a[i]-k);
			if(vt > 0) dem += vt;		
		}
		cout<<dem<<endl;
	}
}
