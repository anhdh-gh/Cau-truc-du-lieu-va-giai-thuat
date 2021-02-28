#include<iostream>
#include<vector>
using namespace std;

long long stop;

void sinh(string &a,long long n)
{
	stop = 0;
	long long i;
	for(i = n-1 ; i >= 0 ; i--)
		if(a[i] == 'A') 
		{
			stop = 1;
			a[i] = 'B';
			break;
		}
		else a[i] = 'A';	
}

long long kt(string a,long long k,long long n)
{
	long long i = 0,j,count = 0;
	while(i < n)
	{
		j = i;
		while(a[i] == 'A' && a[j] == a[i] && j < n) j++;
		if((j-i) == k) count++;
		if(j!=i) i = j;
		else i++;
	}
	if(count == 1) return 1;
	return 0;
}

main()
{
	vector<string>b;
	long long n,k;
	cin>>n>>k;
	string a;
	for(long long i = 0 ; i < n ; i++)
		a.push_back('A');
	if(kt(a,k,n)==1) b.push_back(a);
	sinh(a,n);
	while(stop == 1)
	{
		if(kt(a,k,n)==1) b.push_back(a);
		sinh(a,n);
	}
	cout<<b.size()<<endl;
	for(long long i = 0 ; i < b.size() ; i++)
		cout<<b[i]<<endl;
}
