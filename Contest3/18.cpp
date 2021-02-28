#include<bits/stdc++.h>
using namespace std;

void xuly(long long sum)
{
	if(sum < 4) {cout<<-1;return;}
	vector<long long>out;
	while(sum%7!=0)
	{
		out.push_back(4);
		sum -= 4;
		if(sum < 0) {cout<<-1;return;}
	}
	for(long long i = 0 ; i < sum/7 ; i++)
		out.push_back(7);
	for(long long i = 0 ; i < out.size() ; i++)
		cout<<out[i];
}

main()
{
	long long T,sum;
	cin>>T;
	while(T--)
	{
		cin>>sum;
		xuly(sum);
		cout<<endl;
	}
}
