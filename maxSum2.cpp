# include<iostream>
# include<vector>
using namespace std;

vector<long long> nums;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        if (0 == N) {
            break;
        }
        nums.clear();
        bool isNeg = true;
        while (N--) {
            long long num;
            cin >> num;
            if (num>=0)
                isNeg = false;
            nums.emplace_back(num);
        }
        if (isNeg) {
            cout << 0 << " " << nums[0] << " " << nums[nums.size()-1] << endl;
            continue;
        }
        int s = 0, e = 0;
        long long ans = nums[0];
        long long temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            temp = max(temp+nums[i], nums[i]);
            if (temp > ans) {
                ans = temp;
                s = e = i;
            }
        }
        int now = ans - nums[s];
        while (now) now -= nums[--s];
        cout << ans << " " << nums[s] << " " << nums[e] << endl;
    }
    return 0;
}