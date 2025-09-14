#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string arr[12];
    arr[0] = "DO";
    arr[1] = "DO#";
    arr[2] = "RE";
    arr[3] = "RE#";
    arr[4] = "MI";
    arr[5] = "FA";
    arr[6] = "FA#";
    arr[7] = "SOL";
    arr[8] = "SOL#";
    arr[9] = "LA";
    arr[10] = "LA#";
    arr[11] = "SI";
    map<string, int> idx;
    for(int i = 0; i < 12; ++i) idx[arr[i]] = i;

    int s;
    string note;
    cin >> s >> note;
    cout << arr[(idx[note] - s + 12) % 12] << '\n';
}
