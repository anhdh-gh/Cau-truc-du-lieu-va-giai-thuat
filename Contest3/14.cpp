#include<bits/stdc++.h>
using namespace std;

long long tim(long long k,vector<long long>ln)
{
	vector<long long>lk;
	while(k > 0){lk.push_back(k%10);k/=10;}		// 5 2 1
	long long ck = lk.size()-1;
	for(long long i = ln.size()-1 ; i >= 0 ; i--)	
	{
		if(lk[ck]==ln[i]) ck--;		// Khi tim duoc cai nao ck--- 
		if(ck < 0) return 1;		// Den khi nao ck < 0 tuc la da tim het cac so 
	}
	return 0;
}

main()
{
	long long T,n,m,danhdau;
	cin>>T;
	while(T--)
	{
		cin>>n;
		m = n; // 4125
		vector<long long>ln;
		while(m>0){ln.push_back(m%10);m/=10;} // 5 2 1 4
		danhdau = 0;
		for(long long i = pow(n,1.0/3)+1 ; i >= 1 ; i--) // i = (n)^1/3
			if(tim(i*i*i,ln)==1) // Khi i = 5 => tim(125)
			{
				cout<<i*i*i<<endl;
				danhdau = 1;
				break;
			}
		if(danhdau==0) cout<<-1<<endl;
	}
}
