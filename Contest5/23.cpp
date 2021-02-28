#include<bits/stdc++.h>
using namespace std;
// Idea: Lay n - day con tang dai nhat (Tinh ca gia tri bang nhau)  // Khi gia tri bang nhau thi khong can sap xep
long long timmax(long long t[],long long n)
{
	sort(t,t+n);
	return t[n-1];
}

long long qhd(long long a[],long long n)
{
	long long L[1005]={0}; // Do dai tot nhat tai thoi diem i
	L[0] = 1; // Do dai tot nhat cua mang co 1 so la 1 = > So dau tien la 1
	for(long long i = 1 ; i < n ; i++)
	{
		long long temp[1005]={0},tr = 0;		
		for(long long j = 0 ; j < i ; j++)	// tim kiem tu 0 -> i
			if(a[j] <= a[i]) // Neu gap 1 phan tu a[j] <= a[i]
				temp[tr++] = L[j]; // Luu do dai tot nhat cua a[j];
		L[i] = timmax(temp,tr)+1;	// +1 la tinh ca a[i]
	}
	return timmax(L,n);
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n,a[1005];
		cin>>n;
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		cout<<n - qhd(a,n)<<endl;		
	}
}
