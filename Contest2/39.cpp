#include<bits/stdc++.h>
using namespace std;


main()
{
	long long k,n;
	string s;
	cin>>s>>k;
	n = s.size();
	while(n < k) n *= 2; // Do dai cua s sau khi lap
	while(n > s.size())
	{
		if(k > n/2)       // Xem co nam o chuoi 2 hay khong
		{
			k -= n/2;	  // vi tri k nam o xau 2
			if(k == 1) k = n/2; // if k o dau xau 2 => k nam cuoi xau 1
			else k--;           // khong thi k nam o vi tri k-1 trong xau 1
		}
		n /= 2;
	}
	cout<<s[k-1]; // vi s tinh tu 0 nen phai -1
}

//Ex: ABC 3
//n = 3: 			ABC
//				123
//n = 6:          ABC-CAB
//				123 456
//n = 12: 		ABC-CAB--BABCCA
//
//n = 24: 		(((ABC)CAB)BABCCA)AABCCABBABCC
//xau					        1	 /    2
//xau					   1  /  2   )
//xau					1 / 2 )
// bo comment de xem
