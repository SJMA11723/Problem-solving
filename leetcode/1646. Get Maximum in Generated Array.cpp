class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
 
        int *arr = new int[n + 1];
        int ans = 1;

        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i <= n; ++i){
            arr[i] = arr[i / 2];
            if(i % 2)
                arr[i] += arr[i / 2 + 1];

            ans = max(ans, arr[i]);
        }

        delete[] arr;
        return ans;
    }
};