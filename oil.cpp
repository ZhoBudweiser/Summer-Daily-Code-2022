# include<iostream>
# include<stdio.h>
# include <string.h>
using namespace std;

const int N = 105;
int H, W;
char matrix[N][N];
bool visit[N][N];
int direct[8][2] {
    0, 1, 
    1, 0, 
    -1, 0, 
    0, -1,
    -1, -1,
    1, 1,
    -1, 1,
    1, -1
};

void DFS(int sx, int sy) {
    visit[sx][sy] = true;
    for (int i = 0; i < 8; i++) {
        int x = sx + direct[i][0];
        int y = sy + direct[i][1];
        if (matrix[x][y] == '@' && visit[x][y] == 0) {
            DFS(x, y);
        }                
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while (cin >> H >> W) {
        if (0 == H && 0 == W) {
            break;
        }
        memset(visit, false, sizeof(visit));
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= H; i++) {
            scanf("%s", matrix[i]+1);
        }
        int ans = 0;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if ('@' == matrix[i][j] && !visit[i][j]) {
                    DFS(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
