#include<iostream>
#include<vector>
#define MAXN 110
#define MAXB 10010

using namespace std;
int dp[MAXN][MAXB];

int main(){


    int c;
    scanf("%d", &c);

    int x;

    vector<int> vt;
    while(scanf("%d", &x) == 1){
        vt.push_back(x);
    }

    int n = vt.size();
    vector<int> v;
    vector<int> w;
    for(int x = 0; x < n; x++){
        if(x < (n/2)){
            v.push_back(vt[x]);
        }
        else{
            w.push_back(vt[x]);
        }
    }

    for(int b = 0; b <= c; b++){
        if(b >= w[0]) dp[0][b] = v[0];
    }
    int nn = v.size();
    for(int i = 1; i < (nn); i++){
        for(int j = 0; j <= c; j++){
            if(j - w[i] >= 0) dp[i][j] = max(v[i]+dp[i-1][j-w[i]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = dp[(nn)-1][c];
    cout<<ans<<"\n";
    
}