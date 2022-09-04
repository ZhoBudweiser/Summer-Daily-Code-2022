# include<iostream>
# include<cstring>
using namespace std;

int dp[1005][1005];
int w[1005];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int s, n;
    while (cin >> s >> n) {
        for (int i = 1; i <= n; i++) {
            int we;
            cin >> we;
            w[i] = we;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                if (dp[i-1][j] == 1) dp[i][j] = 1;
                if (j-w[i]>=0 && dp[i-1][j-w[i]] == 1) dp[i][j] = 1;
            }
        }
        if (dp[n][s] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}