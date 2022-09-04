# include<iostream>
# include<vector>
# include<cstring>
using namespace std;

int dp[105][1005];
int w[1005];
int val[1005];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int T, M;
    while (cin >> T >> M) {
        for (int i = 1; i <= M; i++) {
            cin >> w[i] >> val[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= T; j++) {
                if (j-w[i] >= 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+val[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << dp[M][T] << endl;
    }

    return 0;
}