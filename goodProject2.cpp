# include<iostream>
# include<algorithm>
using namespace std;

const int MAXN = 105;
struct Node
{
    int src, dst;
    int weight;
}edges[MAXN];

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
        cin >> M;
        if (N < M-1) {
            cout << "?" << endl;
            break;
        }
        for (int i = 0; i < N; i++) {
            cin >> edges[i].src >> edges[i].dst >> edges[i].weight;
            cities[i+1] = i+1;
        }
        int total = 0;
        int cost = 0;
        sort(edges, edges+N, cmp);
        for (int i = 0; i < N; i++) {
            int fa = find(edges[i].src);
            int fb = find(edges[i].dst);
            if (fa != fb) {
                cities[fa] = fb;
                total++;
                cost += edges[i].weight;
            }
        }
        if (total != M-1)
            cout << "?" << endl;
        else
            cout << cost << endl;
    }

    return 0;
}
