#include <bits/stdc++.h>

using namespace std;

const int N = 2024;

set<pair<int, int>> corners;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    corners.insert({0, 0});
    corners.insert({0, N});
    corners.insert({N, 0});
    corners.insert({N, N});

    pair<int, int> p1, p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;

    if(p1 == p2){
        cout << "1\n";
        return 0;
    }

    if(p2 < p1) swap(p1, p2);

    if(p1 == make_pair(0, 0) && p2 == make_pair(N, N)){
        cout << "0\n";
        return 0;
    }

    if(p1 == make_pair(0, N) && p2 == make_pair(N, 0)){
        cout << "0\n";
        return 0;
    }

    if(corners.count(p1) || corners.count(p2)){
        cout << "1\n";
        return 0;
    }

    cout << "2\n";
}
