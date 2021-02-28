#include<iostream>
#include<vector>
using namespace std;

long long stop;
void sinh(vector<long long>&b,long long n,long long k)
{
	stop = 0;
	long long i;
	for(i = k-1 ; i >= 0 ; i--)
		if(b[i] != n-k+i+1)
		{
			stop = 1;
			b[i] += 1;
			break;
		}
	for(long long j = i+1 ; j < k ; j++)
		b[j] = b[i]+j-i;
}

long long kt(long long a[],vector<long long>b)
{
	long long sum = 0;
	for(long long i = 0 ; i < b.size() ; i++)
		sum += a[b[i]-1];
	return sum;
}

int main()
{
	// input
	long long n,s,check = 0;
	cin>>n>>s;
	long long a[n];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	// xuly
	// sinh to hop chap k cua n
	vector<long long>b;
	for(long long k = 1 ; k <= n ; k++)
	{
		b.clear();
		for(long long i = 0 ; i < k ; i++)
			b.push_back(i+1);
		if(kt(a,b) == s) 
		{
			cout<<b.size()<<endl;
			check = 1;
			return 0;
		}
		sinh(b,n,k);
		while(stop == 1)
		{
			if(kt(a,b) == s) 
			{
				cout<<b.size()<<endl;
				check = 1;
				return 0;
			}
			sinh(b,n,k);
		}		
	}
	if(check==0) cout<<-1;
}
