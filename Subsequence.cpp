# include<iostream>
# include<vector>
using namespace std;

vector<int> nums;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int T;
    cin >> T;
    while (T--) {
        int n, s;
        while (cin >> n >> s) {
            nums.clear();
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                nums.emplace_back(num);
            }
            int i = 0, j = 0;
            int sum = 0;
            int ans = 0x7f7f7f7f;
            while (true)
            {
                while (j < n && sum < s) {
                    sum += nums[j++];
                }
                if (sum < s) {
                    break;
                }
                ans = min(ans, j-i);
                sum -= nums[i++];
            }
            if (ans != 0x7f7f7f7f) {
                cout << ans << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
