#include<bits/stdc++.h>

using namespace std;




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int64_t tu, arr[n-1];

    cin >> tu; n--;
    for( int i=0; i<n; i++ ){
        cin >> arr[i];
    }

    sort( arr, arr + n );

    int vivos = n;
    for( int i=0; i<n; i++ ){
        tu -= ( arr[i] -1 )*(vivos) + (vivos - 1);
        if( tu <= 0 ){
            cout << "NO\n";
            return 0;
        }
        vivos--;
    }

    cout << "SI\n";

}
