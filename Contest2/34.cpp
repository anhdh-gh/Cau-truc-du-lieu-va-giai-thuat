#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long input[100][100],a[100];

void nhap()
{
	for(long long i = 1 ; i <= 8 ; i++)
		for(long long j = 1 ; j <= 8 ; j++)
			cin>>input[i][j];
}

long long kt(long long i,long long j)
{
	for(long long k = 1 ; k < i ; k++) // chay quan hau tu 1 to quan hau hien tai
		if(a[k] == j || abs(k - i) == abs(a[k] - j))
			return 0;
	return 1;
}

void tong(long long &max)
{
	long long sum = 0;
	for(long long i = 1 ; i <= 8 ; i++)
		sum += input[i][a[i]];
	if(max < sum) max = sum;
}


void TRY(long long i,long long &max)
{
	for(long long j = 1 ; j <= 8 ; j++) // chay vi tri theo cot
		if(kt(i,j) == 1)
		{
			a[i] = j;
			if(i == 8) tong(max);
			else TRY(i+1,max);
		}
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long max = -1;
		nhap();
		TRY(1,max);
		cout<<max<<endl;
	}
}
