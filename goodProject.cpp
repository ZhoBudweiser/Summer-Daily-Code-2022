# include<iostream>
using namespace std;

int cities[1005];

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
        int sum = 0;
        cin >> M;
        for (int i = 1; i <= N; i++) cities[i] = i;
        while (M--) {
            int x, y;
            cin >> x >> y;
            int fx = find(x);
            int fy = find(y);
            if (fx != fy) {
                cities[fx] = fy;
                sum++;
            }
        }
        cout << N-1-sum << endl;
    }

    return 0;
}
