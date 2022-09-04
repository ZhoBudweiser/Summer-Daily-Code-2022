# include<iostream>
# include<vector>
# include<queue>
using namespace std;

struct Edge
{
    int src, dst;
    int weight;
};

const int MAXN = 105;

vector<Edge> edges;
vector<int> nodes[MAXN];
int dist[MAXN];
bool visit[MAXN];

void addEdge(int src, int dst, int weight) {
    edges.emplace_back(Edge{src, dst, weight});
    nodes[src].emplace_back(edges.size()-1);
}

void SPFA(int src) {
    queue<int> q;
    q.push(src);
    visit[src] = true;
    dist[src] = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        visit[n] = true;
        for (int i = 0; i < nodes[n].size(); i++) {
            Edge& e = edges[ nodes[n][i] ];
            if (dist[e.dst] > dist[e.src] + e.weight) {
                dist[e.dst] = dist[e.src] + e.weight;
                // if (!visit[e.dst]) {
                //     q.push(e.dst);
                // }
                q.push(e.dst);
            }
        }
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N, M;
    while (cin >> N >> M) {
        if (0 == N && 0 == M) {
            break;
        }
        edges.clear();
        for (int i = 0; i <= N; i++) {
            dist[i] = INT32_MAX;
            visit[i] = false;
            nodes[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            addEdge(src, dst, weight);
            addEdge(dst, src, weight);
        }
        SPFA(1);
        cout << dist[N] << endl;
    }

    return 0;
}
