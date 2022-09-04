#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
	
    int L, M;
    while (cin >> L >> M) {
        vector<int> trees(L+1, 1);
        while (M--) {
            int a, b;
            cin >> a >> b;
            for (int i = a; i <= b; i++) {
                trees[i] = 0;
            }
        }
        cout << accumulate(trees.begin(), trees.end(), 0) << endl;
    }

	return 0;

}