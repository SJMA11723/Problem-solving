// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;


	int n = s.length();

	int acu = 0;


	int maxi = -1;
	int maxidx = 0;
	for(int x = 0; x < n; x++){
		if(s[x] == '+')acu++;
		else acu--;

		if(acu > maxi){
			maxi = acu;
			maxidx = x;
		}
	}

	cout<<maxidx+1<<"\n";
}
