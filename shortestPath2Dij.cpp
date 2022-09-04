# include<iostream>
# include<queue>
using namespace std;

const int MAXN = 105;
int father[MAXN];
int matrix[MAXN][MAXN];
int dist[MAXN];
bool visit[MAXN];
int N, M;

int find(int x) {
    if (x == father[x]) return x;
    father[x] = find(father[x]);
    return father[x];
}

void DFS(int src, int val) {
    dist[src] = val;
    visit[src] = true;
    for (int i = 0; i < N; i++) {
        if (matrix[src][i] != INT32_MAX && !visit[i]) {
            DFS(i, (dist[src]+matrix[src][i])%100000);
        }
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while (cin >> N >> M) {
        for (int i = 0; i <= N; i++) {
            father[i] = i;
            visit[i] = false;
            dist[i] = INT32_MAX;
            for (int j = 0; j <= N; j++) {
                matrix[i][j] = INT32_MAX;
            }
        }
        int length = 1;
        for (int i = 0; i < M; i++) {
            int src, dst;
            cin >> src >> dst;
            int fx = find(src);
            int fy = find(dst);
            if (fx != fy) {
                father[fx] = fy;
                matrix[src][dst] = length;
                matrix[dst][src] = length;
            }
            length = length * 2 % 100000;
        }
        DFS(0, 0);
        for (int i = 1; i < N; i++) {
            cout << dist[i] % 100000 << endl;
        }
    }

    return 0;
}
