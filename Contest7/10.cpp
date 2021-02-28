#include<bits/stdc++.h>
using namespace std;

vector<char> process(string a)
{
	vector<char>res;
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i]!=')') res.push_back(a[i]); // Neu chua gap ngoac dong
		else // Neu gap ngoac dong
		{
			long long j = res.size()-1;
			while(res[j]!='(' && j>=0) j--; // Tim ngoac mo gan nhat (tu phai qua trai)
			res.erase(res.begin()+j); // Neu tim thay => Xoa ngoac mo
			if(res[j-1]=='-') // Neu truoc ngoac mo la dau - 
				while(j < res.size()) //=> doi tat cac dau o trong res tu j den res.size()-1
				{
					if(res[j]=='-') res[j] = '+';
					else if(res[j]=='+') res[j] = '-';	
					j++;		
				}	
		}
	return res;
}

bool check(vector<char>a,vector<char>b)
{
	long long i = 0,j = 0;
	while(i < a.size() && j < b.size())
	{
		if(a[i]!=b[j]) return false;
		i++;
		j++;
	}
	return true;
}

main()
{
	long long T;
	cin>>T;
	string a,b;
	while(T--)
	{
		cin>>a>>b;
		if(check(process(a),process(b))==true) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
