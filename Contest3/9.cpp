#include<bits/stdc++.h>
using namespace std;

struct JOB{
	long long jobld;
	long long deadline;
	long long profit;
};

bool comp(JOB x,JOB y){return (x.profit > y.profit);}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		JOB a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i].jobld>>a[i].deadline>>a[i].profit;
		sort(a,a+n,comp);
		long long time[1001]={0};      // khoang thoi gian truoc deadline 0,1,2,3,4,...< deeadline
		long long dem = 0,pf = 0;
		for(long long i = 0 ; i < n ; i++)
			for(long long j = a[i].deadline-1 ; j >= 0 ; j--)// kiem tra xem truoc deadline cong viec do con co time lam khong
				if(time[j]==0)
				{
					time[j] = 1;
					dem++;
					pf += a[i].profit;
					break; // tim thay gan xong phai thoat luon
				}	
		cout<<dem<<" "<<pf<<endl;
	}
}
