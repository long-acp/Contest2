#include<bits/stdc++.h>

using namespace std;

int dau[25],cuoi[25],check[25],n,m,val;

void find(int i,int acp)
{
	val=max(val,acp);
	
	for(int j=0;j<m;j++)
	{
		if(check[j]==1)
		{
			if(dau[j]==i)
			{
				check[j]=0;
				find(cuoi[j],acp+1);
				check[j]=1;
			}
			else if(cuoi[j]==i)
			{
				check[j]=0;
				find(dau[j],acp+1);
				check[j]=1;
			}
			
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;i++)  
		{
			cin>>dau[i]>>cuoi[i];
			check[i]=1;
		}
		val=0;
		for(int i=0;i<n;i++)
		{
			find(i,0);
		}
		cout<<val<<endl;
		
	}

	return 0;
}

