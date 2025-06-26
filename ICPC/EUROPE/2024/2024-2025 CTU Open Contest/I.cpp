// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define MAXN 400010
#define DEBUG if(deb)
using namespace std;

bool deb = false;
int preff[MAXN][31];
int k;
int bbsearch(int ini, int fin, int n, int* lims){


    int ans = -1;

    while(ini <= fin){
        
        int mit = (ini+fin)/2;
        DEBUG printf("%d %d\n", ini, fin);
        bool flag = true;
        for(int i = 0; i < 31; i++){
            if(k & (1 << i)){
                if(preff[mit][i] >= lims[i]){
                    DEBUG printf("i exceeds %d %d, %d\n", i, preff[mit][i], lims[i]);
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            
            ans = mit;
            DEBUG printf("fhalf %d\n", ans);
            ini = mit+1;
           
        }
        else{
            fin = mit-1;
        }
    }
     DEBUG printf("ans %d\n", ans);

    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
    cin>>n>>k;

    int arr[n];

    for(int x = 0; x < n; x++) cin>>arr[x];

    

    for(int i = 0; i < 31; i++){
        if(arr[0] & (1 << i)) preff[0][i] =1;
        else preff[0][i] = 0;
    }


    for(int x = 1; x < n; x++){
        for(int i = 0; i < 31; i++){
            if(arr[x] & (1 << i)) preff[x][i] = preff[x-1][i]+1;
            else preff[x][i] = preff[x-1][i];
        }
    } 


    map<array<int, 31>, int> mp;
    int lims[31];
    long long ans = 0;

    int ksz = __builtin_popcount(k);
    for(int x = 0; x < n; x++){
        array<int,31> a;
        
        int cnt = 0;
        bool flag = true;
        for(int i = 0; i < 31; i++){
            if((k & (1 << i))){
                a[i] = 1;
                lims[i] = preff[x][i];
                if(lims[i]) cnt++;
            }
            else{
                a[i] = preff[x][i];
                if(a[i]) flag = false;
            }
        }
        if(cnt == ksz && flag) ans++;
        
        DEBUG printf("lol %d\n", x);
        if(!mp.count(a)) mp[a] = x;
        int ini = mp[a];
        DEBUG printf("enter %d\n", ini);
        int fin = bbsearch(ini, x-1, n, lims);
        if(fin == -1) {
            DEBUG printf("fumbled\n");
            continue;
        }
        ans+= fin-ini+1;
        DEBUG printf("cnt%d\n", cnt);
        
        DEBUG printf("...%d\n", ans);
    }
    cout<<ans<<"\n";

    

}
