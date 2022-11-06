class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int ant = 0, fib = 1;
        n--;
        while(n--){
            fib += ant;
            ant = fib - ant;
        }
        return fib;
    }
};