#include <iostream>
#include <vector>
#include <string>
using namespace std;

string divide(string s, int x, int &re) {
	int reminder = 0;
	for (int i = 0; i < s.size(); i++) {
		int cur = reminder*10 + s[i] - '0';
		s[i] = cur / x + '0';
		reminder = cur % x;
	}
	re = reminder;
	
	int pos = 0;
	while (s[pos] == '0') {
		pos++;
	}
	return s.substr(pos);

}

int main() {
	string s;
	while (cin >> s) {
		vector<int> res;
		int re;
		while (s != "") {
			s = divide(s, 2, re);
			res.emplace_back(re);
		}
		
		for (int i = res.size()-1; i >= 0; i--) {
			cout << res[i];
		}
		cout << endl;
		
	}
	return 0;

}