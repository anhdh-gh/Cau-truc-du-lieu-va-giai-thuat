#include<bits/stdc++.h>
using namespace std;
long long C[1005][1005];
long long qhd(string s1,string s2)
{
	for(long long i = 1 ; i <= s1.size() ; i++) // chay hang matran C
		for(long long j = 1 ; j <= s2.size() ; j++)	// Chay cot matran C
			if(s1[i-1]==s2[j-1]) 
				C[i][j] = C[i-1][j-1] + 1;
			else			
				C[i][j] = max(C[i-1][j],C[i][j-1]);
	return C[s1.size()][s2.size()];
}

main()
{
	long long T;
	cin>>T;
	string s1,s2;
	while(T--)
	{
		cin>>s1>>s2;
		cout<<qhd(s1,s2)<<endl;
	}
}
// Xem công thuc trong slide
