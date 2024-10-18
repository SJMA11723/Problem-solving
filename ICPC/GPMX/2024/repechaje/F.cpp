#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A[10];
    int B[10];
    for(int c=0; c < 5; c++){
        cin >> A[c];
    }
    for(int c=0; c < 4; c++){
        cin >> B[c];
    }
    for(int c=0; c < 5; c++){
        bool esta = false;
        for(int k=0; k < 4; k++){
            if(A[c]==B[k])
                esta = true;
        }
        if(!esta){
            cout << A[c];
            return 0;
        }
    }
}
