#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

// #define NMAX 1010
// typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int64_t MOD = 1e9 + 7;


bool vis[NMAX][NMAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, m;
    cin>>n>>m;

    vector<string> mat(n);

    for(int x = 0; x < n; x++){
        cin>>mat[x];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < m && mat[i][j] != 'o'){
            if(!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
            j++;
        }
        j = m-1;
        while(j >= 0 && mat[i][j] != 'o'){
            if(!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
            j--;
        }
    }
    for(int j = 0; j < m; j++){
        int i = 0;
        while(i < n && mat[i][j] != 'o'){
            if(!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
            i++;
        }
        i = n-1;

        while(i >= 0 && mat[i][j] != 'o'){
            if(!vis[i][j]) {
                ans++;
                vis[i][j] = true;
            }
            i--;
        }
    }
    cout<<ans<<"\n";
}