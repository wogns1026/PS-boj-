#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int n, arr[100001], num;
stack<int> s;
vector<char> v;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int idx = 0, num = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool flag = false;
	while (idx != n) {
		if (!s.empty()) {
			if (s.top() == arr[idx]) {
				v.push_back('-');
				s.pop();
				idx++;
			}
			else {
				if (num > n) {
					flag = true;
					break;
				}
				v.push_back('+');
				s.push(num);
				num++;
			}
		}
		else {
			if (num > n) {
				flag = true;
				break;
			}
			v.push_back('+');
			s.push(num);
			num++;
		}
	}
	if (flag)
		cout << "NO\n";
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}


	return 0;
}