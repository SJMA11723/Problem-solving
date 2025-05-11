#include<bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;


    while(t--){
        int n,id,prior; cin >> n;

        vector< pair< pair<int,int>, int>  > arr(n);

        for( int i=0; i<n; i++){
            cin >> arr[i].second; // id
            arr[i].first.second = i; // llegada antes
        }
        for( int i=0; i<n; i++){
            cin >> arr[i].first.first ; // prioridad
        }

        sort( arr.begin(), arr.end());


        for(int i=0; i<n; i++ ){
            cout << arr[i].second << " \n"[i==n-1];
        }
    }



}