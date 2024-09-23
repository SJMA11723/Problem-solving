#include<bits/stdc++.h>
#include<set>

#define DEBUG if(deb)


bool deb = false;
using namespace std;

int64_t dp[200][1<<11];


void printmask(int mask,int sz){
    int i = 1;
    cout<<"[";
    while(i <= sz){
        if(mask& (1<<i)){
            cout<<1;
        }
        else{
            cout<<0;
        }
        i++;
    }

    cout<<"]"<<endl;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;


    set<pair<int,int> > s;


    for(int u = 1; u <= n; u++){
        int m;
        cin>>m;

        for(int x  = 0 ; x < m ; x++) {
            int v;
            cin>>v;
            pair<int,int> uv = make_pair(u,v);
            pair<int,int> vu = make_pair(v,u);
            if(!s.count( vu )) s.insert( uv );
        }
    }

    vector<pair<int,int> > pairs;

 //v is 1 indexed

    for(auto p : s){
        pairs.push_back(p);
    }

    int sz = pairs.size();
    for(int mask = 0; mask < (1<<(n+1)); mask++){
        dp[sz][mask] = 1;
    }


    //printf("lolquemal %d\n", sz);
    for(int m = sz-1; m >= 0; m--){


        for(int mask = 0; mask < (1<<(n+1)); mask++){

            //incluir

            int x = pairs[m].first;
            int y = pairs[m].second;

            if(!(mask & (1<<x) || mask & (1<<y))) {
                int newmask = mask;
                newmask|=(1<<x);
                newmask|=(1<<y);
                dp[m][mask]+= dp[m+1][newmask];
            }
            dp[m][mask]+=dp[m+1][mask];
            DEBUG{
                printf("dp[%d]", m);
                printmask(mask, n);
                printf(" = %d\n", dp[m][mask]);
            }
        }
    }

    cout<<dp[0][0];




}
