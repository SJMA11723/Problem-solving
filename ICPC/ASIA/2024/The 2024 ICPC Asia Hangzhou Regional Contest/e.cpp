#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n, x;
        cin>>n>>x;

        set<int> events;

        vector<pii> vp;
        vector<pii> vps;
        map<int,vector<pii>> miv;
        set<array<int, 3>> seen;
        int maxi = 0;
        for(int x = 0; x < n; x++){
            int l,r;
            cin>>l>>r;
            maxi = max(maxi, r);
            vp.pb({l,r});
            vps.pb({l,r})
            miv[l].pb({r,x});
            seen.insert({r,l,x});
            events.insert(l);
            events.insert(r);
        }
        sort(vps.begin(), vps.end());
        vector<int> e;
        for(auto x: events)e.pb(x);


        pii maxheight[maxi];
        pii maxi = {-1,-1};
        for(auto x: e){
            for(auto r : miv[x]){
                maxi = max(maxi, r);
            }
            maxheight[x] = maxi;
        }

        vector<pii>::iterator lb = lower_bound(vps.begin(), vps.end(), {f, -1});


        int ini;
        long long ans = 0;
        if(lb == vps.begin()){
            ini = *(lb).first;
        }
        else{
            auto [l,r] = *(--lb)
            if(l <= ini && ini <= r){
                ini = l;
            }
            else {
                if((++lb)!= vps.end()){
                    ini = *(lb).first;
                    ans += ini-f;
                }
                else{
                    ini = *(--lb).second;
                }
            }
        }

        vector<int> a;
        for(auto x : e){
            if(x < ini) continue;
            ans+= (x -ini);
            ini = x;
            while(true){
                auto [nh, idx] = maxheight[ini];
                auto [l,r] = vp[idx];
                a.pb(idx);
                seen.erase({r,l,idx});
                ans += (r-l);
                if(ini == nh) break;
                else ini = nh;
            }
            if(ini == maxi) break;
        }

        while(!seen.empty()){
            auto thang = *(--seen.end());
            ans += seen[0]-seen[1];
            a.pb(seen[2]);
            seen.erase(thang);
        }

        cout<<ans<<"\n";

        for(auto x : a){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    
}