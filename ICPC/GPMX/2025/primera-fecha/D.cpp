
#include<bits/stdc++.h>
#define VMAX 1e12
using namespace std;
typedef long long ll;

bool func(ll* arr, ll* sum, int k, ll day){
    bool ans = true;
    for(int x = 0; x < k; x++){
        if(  sum[x]*day > arr[x]){
            ans = false;
            break;
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;

    ll arr[k];
    ll sum[k]{0};
    for(int x = 0; x < k; x++) cin>>arr[x];

    int n;
    cin>>n;
    vector<vector<ll>> ord(n, vector<ll>(k));

    for(int x = 0; x < n; x++){
        for(int y = 0; y < k; y++){
            cin>>ord[x][y];
            sum[y]+=ord[x][y];
        }
    }
    ll maxa = *max_element(arr , arr+k);
    ll maxi = *max_element(sum , sum+k);

    ll ini = 1, fin = maxa/maxi+10;
    long long day = -1;
    while(ini <= fin){
        ll mit = (ini+fin)/2;
        bool q = func(arr, sum ,k, mit);
        if(q){
            ini = mit+1;
        }
        else{
            day = mit;
            fin = mit-1;
        }
    }
    for(int x = 0; x < k; x++){
        arr[x]-= sum[x]*(day-1);
    }
    long long order = -1;
     for(int x = 0; x < n; x++){
        for(int y = 0; y < k; y++){
            arr[y]-=ord[x][y];
            if(arr[y] < 0){
                order = x+1;
                x = y= max(n,k);
                //break;
            }
        }
    }

    cout<<day<<" "<<order<<"\n";


}




