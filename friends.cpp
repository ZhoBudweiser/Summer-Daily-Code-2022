#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
	
    int n, m;
    while (cin >> n >> m) {
        unordered_map<int, int> mp;
        vector<int> index;
        while (n--) {
            int book;
            cin >> book;
            index.push_back(book);
            mp[book]++;
        }
        for (int i = 0; i < index.size(); i++) {
            if (mp[index[i]]-1) {
                cout << mp[index[i]]-1 << endl;
            } else {
                cout << "BeiJu" << endl;
            }
        }
    }

	return 0;

}