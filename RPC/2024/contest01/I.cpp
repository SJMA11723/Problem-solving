/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> arr;
    for(int t = 0; t < 52; ++t){
        string str; cin >> str;
        arr.push_back(str);

        /*cout << "Entra: ";
        for(string s : arr) cout << s << ' ';
        cout << '\n';*/

        bool cambio = true;
        while(arr.size() > 3 && cambio){
            cambio = false;

            for(int i = (int)arr.size() - 1; 3 <= i; --i){
                if(arr[i][0] == arr[i - 3][0]){
                    arr.erase(arr.begin() + i - 3, arr.begin() + i + 1);
                    cambio = true;
                    /*cout << "M: ";
                    for(string s : arr) cout << s << ' ';
                    cout << '\n';*/
                    break;
                }
            }

            if(cambio) continue;

            for(int i = (int)arr.size() - 1; 3 <= i; --i){
                if(arr[i][1] == arr[i - 3][1]){
                    arr.erase(arr.begin() + i);
                    arr.erase(arr.begin() + i - 3);
                    cambio = true;
                    /*cout << "M: ";
                    for(string s : arr) cout << s << ' ';
                    cout << '\n';*/
                    break;
                }
            }
        }
    }

    cout << arr.size() << ' ';
    for(string s : arr) cout << s << ' ';
    cout << '\n';
}
