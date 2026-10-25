#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int hh, mm, ss;
    cin >> hh >> mm >> ss;
    if(hh < 2) cout << "-\n";
    else if(hh > 2) cout << "+\n";
    else if(mm > 30) cout << "+\n";
    else if(mm < 30) cout << "-\n";
    else if(ss > 0) cout << "+\n";
    else cout << "=\n";
}