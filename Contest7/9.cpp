#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Sinh xau nhi phan
void sinh(string &np)
{
	for(long long i = np.size()-1 ; i >= 0 ; i--)
		if(np[i]!='0') np[i] = '0';
		else {np[i] = '1';break;}
}

string output(string a,string np,vector< pair<long long,long long> >luu)
{
	vector<long long>bo;
	for(long long i = 0 ; i < np.size() ; i++)
		if(np[i] == '1')
		{
			a[luu[i].first] = 't';
			a[luu[i].second] = 't';
		}
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i] == 't') a.erase(a.begin()+i--);
	cout<<"a = "<<a<<endl;
	return a;
}

void process(string a)
{
	// tim vi tri cac cap ngoac
	vector< pair<long long,long long> >luu;
	pair<long long,long long>temp;
	stack< pair<long long,long long> >st;
	for(long long i = 0 ; i < a.size() ; i++)	
		if(a[i]=='(')
		{
			temp.first = i;
			st.push(temp);
		} 
		else if(a[i]==')') 
		{
			st.top().second = i;
			luu.push_back(st.top());
			st.pop();
		}
	// Sinh xau nhi phan voi n = luu.size()
	string np,stop;
	set<string>res; // tu dong loai bo phan tu giong nhau va tu sort (tu min -> max)
	// Khoi tao xau ban dau
	for(long long i = 0 ; i < luu.size() ; i++) {np.push_back('0');stop.push_back('1');}
	while(np != stop)
	{
		sinh(np);
		res.insert(output(a,np,luu));
	}
	for(set<string>::iterator it  = res.begin() ; it != res.end() ; it++)
		cout<<*it<<endl;
}

main()
{
	string a;
	cin>>a;
	process(a);
}
