// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& h, vector<int>& d){

	int n = h.size();
	bool flag = true;
	int pivot = h[0];
	for(int x = 1; x < n; x ++){


		if(d[x-1] >= pivot){
			flag = false;
			break;
		}
		else{
			pivot = max(h[x], pivot - d[x-1]);
		}
	}

	return flag;
}

int main() {
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> h(n), d(n-1);

		for(int x = 0; x < n; x++) cin>>h[x];

		for(int x = 0; x < n-1; x++) cin>>d[x];

		bool f1 = check(h,d);

		reverse(h.begin(), h.end());
		reverse(d.begin(), d.end());

		bool f2 = check(h,d);


		if(f1 || f2) cout<<"habibi\n";
		else cout<<"which\n";




	}

}
