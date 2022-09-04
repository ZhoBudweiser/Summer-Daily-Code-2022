#include<iostream>
#include<cstring>
using namespace std;

int nums[100005];

int main(){

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    string s;
    while (cin >> s) {
        int n = s.size();
        memset(nums, 0, sizeof(nums));
        if (s[0] == 'T') {
            nums[0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T') {
                nums[i] = nums[i-1] + 1;
            } else {
                nums[i] = nums[i-1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                ans += nums[i] * (nums[n-1] - nums[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}