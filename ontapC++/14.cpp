#include<iostream>
#include<algorithm>
using namespace std;
// Bai nay dung long long la loi no rum-time
//phai dung: int

struct data{
	int value,count,index;
};

bool comp1(data a,data b)
{
	return a.value < b.value;
}

bool comp2(data a,data b)
{
	if(a.count != b.count) return a.count < b.count;
	else return a.index > b.index;
}

void solve(int a[],int n)
{
	data b[n];
	for(int i = 0 ; i < n ; i++)
	{
		b[i].value = a[i];
		b[i].count = 0;
		b[i].index = i;
	}
	stable_sort(b,b+n,comp1);
	b[0].count = 1;
	for(int i = 1 ; i < n ; i++)
		if(b[i].value == b[i-1].value)
		{
			b[i].count += b[i-1].count + 1;
			b[i-1].count = -1;
			b[i].index = b[i-1].index;
		}
		else b[i].count = 1;
	stable_sort(b,b+n,comp2);
	for(int i = n-1; i >= 0 ; i--)
		if(b[i].count != -1)
			for(int j = 0 ; j < b[i].count ; j++)
				cout<<b[i].value<<" ";
	cout<<endl;
}

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		solve(a,n);
	}
	return 0;
}
