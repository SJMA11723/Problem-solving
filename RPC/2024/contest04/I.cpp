#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t A,B,C;
    cin >>  A >> B >> C;

    int64_t DP[A+1][B+1][C+1][4];
    memset(DP, sizeof(DP),0 );

    for(int a=0; a<=A; a++){
        for(int b=0; b<=B; b++){
            for(int c=0; c<=C; c++){
                if( a==0 ){
                    DP[a][b][c][0]=0;
                }else{
                    DP[a][b][c][0] =  DP[a-1][b][c][1] + DP[a-1][b][c][2];
                }
                if( b==0 ){
                    DP[a][b][c][1]=0;
                }else{
                    DP[a][b][c][1] =  DP[a][b-1][c][0] + DP[a][b-1][c][2];
                }
                if( c==0 ){
                    DP[a][b][c][2]=0;
                }else{
                    DP[a][b][c][2] =  DP[a][b][c-1][0] + DP[a][b][c-1][1];
                }


                if( a==1 && b==0 && c==0 ) DP[a][b][c][0]=1;
                if( a==0 && b==1 && c==0 ) DP[a][b][c][1]=1;
                if( a==0 && b==0 && c==1 ) DP[a][b][c][2]=1;


                for( int k =0; k<3; k++ ){
                    if( DP[a][b][c][k]>MOD  ) DP[a][b][c][k]-=MOD;
                }
            }
        }
    }

    int64_t ans = DP[A][B][C][0] + DP[A][B][C][1];
    if( ans > MOD ) ans-=MOD;
    ans += DP[A][B][C][2];
    if( ans > MOD ) ans-=MOD;

    cout << ans <<'\n';

}
