#include <bits\stdc++.h>
#define MAXN 105

using namespace std;

struct point{
    int x, y;

    int operator*(const point &b)const{
        return x * b.y - b.x * y;
    }

    point operator-(const point &b){
        return point{x - b.x, y - b.y};
    }
};

void move(int &x, int &y, char c){
    if(c == 'N') y++;
    else if(c == 'S') y--;
    else if(c == 'E') x++;
    else x--;
}

int raining[MAXN][MAXN][MAXN];
int edge[MAXN][MAXN][MAXN];
set<char> dir[MAXN][MAXN][MAXN];

struct pos{
    int x, y;
    int d;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir_char[4] = {'E', 'W', 'N', 'S'};
char opp_dir[4] = {'W', 'E', 'S', 'N'};
char perp1[4] = {'N', 'N', 'E', 'E'};
char perp2[4] = {'S', 'S', 'W', 'W'};

bool border(int x, int y, int d){
    return edge[y][x][d] && raining[y][x][d] == edge[y][x][d];
}

bool valid_cell(int x, int y){
    return !(x < 0 || 100 < x || y < 0 || 100 < y);
}

bool safe(int x, int y, int nx, int ny, int d, int k){
    cout << "   Comprueba " << x << ' ' << y << ' ' << nx << ' ' << ny << ' ' << d << '\n';
    cout << "   " << border(x, y, d) << ' ' << raining[nx][ny][d + 1] << ' ' << dir_char[k] << ' ' << perp2[k] << '\n';

    /// Revisa si llueve a los lados en direccion perpendicular
    move(x, y, perp1[k]);
    if(valid_cell(x, y) && raining[y][x][d] && dir[y][x][d].count(perp2[k])){
        cout << "   falla perp2\n";
        return false;
    }

    move(x, y, perp2[k]);
    move(x, y, perp2[k]);
    if(valid_cell(x, y) && raining[y][x][d] && dir[y][x][d].count(perp1[k])){
        cout << "   falla perp1\n";
        return false;
    }

    move(x, y, perp1[k]);

    if(raining[y][x][d] && raining[ny][nx][d]) return border(x, y, d) && border(nx, ny, d);
    else if(!raining[y][x][d] && raining[ny][nx][d] && dir[nx][ny][d].count(opp_dir[k])) return false;

    return true;
}

int bfs(int a, int b, int c, int d){
    bool vis[MAXN][MAXN][MAXN];
    memset(vis, 0, sizeof(vis));
    queue<pos> q;
    q.push({a, b, 0});
    vis[b][a][0] = true;
    while(q.size()){
        pos cur = q.front();
        q.pop();

        cout << "Llega " << cur.x << ' ' << cur.y << ' ' << cur.d << '\n';
        if(cur.x == c && cur.y == d) return cur.d;

        if(cur.d == MAXN) continue;

        for(int k = 0; k < 4; ++k){
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            cout << "   Intenta " << dir_char[k] << ' ' << nx << ' ' << ny << ' ' << cur.d + 1 << '\n';
            if(!valid_cell(nx, ny) || vis[ny][nx][cur.d + 1] || !safe(cur.x, cur.y, nx, ny, cur.d, k)) continue;
            cout << "   Agrega " << nx << ' ' << ny << ' ' << cur.d + 1 << '\n';
            vis[ny][nx][cur.d + 1] = true;
            q.push({nx, ny, cur.d + 1});
        }

        if(!vis[cur.y][cur.x][cur.d + 1]){
            cout << "   Agrega " << cur.x << ' ' << cur.y << ' ' << cur.d + 1 << '\n';
            vis[cur.y][cur.x][cur.d + 1] = true;
            q.push({cur.x, cur.y, cur.d + 1});
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d; cin >> a >> b >> c >> d;

    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        int v; cin >> v;
        vector<point> vertices;
        for(int i = 0; i < v; ++i){
            int x, y; cin >> x >> y;
            vertices.push_back({x, y});
        }
        vertices.push_back(vertices[0]);

        bool cur_edge_V[MAXN][MAXN];
        memset(cur_edge_V, 0, sizeof(cur_edge_V));

        bool cur_edge_H[MAXN][MAXN];
        memset(cur_edge_H, 0, sizeof(cur_edge_H));

        for(int i = 1; i <= v; ++i){
            if(vertices[i].x == vertices[i - 1].x){
                int x = vertices[i].x;
                int mini = min(vertices[i].y, vertices[i - 1].y);
                int maxi = max(vertices[i].y, vertices[i - 1].y);
                for(int y = mini; y <= maxi; ++y){
                    edge[y][x][0]++;
                    cur_edge_V[y][x] = true;
                    raining[y][x][0]++;
                    dir[y][x][0].insert(c);
                }
            } else {
                int y = vertices[i].y;
                int mini = min(vertices[i].x, vertices[i - 1].x);
                int maxi = max(vertices[i].x, vertices[i - 1].x);
                for(int x = mini; x <= maxi; ++x){
                    edge[y][x][0]++;
                    raining[y][x][0]++;
                    dir[y][x][0].insert(c);
                    cur_edge_H[y][x] = true;
                }
            }
            edge[vertices[i].y][vertices[i].x][0]--;
            raining[vertices[i].y][vertices[i].x][0]--;
        }


        for(int x = 0; x < MAXN; ++x)
        for(int y = 0; y < MAXN; ++y){
            if(cur_edge_V[y][x] || cur_edge_H[y][x]){/// quiero del poligono actual
                int time = 0, curx = x, cury = y;
                move(curx, cury, c);
                time++;
                while(valid_cell(curx, cury)){
                    raining[cury][curx][time]++;
                    edge[cury][curx][time]++;
                    dir[cury][curx][time].insert(c);
                    move(curx, cury, c);
                    time++;
                }
                continue;
            }

            int cnt = 0;
            for(int xx = x; xx < MAXN; ++xx)
                if(cur_edge_V[y][xx]) cnt++; /// del poligono actual

            if(cnt % 2 == 0) continue;

            int time = 0, curx = x, cury = y;
            while(valid_cell(curx, cury)){
                raining[cury][curx][time]++;
                dir[cury][curx][time].insert(c);
                move(curx, cury, c);
                time++;
            }
        }
    }

    int N = 11;
    for(int t = 0; t < 7; ++t){
        cout << t << ":\n";
        for(int y = N; 0 <= y; --y){
            cout << setw(2) << setfill('0') << y << ": ";
            for(int x = 0; x <= N; ++x) cout << raining[y][x][t] << " \n"[x == N];
        }
        cout << '\n';
    }

    //for(int t = 0; t < 3; ++t){
    //    for(int y = 5; 0 <= y; --y)
    //    for(int x = 0; x <= 5; ++x) cout << edge[y][x][t] << " \n"[x == 5];
    //    cout << '\n';
    //}

    cout << bfs(a, b, c, d) << '\n';
}
