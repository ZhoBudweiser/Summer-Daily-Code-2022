# include<iostream>
# include<vector>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);


    int n, s;
    while (cin >> n >> s) {
        vector<int> nums;
        vector<int> visit(s+1);
        int countVisit = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums.emplace_back(num);
        }
        int i = 0, j = 0;
        int a, b;
        int ans = 0x7f7f7f7f;
        while (true) {
            while (j < n && countVisit < s) {
                visit[nums[j]]++;
                if (visit[nums[j]] == 1)
                    countVisit++;
                j++;
            }
            if (countVisit < s) {
                break;
            }
            if (j-i < ans) {
                ans = j-i;
                a = i+1;
                b = j;
            }
            visit[nums[i]]--;
            if (!visit[nums[i]])
                countVisit--;
            i++;
        }
        if (ans != 0x7f7f7f7f) {
            cout << a << " " << b << endl;
        } else {
            cout << 0 << endl;
        }
    }


    return 0;
}
