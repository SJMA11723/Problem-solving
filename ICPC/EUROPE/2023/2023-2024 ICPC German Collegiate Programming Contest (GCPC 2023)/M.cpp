#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int op(int a, int b, int op){
    if(op == 0) return a + b;
    else if(op == 1) return a - b;
    else if(op == 2) return a * b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d; cin >> d;
    for(int i = 1; i <= 100; ++i)
    for(int j = i + 1; j <= 100; ++j)
    for(int k = j + 1; k <= 100; ++k){
        if(i == j || i == k || j == k) continue;
        if(i == d || j == d || k == d) continue;

        int arr[3] = {i, j, k};
        bool ok = true;
        do{
            int a = arr[0];
            int b = arr[1];
            int c = arr[2];

            /// usa los 3
            for(int op1 = 0; op1 < 3; ++op1)
            for(int op2 = 0; op2 < 3; ++op2){
                /// (a + b) + c
                if(op(op(a, b, op1), c, op2) == d){
                    ok = false;
                    break;
                }

                /// a + (b + c)
                if(op(a, op(b, c, op2), op1) == d){
                    ok = false;
                    break;
                }
            }

            /// op2 == 3
            for(int op1 = 0; op1 < 3; ++op1){
                /// (a + b) / c = d
                if(op(a, b, op1) == d * c){
                    ok = false;
                    break;
                }

                /// a + (b / c) = d
                if(op1 <= 1){
                    if(op(a * c, b, op1) == d * c){
                        ok = false;
                        break;
                    }
                } else if(a * b == d * c){
                    ok = false;
                    break;
                }
            }

            /// op1 == 3
            for(int op2 = 0; op2 < 3; ++op2){
                /// (a / b) + c
                if(op2 <= 1){
                    if(op(a, b * c, op2) == b * d){
                        ok = false;
                        break;
                    }
                } else if(a * c == b * d){
                    ok = false;
                    break;
                }

                /// a / (b + c)
                if(a == d * op(b, c, op2)){
                    ok = false;
                    break;
                }
            }

            if(a == b * c * d || a * c == b * d) ok = false;

            /// a + b
            for(int op1 = 0; op1 < 3; ++op1){
                /// a + b == d
                if(op(a, b, op1) == d){
                    ok = false;
                    break;
                }
            }
            if(a == b * d) ok = false;

            /// a + c
            for(int op1 = 0; op1 < 3; ++op1){
                /// a + c == d
                if(op(a, c, op1) == d){
                    ok = false;
                    break;
                }
            }
            if(a == c * d) ok = false;

            /// b + c
            for(int op1 = 0; op1 < 3; ++op1){
                /// b + c == d
                if(op(b, c, op1) == d){
                    ok = false;
                    break;
                }
            }
            if(b == c * d) ok = false;
        }while(next_permutation(arr, arr + 3));

        if(ok){
            cout << i << ' ' << j << ' ' << k << '\n';
            return 0;
        }
    }
}
