#include<iostream>
#include<algorithm>
using namespace std;

void nhap(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
}

void xuat(long long a[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void xuly(long long a[],long long n)
{	
	long long i;
	for(i = n-1 ; i > 0 ; i--)
		if(a[i] > a[i-1])
			break;
	if(i == 0) 
	{
		sort(a,a+n);
		return;		
	}
	else
	{
		for(long long j = n-1 ; j >= i ; j--)
			if(a[j] > a[i-1])
			{
				swap(a[j],a[i-1]);
				break;
			}
		sort(a+i,a+n);	
	}
}

main()
{
	long long T,n,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		nhap(a,n);
		xuly(a,n);
		xuat(a,n);
	}
}

//void xuly(long long a[],long long n)
//{
//	long long i = n-2,j;
//	while(a[i] > a[i+1]) i--;
//	if(i < 0) 
//	{
//		sort(a,a+n);
//		return;
//	} 
//	else
//	{
//		j = n-1;
//		while(a[j] < a[i]) j--; 
//		swap(a[j],a[i]);
//		sort(a+i+1,a+n);
//	}
// }
