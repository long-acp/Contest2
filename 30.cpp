#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 

vector<int> set; 
vector<int> prime;
vector<int> acc;
int val; 

bool isPrime(int x) 
{ 
	int sqroot = sqrt(x); 
	bool flag = true; 
	
	if (x == 1) 
		return false; 

	for (int i = 2; i <= sqroot; i++) 
		if (x % i == 0) 
			return false; 

	return true; 
} 

void display() 
{ 
	val++; 
	for (int i = 0; i < set.size(); i++) 
		acc.push_back(set[i]); 
} 

void primeSum(int total, int N, int S, int index) 
{ 

	if (total == S && set.size() == N) 
	{ 
		display(); 
		return; 
	} 

	if (total > S || index == prime.size()) 
		return; 

	set.push_back(prime[index]); 

	primeSum(total+prime[index], N, S, index+1); 
 
	set.pop_back(); 

	primeSum(total, N, S, index+1); 
} 
 
void allPrime(int N, int S, int P) 
{ 

	for (int i = P+1; i <=S ; i++) 
	{ 
		if (isPrime(i)) 
			prime.push_back(i); 
	} 

	if (prime.size() < N) 
		return; 
	primeSum(0, N, S, 0); 
} 

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int S,N,P; 
		cin>>N>>P>>S;
		val=0;
		allPrime(N, S, P);
		cout<<val<<endl;
		for(int i=0;i<acc.size();i+=N)
		{
			for(int j=i;j<i+N;j++) cout<<acc[j]<<" ";
			cout<<endl;
		}
		set.erase(set.begin(),set.end());
		prime.erase(prime.begin(),prime.end());
		acc.erase(acc.begin(),acc.end());
	 } 
	return 0; 
} 

