// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define MOD 1000000007
#define DEBUG if(deb)

bool deb = false;
using namespace std;
int dp[1010][1010];
int main() {
ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];

        for(int x = 0; x < n; x++){
            cin>>arr[x];
            if(arr[x] == 0 || arr[x] == 1) dp[x][x] = 1;
            else dp[x][x] = 0;
        }


        for(int sz = 1; sz < n; sz++){
            for(int l = 0; l+sz < n; l++){
                int r = l+sz;
                dp[l][r] = 0;
                int num = sz+1;
                if(arr[l] == 0 || arr[l] == num) dp[l][r]+=dp[l+1][r];
                dp[l][r]%=MOD;
                if(arr[r] == 0 || arr[r] == num) dp[l][r]+=dp[l][r-1];
                dp[l][r]%=MOD;
                
            }   
        }   
        DEBUG{
            for(int x = 0; x < n; x++) cout<<arr[x]<<" ";
            cout<<"\n dp: \n";

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout<<dp[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        cout<<dp[0][n-1]<<"\n";
    }
    
}
