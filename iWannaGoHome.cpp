# include<iostream>
# include<vector>
# include<queue>
using namespace std;

struct Node
{
    int dst;
    int weight;
    bool operator < (const Node n) const {
        return weight > n.weight;
    }
};

int N, M;
const int MAXN = 605;
int nodes[MAXN][MAXN];
vector<int> part1;
vector<int> part2;
int dist[MAXN];
bool visit[MAXN];

void addEdge(int src, int dst, int weight) {
    if (nodes[src][dst] > weight) {
        nodes[src][dst] = weight;
        nodes[dst][src] = weight;        
    }
}

void Dijkstra(int src) {
    priority_queue<Node> q;
    dist[src] = 0;
    visit[src] = false;
    q.push(Node{src, 0});
    while (!q.empty()) {
        Node n = q.top();
        q.pop();
        visit[n.dst] = true;
        for (int i = 1; i <= N; i++) {
            if (nodes[n.dst][i] != INT32_MAX && !visit[i]) {
                if (dist[i] > dist[n.dst] + nodes[n.dst][i]) {
                    dist[i] = dist[n.dst] + nodes[n.dst][i];
                    q.push(Node{i, dist[i]});
                }
            }
        }
    }
    

}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while (cin >> N) {
        if (0 == N) {
            break;
        }
        part1.clear();
        part2.clear();
        for (int i = 0; i <= N; i++) {
            dist[i] = INT32_MAX;
            visit[i] = false;
            for (int j = 0; j <= N; j++) {
                nodes[i][j] = INT32_MAX;
            }
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            int A, B, T;
            cin >> A >> B >> T;
            if (A != B) {
                addEdge(A, B, T);
                addEdge(B, A, T);                
            }
        }
        for (int i = 1; i <= N; i++) {
            int part;
            cin >> part;
            if (1 == part) {
                part1.emplace_back(i);
            } else if (2 == part) {
                part2.emplace_back(i);
            }
        }
        for (int i = 0; i < part2.size(); i++) {
            int src = part2[i];
            for (int j = 0; j < part1.size(); j++) {
                int dst = part1[j];
                if (nodes[src][dst] != INT32_MAX) {
                    nodes[src][dst] = INT32_MAX;
                }
            }
        }
        Dijkstra(1);
        if (dist[2] != INT32_MAX)
            cout << dist[2] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
