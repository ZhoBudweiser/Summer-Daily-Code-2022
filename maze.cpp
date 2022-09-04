# include<iostream>
# include<queue>
# include<string.h>
using namespace std;

const int N = 105;
char matrix[N][N];
bool visit[N][N];
int direct[4][2] {0, 1, 1, 0, -1, 0, 0, -1};

struct Node {
    int step;
    int x, y;
};

int BFS(int sx, int sy) {
    queue<Node> q;
    visit[sx][sy] = 1;
    q.push(Node{0, sx, sy});
    int ans = -1;
    while (!q.empty()) {
        Node n = q.front();
        q.pop();
        if (matrix[n.x][n.y] == 'E') {
            ans = n.step;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = n.x + direct[i][0];
            int y = n.y + direct[i][1];            
            if ((matrix[x][y] == '*' || matrix[x][y] == 'E') && visit[x][y] == 0) {
                visit[x][y] = 1;
                q.push(Node{n.step+1, x, y});
            }
        }
    }
    return ans;
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int H, W;
    while (cin >> H >> W) {
        if (0 == H && 0 == W) {
            break;
        }
        memset(visit, false, sizeof(visit));
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                char ch;
                cin >> ch;
                matrix[i][j] = ch;
            }
        }
        int ans;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if ('S' == matrix[i][j]) {
                    ans = BFS(i, j);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
