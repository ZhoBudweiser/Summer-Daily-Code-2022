# include<iostream>
# include<queue>
using namespace std;

int N, M;
char matrix[105][105];
int direct[4][2] {0, 1, 1, 0, -1, 0, 0, -1};

struct Node {
    int x, y;
};

bool BFS(int gx, int gy, int sx, int sy, int t) {
    queue<Node> qg, qs;
    qs.push(Node{sx, sy});
    qg.push(Node{gx, gy});
    while (t && !qg.empty()) {
        // 提前获取队列中的元素个数，便于统一时间点内使得所有该轮扩散的气体都被访问
        int gSize = qg.size();
        while (gSize--) {
            Node g = qg.front();
            qg.pop();
            for (int i = 0; i < 4; i++) {
                int ngx = g.x + direct[i][0];
                int ngy = g.y + direct[i][1];
                if (1 <= ngx && ngx <= N && 1 <= ngy && ngy <= M) {
                    if (matrix[ngx][ngy] == 'S' || matrix[ngx][ngy] == '.') {
                        matrix[ngx][ngy] = 'G';
                        qg.push(Node{ngx, ngy});
                    }
                }
            }                     
        }
        int sSize = qs.size();
        // 人存在或毒气扩散
        while (sSize-- && !qg.empty()) {
            Node s = qs.front();
            qs.pop();
            if (matrix[s.x][s.y] == 'G') {
                continue;
            }
            // matrix[s.x][s.y] = '.';
            for (int i = 0; i < 4; i++) {
                int nsx = s.x + direct[i][0];
                int nsy = s.y + direct[i][1];
                if (1 <= nsx && nsx <= N && 1 <= nsy && nsy <= M) {
                    if (matrix[nsx][nsy] == '.') {
                        matrix[nsx][nsy] = 'S';
                        qs.push(Node{nsx, nsy});
                    }
                }
            }
        }
        t--;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int t;
        while (cin >> N >> M >> t) {
            // memset(matrix, 0, sizeof(matrix));
            // 输入数据
            for (int i = 1; i <= N; i++) {
                string s;
                cin >> s;
                for (int j = 0; j < s.size(); j++) {
                    matrix[i][j+1] = s[j];
                }
            }
            // 找到毒气和人的位置
            int gx, gy, sx, sy;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (matrix[i][j] == 'G') {
                        gx = i;
                        gy = j;
                    } else if (matrix[i][j] == 'S') {
                        sx = i;
                        sy = j;
                    }
                }
            }
            // 搜索，人无事返回false，反之为true
            bool res = BFS(gx, gy, sx, sy, t);
            if (res) {
                cout << "No" << endl;
            } else {
                for (int i = 1; i <= N; i++) {
                    for (int j = 1; j <= M; j++) {
                        cout << matrix[i][j];
                    }
                    cout << endl;
                }
            }
        }
    }


    return 0;
}
