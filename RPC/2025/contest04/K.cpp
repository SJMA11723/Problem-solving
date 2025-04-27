#include<bits/stdc++.h>

using namespace std;


int r,c,s,t;
int land[20][20];
char elFloor[4][20][20];
int x[4],y[4];

int ageOfTrees(int i, int j, int g ){
    if(  i+ x[g] > r || j + y[g] > c ) return 40000;

    int ans = 0;
    for( int ii=i; ii< i + x[g]; ii++){
    for( int jj=j; jj< j + y[g]; jj++){
        if( elFloor[g][ii-i][jj-j] == '#' )
            ans += land[ii][jj];
    }}
    return ans;
}

// rr y cc locales
void rotar( int rr, int cc, char rota[20][20], char ans[20][20] ){
    for( int i=0; i<rr; i++ ){
    for( int j=0; j<cc; j++ ){
          ans[j][rr-1-i] =  rota[i][j];
    }}
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 0;
    cin >> r >> c;
    for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
        cin >> land[i][j];
        total+= land[i][j];
    }}
    cin >> s >> t;
    for( int i=0; i<s; i++ ){
    for( int j=0; j<t; j++ ){
        cin >> elFloor[0][i][j];
    }}


    // rotar
    rotar(s,t, elFloor[0], elFloor[1]);
    rotar(t,s, elFloor[1], elFloor[2]);
    rotar(s,t, elFloor[2], elFloor[3]);

    x[0] = s, y[0] = t;
    x[1] = t, y[1] = s;
    x[2] = s, y[2] = t;
    x[3] = t, y[3] = s;
//
//    for( int g=0; g<4; g++ ){
//    for( int i=0; i<20; i++ ){
//    for( int j=0; j<20; j++ ){
//        if( elFloor[g][i][j] != '#') cout << ".";
//        else cout << elFloor[g][i][j];
//    }
//        cout << "\n";
//    }
//        cout << "\n";
//    }



    // probar todo
    int ans =  40000;
    for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
    for( int g=0; g<4; g++ ){
        ans = min( ans, ageOfTrees(i,j,g) );
//        cout << "i: " << i << " j:" << j << "  g: " << g << " tres:" << ageOfTrees(i,j,g) <<'\n';
    }}}

    cout << total - ans << '\n';


}

