#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        long long ans = n;



        for(int i = 0; i < n; ++i)
            cin >> arr[i];

        /**
            - Every non-decreasing sub-array is weird
            - Every decreasing sub-array is weird if we change every element xi to -xi
            - Every non-increasing sub-array preceded by a decreasing sub-array is weird if
              we change the element xi to -xi for every element in the decreasing sub-array

            Answer is to count every non-decreasing sub-array, every non-decreasing sub-array
            and every non-increasing sub-array preceded by a decreasing sub-array.

            Use a dp for couting every non-increasing sub-array preceded by a decreasing sub-array:
            0 <= i < n
            f(i) = length of the non-decreasing sub-array beginning at position i
        */

        long long dp[n];
        fill(dp, dp + n, 1);

        /// counting non-decreasing
        for(int i = 0; i < n - 1; ++i){
            if(arr[i] <= arr[i + 1]){
                int j;
                for(j = i + 1; j < n && arr[j] <= arr[j + 1]; ++j);
                if(j == n) j--;
                //cout << i << ' ' << j << '\n';

                long long len = j - i + 1;
                ans += len * (len - 1) / 2;

                dp[i] = len;

                i = j;
            }
        }

        /// counting decreasing and non-increasing preceded by decreasing
        for(int i = 0; i < n - 1; ++i){
            if(arr[i] > arr[i + 1]){
                int j;
                for(j = i + 1; j < n && arr[j] > arr[j + 1]; ++j);
                if(j == n) j--;
                //cout << i << ' ' << j << '\n';

                long long len = j - i + 1;
                ans += len * (len - 1) / 2;
                ans += (len - 1) * (dp[j] - 1);

                i = j;
            }
        }

        cout << ans << '\n';
    }
}
