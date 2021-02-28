#include<iostream>
#include<math.h>
using namespace std;
long long a[999],n,check;

long long kt(long long i,long long j)
{
	for(long long k = 1 ; k < i ; k++) // chay quan hau tu 1 to quan hau hien tai
		if(a[k] == j || abs(k - i) == abs(a[k] - j))
			return 0;
	return 1;
}

void TRY(long long i)
{
	for(long long j = 1 ; j <= n ; j++) // chay cot
		if(kt(i,j) == 1)
		{
			a[i] = j;
			if(i == n) check++;
			else TRY(i+1);
		}
}

main()
{
	check = 0;
	cin>>n;
	TRY(1);
	cout<<check<<endl;
}
