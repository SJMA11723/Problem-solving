#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, c; cin >> n >> r >> c;
    r--, c--;

    list<int> arr;
    vector<int> ans;

    for(int i = 0; i < n; ++i) arr.push_back(i + 1);

    auto ptr1 = arr.begin(), ptr2 = --arr.end();
    while(arr.size() > 2){
        int tmp = r % arr.size();
        while(tmp--){
            ptr1++;
            if(ptr1 == arr.end()) ptr1 = arr.begin();
        }
        tmp = c % arr.size();
        while(tmp--){
            if(ptr2 == arr.begin()) ptr2 = arr.end();
            ptr2--;
        }

        //cout << *ptr1 << ' ' << *ptr2 << '\n';

        if(ptr1 == ptr2){
            ans.push_back(*ptr1);

            ptr1 = arr.erase(ptr1);
            ptr2 = ptr1;

            if(ptr2 == arr.begin()) ptr2 = arr.end();
            ptr2--;

            if(ptr1 == arr.end()) ptr1 = arr.begin();
        } else {
            ptr1 = arr.erase(ptr1);
            if(ptr1 == arr.end()) ptr1 = arr.begin();

            if(ptr1 == ptr2) ptr2 = ptr1 = arr.erase(ptr1);
            else ptr2 = arr.erase(ptr2);

            if(ptr2 == arr.begin()) ptr2 = arr.end();
            ptr2--;

            if(ptr1 == arr.end()) ptr1 = arr.begin();
        }

        //cout << "Arreglo: ";
        //for(int x : arr) cout << x << ' ';
        //cout << '\n';

        //cout << "Final: " << *ptr1 << ' ' << *ptr2 << '\n';
    }

    while(arr.size()){
        int x = arr.front();
        ans.push_back(x);
        arr.pop_front();
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }

    return 0;
}
