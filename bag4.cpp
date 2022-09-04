# include<iostream>
using namespace std;

int dp[1005];
int w[10005];
int v[10005];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n, val;
    while (cin >> n >> val) {
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }
        for (int j = 0; j <= val; j++) {
            dp[j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= val; j++) {
                // if (j >= w[i])
                    dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
                // else
                    // dp[i][j] = dp[i-1][j];
            }
        }
        cout << dp[val] << endl;
    }

    return 0;
}
