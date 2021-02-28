#include<bits/stdc++.h>
using namespace std;

bool check_tt(char x) //Kiem tra xem co phai la + - * / khong
{
	if(x == '+' || x == '-' || x == '*' || x == '/') return true;
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

// tinh toan gia tri
string tinh(string a,string b,string tt)
{
	if(tt=="+") return l_s(s_l(a)+s_l(b));
	if(tt=="-") return l_s(s_l(a)-s_l(b));
	if(tt=="*") return l_s(s_l(a)*s_l(b));
	if(tt=="/") return l_s(s_l(a)/s_l(b));
}

// Tinh toan bieu thuc khong co ngoac (bieu thuc trong ngoac)
string TINH(vector<string>a)
{
	// Tinh * / truoc
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i]=="*" || a[i]=="/")
		{
			a[i-1] = tinh(a[i-1],a[i+1],a[i]);
			// Xoa a[i] va a[i+1]
			a.erase(a.begin()+i,a.begin()+i+1+1);
			i--;			
		}
	// Tinh + -
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i]=="+" || a[i]=="-")
		{
			a[i-1] = tinh(a[i-1],a[i+1],a[i]);
			// Xoa a[i] va a[i+1]
			a.erase(a.begin()+i,a.begin()+i+1+1);
			i--;			
		}
	return a[0];
}

string process(string a)
{
	// B1: chuyen doi sang string
	vector<string>res;
	for(long long i = 0 ; i < a.size() ; i++) 
		if(a[i]=='(') res.push_back("(");
		else if(a[i]==')') res.push_back(")");
		else if(check_tt(a[i])==true)
		{
			if(a[i]=='+') res.push_back("+");
			else if(a[i]=='-') res.push_back("-");
			else if(a[i]=='*') res.push_back("*");
			else if(a[i]=='/') res.push_back("/");
		}
		else // Neu a[i] la so
		{
			string temp;
			temp.push_back(a[i]);
			while(a[i+1] >= '0' && a[i+1] <= '9')
				temp.push_back(a[++i]);
			res.push_back(temp);
		}
	// B2: Tinh toan tat ca cac ngoac
	for(long long i = 0 ; i < res.size() ; i++)
		if(res[i]==")")
		{
			vector<string>ngoac;
			long long j = i-1;
			while(j>= 0 && res[j]!="(") j--; // Tim vi tri ngaoc mo
			for(long long k = j+1 ; k < i ; k++)
				ngoac.push_back(res[k]);
			res[j] = TINH(ngoac); 
			res.erase(res.begin()+j+1,res.begin()+i+1);
			i = j;
		}
	// B3: Chi con lai bieu thuc khong co ngoac
	return TINH(res);
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
