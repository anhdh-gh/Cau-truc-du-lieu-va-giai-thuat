#include<bits/stdc++.h>
using namespace std;

void process(string a)
{
	//B1: Loai bo het cac cap dau ngoac dung
	vector<char>s;
	for(long long i = 0 ; i < a.size() ; i++)
	{
		if(s.empty()!=1 && s.back()=='(' && a[i]==')') s.pop_back();
		else s.push_back(a[i]);
	}
	//B2: m: la so ngoac dong, n: la so ngoac mo
	long long m = 0, n = 0;
	for(long long i = 0 ; i < s.size() ; i++)
		if(s[i]==')') m++;
		else n++;
	//So luong ngoac can phai doi chieu la: ceil(m/2)+ceil(n/2)
	// ceil(x): return so nho nhat >= x
	cout<<ceil((double)m/2)+ceil((double)n/2)<<endl;
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		process(a);
	}
}
//https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
