#include<bits/stdc++.h>
using namespace std;
long long n,a[100000];
void khoitao()
{
	cin>>n;
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	sort(a,a+n);	
}

long long process()
{
	long long dem = 0;
	long long mid = n/2;
	long long i;
	for(i = mid-1 ; i>= 0 ; i--)
		if(2*a[i] <= a[n-1]) break;
	long long j = n-1;
	while(i >= 0 && j >= mid)
		if(2*a[i] <= a[j]){dem++;i--;j--;}
		else i--;		
	return dem;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		khoitao();
		cout<<n-process()<<endl;
	}
}
//Co n con
//=> So con co the nhin thay la: n/2 <= so con <= n
