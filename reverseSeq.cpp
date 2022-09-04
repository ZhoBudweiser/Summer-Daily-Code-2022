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
        int oneNum = 0;
        N--;
        char ch;
        int temp = 1;
        int ans = 0;
        cin >> ch;
        if ('1' == ch) {
            oneNum++;
            temp = -1;
        } else if ('0' == ch) {
            nums.emplace_back(1);
            temp = 1;
        }
        while (N--) {
            char ch;
            int num = 1;
            cin >> ch;
            if ('1' == ch) {
                oneNum++;
                num = -1;
            } else if ('0' == ch) {
                num = 1;
            }
            temp = max(temp+num, num);
            if (temp > ans) {
                ans = temp;
            }
        }
        cout << ans+oneNum << endl;
    }
    return 0;
}