#include<bits/stdc++.h>
using namespace std;

// Danh sach lien ket don
struct node{
	long long heso;
	long long mu;
	node *next;
};

// show da thuc
void show(node *dt)
{
	node *idx = dt;
	while(idx != NULL)
	{
		cout<<idx->heso<<"*x^"<<idx->mu;
		idx = idx->next;
		if(idx != NULL) cout<<" + ";
		else break;
	}
	cout<<endl;
}

// Them 1 node vao da thuc
void add_node(long long hs,long long m,node *&dt)
{
	node *temp = new node;
	temp->heso = hs;
	temp->mu = m;
	temp->next = NULL;	
	if(dt == NULL) dt = temp;
	else
	{
		node *idx = dt;
		while(idx->next != NULL) idx = idx->next;
		idx->next = temp; 
	}
}

// covert string a -> long long
long long s_l(string a)
{
	stringstream convert(a);
	long long x;
	convert>>x;
	return x;
}

// Xu ly chuoi
void process_string(string s,node *&dt)
{
	s += "|";
	string temp;
	vector<long long>res;
	for(long long i = 0 ; i < s.size() ; i++)
		if(s[i] >= '0' && s[i] <= '9') temp.push_back(s[i]);
		else if(temp.empty()!=1)
		{
			res.push_back(s_l(temp));
			temp.clear();
		}
	for(long long i = 0 ; i < res.size() ; i+= 2)
		add_node(res[i],res[i+1],dt);
}

// Xu ly
void process(string a,string b)
{
	// Xu ly chuoi
	node *dt1 = NULL,*dt2 = NULL,*res = NULL;
	process_string(a,dt1);
	process_string(b,dt2);
	// Thuat toan
	while(dt1 != NULL && dt2 != NULL)
		if(dt1->mu > dt2->mu)
		{
			add_node(dt1->heso,dt1->mu,res);
			dt1 = dt1->next;	
		}
		else if(dt1->mu < dt2->mu)
		{
			add_node(dt2->heso,dt2->mu,res);
			dt2 = dt2->next;			
		}
		else
		{
			add_node(dt1->heso+dt2->heso,dt1->mu,res);
			dt1 = dt1->next;	
			dt2 = dt2->next;		
		}
	// Hoan chinh
	while(dt1!=NULL)	
	{
		add_node(dt1->heso,dt1->mu,res);
		dt1 = dt1->next;		
	}
	while(dt2!=NULL)
	{
		add_node(dt2->heso,dt2->mu,res);
		dt2 = dt2->next;		
	}
	// In ket qua
	show(res);
}

main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long T;
	cin>>T;
	cin.ignore();
	string a,b;
	while(T--)
	{
		getline(cin,a);
		getline(cin,b);
		process(a,b);
	}
}
