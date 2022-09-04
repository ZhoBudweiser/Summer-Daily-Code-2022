# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

const int MAXN = 105;
int matrix[MAXN][MAXN];
int dist[MAXN];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        if (0 == N) {
            break;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                matrix[i][j] = INT32_MAX;
            }
        }
        for (int i = 0; i < N*(N-1)/2; i++) {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            matrix[src][dst] = weight;
            matrix[dst][src] = weight;
        }
        int cost = 0;
        bool noTree = false;
        for (int i = 1; i <= N; i++) {
            dist[i] = matrix[1][i];
        }
        dist[1] = 0;
        for (int i = 1; i < N; i++) {
            int minDist = INT32_MAX;
            int minPos = -1;
            for (int j = 1; j <= N; j++) {
                if (minDist > dist[j] && dist[j]) {
                    minDist = dist[j];
                    minPos = j;
                }
            }
            if (minPos == -1) {
                noTree = true;
                break;
            }
            cost += minDist;
            for (int j = 1; j <= N; j++) {
                if (dist[j] > matrix[minPos][j])
                    dist[j] = matrix[minPos][j];
            }
            dist[minPos] = 0;
        }
        if (noTree) cout << "?" << endl;
        else cout << cost << endl;
    }

    return 0;
}
