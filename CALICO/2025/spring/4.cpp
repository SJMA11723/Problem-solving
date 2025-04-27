#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define s second
#define f first
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while(t--){
        int n,m,xd;
        cin >> n >> m ;
        pii coord[n*m+1];
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> xd;
            coord[xd]={i,j};
        }}
        coord[0] = {0,0};
        int ans =0;
        for(int i=0; i<n*m; i++){
            int distx = abs( coord[i].f -  coord[i+1].f );
            int disty = abs( coord[i].s -  coord[i+1].s );
            disty = min( disty, m-disty );
            distx = min( distx, n-distx );
            ans += distx + disty;
        }

        cout << ans << '\n';
    }

}
