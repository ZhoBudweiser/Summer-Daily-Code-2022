# include<iostream>
# include<queue>
# include<string.h>
using namespace std;

const int N = 105;
int H, W;
const int inf = 0x3f3f3f3f;
char matrix[N][N];
int visit[N][N][3];
int direct[4][2] {0, 1, 1, 0, -1, 0, 0, -1};

struct Node {
    int x, y;
};

void BFS(int sx, int sy, int index) {
    queue<Node> q;
    visit[sx][sy][index] = 0;
    q.push(Node{sx, sy});
    while (!q.empty()) {
        Node n = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = n.x + direct[i][0];
            int y = n.y + direct[i][1];
            if (1<=x && x <= H && 1 <= y && y <= W) {
                int step = visit[n.x][n.y][index];
                if (matrix[x][y] == '#')
                    step++;
                if (visit[x][y][index] > step) {
                    visit[x][y][index] = step;
                    q.push(Node{x, y});                    
                }
            }
        }
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    // int H, W;
    while (cin >> H >> W) {
        memset(visit, inf, sizeof(visit));
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= H; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                matrix[i][j+1] = s[j];
            }
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if ('w' == matrix[i][j]) {
                    BFS(i, j, 0);
                } else if ('W' == matrix[i][j]) {
                    BFS(i, j, 1);
                } else if ('f' == matrix[i][j]) {
                    BFS(i, j, 2);
                } 
            }
        }
        int ans = inf;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                int temp = visit[i][j][0]+visit[i][j][1]+visit[i][j][2];
                if (matrix[i][j] == '#') {
                    temp -= 2;
                }
                if (temp < ans) {
                    ans = temp;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
