# include<iostream>
# include<vector>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        vector<int> nums;
        vector<int> dp(N, 0);
        while (N--) {
            int num;
            cin >> num;
            nums.emplace_back(num);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], nums[i] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}