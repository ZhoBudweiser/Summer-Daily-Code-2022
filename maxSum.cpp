# include<iostream>
# include<vector>
using namespace std;

vector<long long> nums;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        nums.clear();
        while (N--) {
            long long num;
            cin >> num;
            nums.emplace_back(num);
        }
        long long ans = nums[0];
        long long temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            temp = max(temp+nums[i], nums[i]);
            if (temp > ans) {
                ans = temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}