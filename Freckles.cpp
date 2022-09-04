# include<iostream>
# include<vector>
# include<map>
# include<cmath>
# include<algorithm>
using namespace std;

const int MAXN = 105;
struct Node
{
    double x, y;
};

struct Edge
{
    int src, dst;
    double distance;
};

vector<Node> vn;
vector<Edge> ve;
int father[MAXN];

bool cmp(Edge e1, Edge e2) {
    return e1.distance < e2.distance;
}

int find(int x) {
    if (x == father[x]) return x;
    father[x] = find(father[x]);
    return father[x];
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n;
    while (cin >> n) {
        vn.clear();
        ve.clear();
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            vn.emplace_back(Node{x, y});
        }
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        for (int i = 0; i < n-1; i++) {
            double x1 = vn[i].x;
            double y1 = vn[i].y;
            for (int j = i+1; j < n; j++) {
                double x2 = vn[j].x;
                double y2 = vn[j].y;
                double weight = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                ve.emplace_back(Edge{i, j, weight});
            }
        }
        sort(ve.begin(), ve.end(), cmp);
        double cost = 0.0;
        for (int i = 0; i < ve.size(); i++) {
            int fa = find(ve[i].src);
            int fb = find(ve[i].dst);
            if (fa != fb) {
                father[fa] = fb;
                cost += ve[i].distance;
            }
        }
        printf("%.2f\n", cost);
    }

    return 0;
}
