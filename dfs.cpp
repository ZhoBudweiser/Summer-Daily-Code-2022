# include<iostream>
# include<cstring>
using namespace std;

int matrix[105][105];
int dp[105][105];
int r, c;
int direct[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
};

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    int maxx = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        if (1 <= nx && nx <= r && 1 <= ny && ny <= c && matrix[nx][ny] < matrix[x][y]) {
            maxx = max(maxx, dfs(nx, ny)+1);
        }
    }
    dp[x][y] = maxx;
    return maxx;
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while (cin >> r >> c) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> matrix[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        cout << ans << endl;
    }

    return 0;
}