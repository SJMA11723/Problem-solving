// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
#define MOD 1000000007
#define DEBUG if(deb)

bool deb = false;
int main() {
	int n;
    cin>>n;

    int arr[n];
    int tr[n+1];
    for(int x = 0; x < n; x++) cin>>arr[x];
    for(int x = 0; x < n; x++) cin>>tr[x];
    tr[n] = -INF;

    sort(arr, arr+n);
    sort(tr, (tr)+n+1);

    int i = n-1;
    int j = n;
    int acu = 0;
    int cnt[n];
    while(i >= 0){

        DEBUG printf("i%d j%d\n", i,j);
        if(tr[j]>= arr[i]){
            acu++;
            j--;
        }
        else{
            cnt[i] = acu;
            i--;
        }
    }
    long long ans = 1;
    for(int i = 0; i < n; i++){
        DEBUG printf("cnt %d = %d\n", n-1-i, cnt[n-1-i]);
        int c = cnt[n-1-i];

        ans*= (long long)((max(c - i, 0))%MOD);
        ans%=MOD;
    }

    cout<<ans<<"\n";
}
