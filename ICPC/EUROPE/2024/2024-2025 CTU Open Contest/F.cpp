// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
    cin>>n>>m;
    long long sum = 0;
    int mm = 100000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int t;
            cin>>t;
            sum+=t;

            if((i+j)%2 != 0) mm = min(mm, t);
        }
    }  
    if(n%2 == 1 || m%2 == 1) cout<<sum<<"\n";
    else cout<<(sum-mm)<<"\n";
}
