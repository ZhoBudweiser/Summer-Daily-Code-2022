# include<iostream>
# include<queue>
# include<string.h>
using namespace std;

const int N = 105;
int H, W;
int ans = 0x3f3f3f3f;
char matrix[N][N];
bool visit[N][N];
int direct[4][2] {0, 1, 1, 0, -1, 0, 0, -1};

void DFS(int step, int sx, int sy) {
    if (step >= ans) {
        return;
    }
    if (matrix[sx][sy] == 'E') {
        if (step < ans) {
            ans = step; 
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x = sx + direct[i][0];
        int y = sy + direct[i][1];
        if (1 <= x && x <= H && 1 <= y && y <= W) {
            if ((matrix[x][y] == '*' || matrix[x][y] == 'E') && visit[x][y] == 0) {
                visit[x][y] = 1;
                DFS(step+1, x, y);
                visit[x][y] = 0;
            }                
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
        ans = 0x3f3f3f3f;
        memset(visit, false, sizeof(visit));
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                char ch;
                cin >> ch;
                matrix[i][j] = ch;
            }
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if ('S' == matrix[i][j]) {
                    DFS(0, i, j);
                }
            }
        }
        if (ans == 0x3f3f3f3f) {
            cout << "-1" << endl;
        } else
            cout << ans << endl;
    }

    return 0;
}
