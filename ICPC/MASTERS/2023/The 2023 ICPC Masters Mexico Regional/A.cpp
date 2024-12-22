// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;

	long long arr[n];
	for(int x = 0; x < n; x++)cin>>arr[x];

	int l = 0, r = n-1;
	int ans = 0;
	while(l<=r){
		if(arr[l] == arr[r]){
			l++;
			r--;
		}
		else{
			ans++;
			if(arr[l] <= arr[r]){
				arr[l+1]+=arr[l];
				l++;
			}
			else{
				arr[r-1]+=arr[r];
				r--;
			}
		}
	}

	cout<<ans<<"\n";
}
