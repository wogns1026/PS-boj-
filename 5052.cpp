#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int t, n;
string s;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		int vsize = v.size();
		bool flag = false;
		for (int i = 0; i < vsize - 1; i++) {
			int vlen = v[i].length();
			bool chk = false;
			for (int j = 0; j < vlen; j++) {
				if (v[i][j] != v[i + 1][j]) {
					chk = true;
					break;
				}
			}
			if (!chk) {
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";

	}

	return 0;
}