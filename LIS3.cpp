# include<iostream>
# include<vector>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        vector<int> nums;
        vector<int> dpd(N, 1);
        vector<int> dpi(N, 1);
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            nums.emplace_back(num);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dpi[i] = max(dpi[i], 1 + dpi[j]);
                }
            }
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = nums.size()-1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    dpd[i] = max(dpd[i], 1 + dpd[j]);
                }
            }
        }
        for (int i = nums.size()-1; i >= 0; i--) {
                ans = max(ans, dpd[i]+dpi[i]-1);
        }
        cout << N-ans << endl;
    }
    return 0;
}