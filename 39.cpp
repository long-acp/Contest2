#include<bits/stdc++.h>

using namespace std;

string s;
long long n,lg;

int findnum(long long i)
{
	long x=(long)(log((i/lg))/log(2));
	long long du=i-lg*pow(2,x);
	
	if(i>=1&&i<=lg) return i;
	else 
	{
		if(du==0) findnum(i/2-1);
		else if(du==1) findnum(i-1);
		else findnum(du-1);
	}

}

int main()
{
	cin>>s>>n;
	lg=s.length();
	cout<<s[findnum(n)-1];

	return 0;
}

