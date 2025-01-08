// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	vector<int> fact;

	int i = 2;
	int ogn = n;
	while(i<= ogn){
		if(n%i == 0){
			fact.push_back(i);
			n/=i;
		}
		else{
			i++;
		}
	}

	for(int x = 0; x < fact.size(); x++){
		if(x != (fact.size()-1))cout<<fact[x]<<"x";
		else cout<<fact[x]<<"\n";
	}
}
