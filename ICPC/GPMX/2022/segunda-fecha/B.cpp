#include <bits/stdc++.h>

using namespace std;

long long lim;
int q;
vector<long long> cads;

long long m_atoi(string str){
    int n = str.size();
    long long num = 0, pot = 1;

    for(int i = n - 1; 0 <= i; --i){
        num += (str[i] - '0') * pot;
        pot *= 2;
    }

    return num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long lim = 1 << 16;
    cads.reserve(lim);

    for(long long i = 1; i < lim; ++i){
        long long tmp = i;
        string rbin = "", bin;
        while(tmp){
            rbin += to_string(tmp % 2);
            tmp /= 2;
        }

        bin = rbin;
        reverse(bin.begin(), bin.end());

        cads.push_back(m_atoi(bin + rbin));
        cads.push_back(m_atoi(bin + "0" + rbin));
        cads.push_back(m_atoi(bin + "1" + rbin));
    }

    cads.push_back(1);
    sort(cads.begin(), cads.end());

    cin >> q;
    while(q--){
        long long a, b;
        cin >> a >> b;
        auto posA = lower_bound(cads.begin(), cads.end(), a);
        auto posB = lower_bound(cads.begin(), cads.end(), b);

        if(b != *posB) posB--;

        cout << posB - posA + 1 << '\n';
    }
}