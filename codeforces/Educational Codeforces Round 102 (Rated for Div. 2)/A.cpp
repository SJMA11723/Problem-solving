#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    
    cin >> t;
    
    
    while(t--){
        int n, d;
        bool ok = true;
        
        cin >> n >> d;
        
        int arr[n];
        
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            
            if(d < arr[i]) ok = false;
        }
        
        if(ok) cout << "yes\n";
        else {
            for(int i = 0; i < n && !ok; ++i){
                for(int k = i + 1; k < n && !ok; ++k){
                    if(arr[i] + arr[k] <= d){
                        ok = true;
                    }
                }
            }
            
            if(ok) cout << "yes\n";
            else cout << "no\n";
        }
    }
}