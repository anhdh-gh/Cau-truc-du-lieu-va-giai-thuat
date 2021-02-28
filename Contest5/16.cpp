#include<bits/stdc++.h>
using namespace std;

long long timmax(long long t[],long long n)
{
	sort(t,t+n);
	return t[n-1];
}

long long qhd(long long a[],long long n)
{
	long long S[1005]={0}; // Tong tot nhat tai thoi diem i
	S[0] = a[0]; // Tong tot nhat cua mang co 1 so la chinh so do = > So dau tien la a[0]
	for(long long i = 1 ; i < n ; i++)
	{
		long long temp[1005],tr = 0;		
		for(long long j = 0 ; j < i ; j++)	// tim kiem tu 0 -> i
			if(a[j] < a[i]) // Neu gap 1 phan tu a[j] < a[i]
				temp[tr++] = S[j]; // Luu tong tot nhat cua a[j];
		S[i] = a[i] + timmax(temp,tr);   // S[i] = a[i] + tong max trong temp 
	}
	return timmax(S,n);
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
		cout<<qhd(a,n)<<endl;		
	}
}
// Tu tuong dua vao bai 2
