# include<iostream>
# include<queue>
# include<vector>
using namespace std;

const int MAXN = 505;
int degree[MAXN];
vector<int> nodes[MAXN];
int N, M;

void topSort() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; i++) {
        if (!degree[i]) {
            q.push(i);
        }
    }
    bool first = true;
    while (!q.empty()) {
        int n = q.top();
        q.pop();
        if (first) {
            cout << n;
            first = false;
        } else {
            cout << " " << n;
        }
        for (int i = 0; i < nodes[n].size(); i++) {
            degree[nodes[n][i]]--;
            if (!degree[nodes[n][i]]) {
                q.push(nodes[n][i]);
            }
        }
    }
    cout << endl;
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while (cin >> N >> M) {
        for (int i = 0; i <= N; i++) {
            nodes[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int first, second;
            cin >> first >> second;
            nodes[first].emplace_back(second);
            degree[second]++;
        }
        topSort();
    }

    return 0;
}
