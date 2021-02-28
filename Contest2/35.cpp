#include<iostream>
#include<vector>
using namespace std;
long long n,k,s,sum,count;
vector<long long>out;

void TRY(long long i,long long sum)
{
	out.push_back(i);
	sum += i;
	if(out.size() == k && sum == s) count++;
	if(sum > s && out.size() > k) return;
	else
		for(long long j = i+1 ; j <= n ; j++)
		{
			TRY(j,sum);
			out.pop_back();
		}
}

main()
{
	while(cin>>n>>k>>s && n!=0 && k != 0 && s != 0)
	{
		out.clear();
		count = 0;
		for(long long i = 1 ; i <= n ; i++)
			{
				out.clear();
				sum = 0;
				TRY(i,sum);		
			}			
		cout<<count<<endl;	
	}
}
