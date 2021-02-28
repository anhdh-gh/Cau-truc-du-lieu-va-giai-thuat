#include<bits/stdc++.h>
using namespace std;

void solve(long long s,long long d)
{
	if(s == 0 && d==1) cout<<0;
	else if((s == 0 && d!=1) || (s > 9*d)) cout<<-1; // so max la 99...9; neu tong lon hon 999 thi khong tao duoc
	else 
	{
		long long c[d];
		s -= 1;
		for(long long i = d-1 ; i > 0 ; i--)
			if(s > 9)
			{
				c[i] = 9;
				s -= 9;
			}
			else 
			{
				c[i] = s;
				s = 0;	
			}
			c[0] = s+1;
		for(long long i = 0 ; i < d ; i++)
			cout<<c[i];		
	}
}

main()
{
	long long T,s,d;
	cin>>T;
	while(T--)
	{
		cin>>s>>d;
		solve(s,d);
		cout<<endl;
	}
}
