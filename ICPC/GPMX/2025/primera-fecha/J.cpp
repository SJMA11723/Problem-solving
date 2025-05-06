#include<bits/stdc++.h>
#define MAXSZ 26
#define DEBUG if(deb)
#define MAXN 1000030
#define elacotadordepibes_yolosacotopibes 134217738
using namespace std;

bool deb = false;
int minmask[elacotadordepibes_yolosacotopibes];

void printmask(int mask){

    for(int i = 0; i < MAXSZ; i++){
        if((mask) & (1 << i)) printf("1");
        else printf("0");
    }
    printf("\n");
}
int preff[MAXSZ][MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;

    cin>>s;
    DEBUG printf("ola %d\n %d", s.length(),n);
    vector<int> arr(n);
    DEBUG printf("ola %d\n %dklxlasdkasdl", s.length(),n);
    for(int x = 0; x < n; x++){
        arr[x] = s[x]-'a';
    }
    DEBUG printf("ola\n");

    preff[arr[0]][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < MAXSZ; j++){
            preff[j][i] = preff[j][i-1];
        }
        preff[arr[i]][i]+=1;
    }
    DEBUG printf("flag\n");


    vector<int> pmasks(n);
    for(int i = 0; i < n; i++){
        int mask = 0;
        for(int j = 0; j < MAXSZ; j++){
            bool val = (preff[j][i]%2);
            if(val) mask |= (1 << j);
        }
        pmasks[i] = mask;
        if(minmask[mask] == 0)  minmask[mask] = i+1;

    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        DEBUG printf("...\n");
        DEBUG printmask(pmasks[i]);
        if(minmask[pmasks[i]]){
            int p = minmask[pmasks[i]];
            p--;
            if(p < i) {
                DEBUG printf("%d %d valid\n", p, i);
                ans = max(ans, i-p);
            }
        }
        for(int j = 0; j < MAXSZ; j++){
            int xmask = ((pmasks[i])^(1 << j));
            if(minmask[xmask]){
                int p = minmask[xmask];
                p--;
                if(p < i) {
                    ans = max(ans, i-p);
                    DEBUG printf("%d %d valid, mymask %d, xmask %d\n", p, i, pmasks[i], xmask);
                    DEBUG printmask(pmasks[i]);
                    DEBUG printmask(xmask);

                }
            }
        }

        int setbits = __builtin_popcount(pmasks[i]);
        if(setbits == 0 || setbits == 1) ans = max(ans, i+1);
    }

    cout<<ans<<"\n";


}
