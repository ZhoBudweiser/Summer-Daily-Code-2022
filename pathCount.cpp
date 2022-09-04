#include <bits/stdc++.h>
using namespace std;

bool matrix[1005][1005];
int dp[1005][1005];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N, M;
    while (cin >> N >> M) {
        memset(matrix, false, sizeof(matrix));
        memset(dp, 0, sizeof(dp));
        while (M--) {
            int x, y;
            cin >> x >> y;
            matrix[x][y] = true;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!matrix[i][j]) {
                    if (i == 1 && j == 1) {
                        dp[i][j] = 1;
                    }else if (i == 1) {
                        dp[i][j] = dp[i][j-1];
                    } else if (j == 1) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 100003;
                    }
                }
            }
        }
        cout << dp[N][N] << endl;
    }

    return 0;
}