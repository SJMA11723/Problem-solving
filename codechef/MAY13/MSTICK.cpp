#include <bits/stdc++.h>
#define MAXN 200005
#define LOGN 21

using namespace std;

int n, q;
int arr[MAXN];
int STMIN[MAXN][LOGN], STMAX[MAXN][LOGN];
int lg2[MAXN];

void buildST(){
    for(int i = 0; i < n; ++i){
        STMIN[i][0] = STMAX[i][0] = arr[i];
    }

    ///build min/max
    for(int k = 1; k < LOGN; ++k){
        int fin = (1 << k) - 1;
        for(int i = 0; i + fin < n; ++i){
            STMIN[i][k] = min(STMIN[i][k - 1], STMIN[i + (1 << (k - 1))][k - 1]);

            STMAX[i][k] = max(STMAX[i][k - 1], STMAX[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /// precompute logarithms
    lg2[1] = 0;
    for(int i = 2; i < MAXN; ++i){
        lg2[i] = lg2[i / 2] + 1;
    }

    cin >> n;

    /// read n elements
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    n *= 2;
    buildST();
    n /= 2;

    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        int lg = lg2[r - l + 1];

        double mini = min(STMIN[l][lg], STMIN[r - (1 << lg) + 1][lg]);
        double maxi = max(STMAX[l][lg], STMAX[r - (1 << lg) + 1][lg]);

        int tam2 = l + n - 1 - r;
        int lgtam = lg2[tam2];

        double maxi2 = 0;

        if(tam2) maxi2 = max(STMAX[r + 1][lgtam], STMAX[(r + tam2) - (1 << lgtam) + 1][lgtam]);

        cout << fixed << setprecision(1);
        cout << mini + max(maxi2, (maxi - mini) / 2) << '\n';
    }
}
