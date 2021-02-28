#include<bits/stdc++.h>
using namespace std;
//idea: 
// lap tu 0 -> cuoi cua chuoi bieu thuc hau to
// Neu s[i] la +-*/: s[i] = tinh(s[i-2],s[i-1],s[i])
// Xoa hai phan tu s[i-1] va s[i-2]
// i -= 2
// Tiep tuc lap cho den khi chi con 1 phan tu
// Return ket qua tinh duoc
// Note: Cac so co 1 chu so

bool check_tt(string x) //Kiem tra xem co phai la + - * / khong
{
	if(x == "+" || x == "-" || x == "*" || x == "/") return true;
	return false;
}

// covert string a -> long long
long long s_l(string a)
{
	stringstream convert(a);
	long long x;
	convert>>x;
	return x;
}

// convert long long -> string
string l_s(long long a)
{
	ostringstream convert;
	convert<<a;
	string x = convert.str();
	return x;
}

string tinh(string a,string b,string tt)
{
	if(tt=="+") return l_s(s_l(a)+s_l(b));
	if(tt=="-") return l_s(s_l(a)-s_l(b));
	if(tt=="*") return l_s(s_l(a)*s_l(b));
	if(tt=="/") return l_s(s_l(a)/s_l(b));
}

string process(string a)
{
	vector<string>res(a.size());
	for(long long i = 0 ; i < a.size() ; i++) //convert char -> string
		res[i] = a[i];
	for(long long i = 0 ; i < res.size() ; i++)
		if(check_tt(res[i])==true)
		{
			res[i] = tinh(res[i-2],res[i-1],res[i]);
			// Xoa phan tu thu i-1 va i-2
			res.erase(res.begin()+i-1);
			res.erase(res.begin()+i-2);
			i -= 2;
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
