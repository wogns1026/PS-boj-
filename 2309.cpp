#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int arr[10];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < (1 << 9); i++) {
		int cnt = 0, sum = 0;
		for (int j = 0; j < 9; j++) {
			if (i & (1 << j)) {
				cnt++;
				sum += arr[j];
			}
		}
		if (cnt == 7) {
			if (sum == 100) {
				for (int j = 0; j < 9; j++) {
					if (i & (1 << j)) {
						cout << arr[j] << '\n';
					}
				}
				return 0;
			}
		}
	}

	return 0;
}