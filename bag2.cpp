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

    int M, N;
    while (cin >> M >> N) {
        for (int i = 1; i <= N; i++) {
            cin >> w[i] >> val[i];
        }
        vector<int> buys[1005];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (j-w[i] >= 0) {
                    if (dp[i-1][j-w[i]]+val[i] > dp[i-1][j]) {
                        dp[i][j] = dp[i-1][j-w[i]]+val[i];
                        buys[j] = buys[j-w[i]];
                        buys[j].emplace_back(i);
                    }
                    else 
                        dp[i][j] = max(dp[i-1][j-w[i]]+val[i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << dp[N][M] << endl;
        for (int i = 0; i < buys[M].size(); i++)
            cout << buys[M][i] << " ";
        cout << endl;
    }

    return 0;
}