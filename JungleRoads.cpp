# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

const int MAXN = 105;
struct Node
{
    int src, dst;
    int weight;
};

vector<Node> edges;

int cities[MAXN];

bool cmp(Node n1, Node n2) {
    return n1.weight < n2.weight;
}

int find(int x) {
    if (x == cities[x]) return x;
    cities[x] = find(cities[x]);
    return cities[x];
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N, M;
    while (cin >> N) {
        if (0 == N) {
            break;
        }
        for (int i = 1; i <= N; i++) {
            cities[i] = i;
        }
        edges.clear();
        while (N > 1) {
            N--;
            char src;
            int num;
            cin >> src >> num;
            while (num--) {
                char dst;
                int cost;
                cin >> dst >> cost;
                edges.emplace_back(Node{src, dst, cost});
            }
        }
        int cost = 0;
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < edges.size(); i++) {
            int fa = find(edges[i].src-'A');
            int fb = find(edges[i].dst-'A');
            if (fa != fb) {
                cities[fa] = fb;
                cost += edges[i].weight;
            }
        }
        cout << cost << endl;
    }

    return 0;
}
