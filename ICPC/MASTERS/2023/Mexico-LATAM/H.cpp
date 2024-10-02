#include<iostream>
#include<vector>
#include<algorithm>
#define DEBUG if(deb)


bool deb = true;

using namespace std;

typedef long long ll;
class FenwickTree{
    public:


    int n;
    vector<ll> ft;

    FenwickTree(int n){
        this->n = n;
        ft.assign(n+1,0);
    }

    FenwickTree(int n, int* arr):FenwickTree(n){
        
        for(int x = 0; x < n; x++){
            updateSum(x+1, arr[x]);
        }
    }
    void updateSum(int idx, ll u){
        for(int x = idx; x <= n; x +=x&(-x)){
            ft[x]+=u;
        }
    }

    ll query(int idx){
        ll ans = 0;
        for(int x = idx; x > 0; x-=x & (-x) ){
            ans+=ft[x];
        }

        return ans;
    }
    void pointUpdate(int idx, ll u){
        ll delta = u - (query(idx) - query(idx-1));
        updateSum(idx, delta);
    }

    ll rangeQuerie(int l, int r){
        ll ans = query(r) - query(l-1);

        return ans;
    }

};



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int arr[n+1];
    for(int x = 1; x <= n; x++){
        cin>>arr[x];
    }

    FenwickTree ft(n);
    
    vector<pair<int,pair<int,int>>> updates;

    updates.push_back({0,{0,0}});
    for(int x = 1; x <= m; x++){
        int day, val;
        cin>>day>>val;
        updates.push_back({x, {day,val}});
    }

    vector<pair<int,pair<int,pair<int,int>>>> queries;

    for(int x = 0; x < q; x++){
        int day,l,r;
        cin>>day>>l>>r;
        queries.push_back({day,{x,{l,r}}});

    }

    sort(queries.begin(), queries.end());

    int i = 1;

    int a[q];
    for(int x = 0; x < q; x++){

        auto [day, querie] = queries[x];
        auto [ogidx,q] = querie;
        auto [l,r] = q;

        //DEBUG printf("day %d, %d %d\n", day, l,r);
        while(day >= i){
            auto [d, update] = updates[i];
            auto [idx,v] = update;

            ll currval = ft.query(idx) - ft.query(idx-1);
            currval = min(currval + v, (long long)arr[idx]);    
            ft.pointUpdate(idx, currval);
            
            i++;
        }
        
        ll ans = ft.rangeQuerie(l,r);

        a[ogidx]= ans;
    }

    for(auto x: a){
        cout<<x<<"\n";
    }

}