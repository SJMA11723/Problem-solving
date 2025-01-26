#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n; n--;

    map<string, int> cnt;
    string word; cin >> word;
    cnt["*****"]++;

    string tmp, ans;
    while( n-- ){
        cin >> tmp;
        ans = "XXXXX";
        /// i-esima letra
        for( int i=0; i<=5; i++ ){
            // correcta
            for( int j=0; j<=5; j++ ){
                if( tmp[i] == word[j] )
                    ans[i]='!';
            }
            // correcta y same poscion
             if( tmp[i] == word[i] )
                ans[i]='*';
        }
        cnt[ans]++;
//        cout << ans  << " " << cnt[ans] << "\n";
    }

    int g; cin >> g;
    while( g-- ){
        cin >>  tmp;
        cout << cnt[tmp] << '\n';
    }

}
