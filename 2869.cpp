#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
int a, b, v;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b >> v;
	ll l = 0, r = 1000000000;
	ll mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if ((mid - 1) * (a - b) + a >= v) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';

	return 0;
}