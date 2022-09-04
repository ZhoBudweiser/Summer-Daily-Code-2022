# include<iostream>
# include<cstring>
using namespace std;

int dp[105][105];

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    string s1, s2;
    while (cin >> s1 >> s2) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[s1.size()][s2.size()] << endl;
    }
    return 0;
}