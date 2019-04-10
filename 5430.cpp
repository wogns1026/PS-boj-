#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <deque>

using namespace std;

int t, n;
string p, s;
deque<int> v;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> p >> n;
		v.clear();
		int plen = p.length();
		cin >> s;
		int slen = s.length();
		string mid;
		int num = 0;
		for (int i = 1; i < slen; i++) {
			if (s[i] == ',') {
				num = stoi(mid);
				v.push_back(num);
				mid.clear();
			}
			else if (i == slen - 1) {
				if (mid.empty()) {
					continue;
				}
				num = stoi(mid);
				v.push_back(num);
				mid.clear();
			}
			else {
				mid += s[i];
			}
		}
		bool flag = false;
		int chk = 0;
		for (int i = 0; i < plen; i++) {
			if (p[i] == 'R') {
				if (chk == 0)
					chk = 1;
				else
					chk = 0;
			}
			else {
				if (v.empty()) {
					flag = true;
					cout << "error\n";
					break;
				}
				else {
					if (chk == 0) {
						v.pop_front();
					}
					else {
						v.pop_back();
					}
				}
			}
		}
		if (!flag) {
			if (chk == 0) {
				cout << '[';
				for (int i = 0; i < v.size(); i++) {
					if (i != v.size() - 1)
						cout << v[i] << ',';
					else
						cout << v[i];
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				for (int i = v.size() - 1; i >= 0; i--) {
					if (i != 0)
						cout << v[i] << ',';
					else
						cout << v[i];
				}
				cout << "]\n";
			}
			
		}
	}

	return 0;
}