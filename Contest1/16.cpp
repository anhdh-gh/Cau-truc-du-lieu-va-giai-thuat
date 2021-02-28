#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void in(vector<long long>b)
{
	for(long long i = 0 ; i < b.size() ; i++)
		cout<<b[i]<<" ";	
	cout<<endl;
}

long long stop;
void sinh(vector<long long>&b)
{
	stop = 0;
	long long i;
	for(i = b.size()-1 ; i > 0  ; i--)
		if(b[i] > b[i-1])
		{
			stop = 1;
			break;
		}
	for(long long j = b.size()-1 ; j >= i ;j--)
		if(b[j] > b[i-1])
		{
			swap(b[j],b[i-1]);
			break;
		}
	sort(b.begin()+i,b.end());	
}

long long kt(long long a[][999],long long n,vector<long long>b)
{
	long long sum = 0;
	for(long long i = 0 ; i < n ; i++)
		sum += a[i][b[i]-1];
	return sum;
}

main()
{
	// input
	long long n,k;
	cin>>n>>k;
	long long a[n][999];
	for(long long i = 0 ; i < n ; i++)
		for(long long j = 0 ; j < n ; j++)
			cin>>a[i][j];
	// xuly
	vector<vector<long long> >o;
	vector<long long>b;
	for(long long i = 0 ; i < n ; i++)
		b.push_back(i+1);
	if(kt(a,n,b) == k) o.push_back(b);
	sinh(b);
	while(stop == 1)
	{
		if(kt(a,n,b) == k) o.push_back(b);
		sinh(b);
	}
	// output
	cout<<o.size()<<endl;
	for(long long i = 0 ; i < o.size() ; i++)
		in(o[i]);
}
