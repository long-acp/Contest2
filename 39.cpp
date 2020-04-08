#include<bits/stdc++.h>

using namespace std;

string s;
long long n,lg,du;
double x;

long long findnum(long long i)
{
	if(i<=lg) 
	{
		x=0;
		du=i;
	}
	else 
	{
		x=(log(i)-log(lg))/log(2);
		du=i-lg*pow(2,(int)x);
	}
//	cout<<du<<" "
	if(i>=1&&i<=lg)
	{
	//	val=i;
		return i;
	}
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
//	for(int i=1;i<=n;i++)
//	{
//		
	cout<<s[findnum(n)-1]<<endl;
//	}


	return 0;
}
