# include<iostream>
# include<queue>
using namespace std;

int N, M;
char matrix[105][105];
int direct[4][2] {0, 1, 1, 0, -1, 0, 0, -1};

struct Node {
    int x, y;
};

bool BFS(int gx, int gy, int t) {
    queue<Node> qg;
    qg.push(Node{gx, gy});
    while (t && !qg.empty()) {
        int gSize = qg.size();
        while (gSize--) {
            Node g = qg.front();
            qg.pop();
            for (int i = 0; i < 4; i++) {
                int ngx = g.x + direct[i][0];
                int ngy = g.y + direct[i][1];
                if (1 <= ngx && ngx <= N && 1 <= ngy && ngy <= M) {
                    if (matrix[ngx][ngy] == '.') {
                        matrix[ngx][ngy] = '#';
                        qg.push(Node{ngx, ngy});
                    }
                }
            }
        }
        t--;
    }

    return qg.empty() && t > 0;
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int t;
    while (cin >> N >> M >> t) {
        // memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                matrix[i][j+1] = s[j];
            }
        }
        int gx, gy, sx, sy;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (matrix[i][j] == '*') {
                    matrix[i][j] = '#';
                    gx = i;
                    gy = j;
                    break;
                }
            }
        }
        bool res = BFS(gx, gy, t);
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
        cout << endl;
    }



    return 0;
}
