#include<bits/stdc++.h>
using namespace std;
// Lap tu 0 -> size
// Neu la s[i] +-*/: s[i-2]  = (s[i-2] + s[i] +  s[i-1])
// Xao s[i-1] va s[i];
// i -= 2: vi da xao 2 phan tu
// tiep tuc lap

bool check_tt(string x) //Kiem tra xem co phai la + - * / khong
{
	if(x == "+" || x == "-" || x == "*" || x == "/") return true;
	return false;
}

string process(string a)
{
	vector<string>res(a.size());
	for(long long i = 0 ; i < a.size() ; i++) //convert char -> string
		res[i] = a[i];
	for(long long i = 0 ; i < res.size() ; i++)
		if(check_tt(res[i])==true)
		{
			res[i-2] = "("+res[i-2]+res[i]+res[i-1]+")";	
			// Xoa phan tu thu i-1 va i
			res.erase(res.begin()+i--);
			res.erase(res.begin()+i--);
		}
	return res[0];
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<process(a)<<endl;
	}
}
