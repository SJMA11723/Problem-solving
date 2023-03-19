class Solution {
public:
    int passThePillow(int n, int time) {
        time %= 2 * n - 2;
        /*if(time + 1 <= n) return time + 1; /// n - (n - (time + 1)) = time + 1
        else return 2 * n - time - 1; /// n - (time + 1 - n) = 2n - time - 1*/
        return n - abs(time + 1 - n);
    }
};