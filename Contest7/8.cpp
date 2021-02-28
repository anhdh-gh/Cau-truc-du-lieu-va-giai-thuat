#include<bits/stdc++.h>
using namespace std;

void in(vector<char>res)
{
	for(long long i = 0 ; i < res.size() ; i++)
		cout<<res[i];
	cout<<endl;
}

void process(string a)
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
	in(res);
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
