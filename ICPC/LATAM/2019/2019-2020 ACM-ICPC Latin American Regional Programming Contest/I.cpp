#include<bits/stdc++.h>


#define MOD 1000000007
using namespace std;
#define DEBUG if(deb)

bool deb = false;
bool vis[2010];
int cnt[2010];
pair<int,int> dfs(vector<vector<int>>&adyl, int u, int l){

    DEBUG printf("dfs at %d\n", u);
    if(vis[u]){
        return make_pair(cnt[u], 0);
    }

    vis[u] = true;


    int mailsrep = 0;
    int mails = 0;
    for(auto child : adyl[u]){
        if(child > l) {
            if(!vis[child]){
                mails++;
                mails%=MOD;
                vis[child] = true;
            }
            mailsrep++;
            mailsrep%=MOD;
        }
        else{
            auto [valrep, val] = dfs(adyl, child,l);
            mailsrep+=valrep;
            mailsrep%=MOD;
            mails+=val;
        }
    }


    DEBUG printf("ans for %d is {%d,%d}\n", u, mailsrep, mails);

    cnt[u] = mailsrep;
    return make_pair(mailsrep, mails);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,l;


    cin>>n>>l;

    vector<vector<int>> adyl(n+1, vector<int>());
    for(int x = 1; x <= l; x++){
        int k;
        cin>>k;
        for(int i = 0; i < k;i++){
            int v;
            cin>>v;
            adyl[x].push_back(v);
        }
    }


    auto[b,a] = dfs(adyl, 1, l);

    printf("%d %d\n", b,a);


}
