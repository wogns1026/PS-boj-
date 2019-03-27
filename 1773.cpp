/*

시간복잡도 계산이 재미있는 문제
시간복잡도 = n * (1 + 1/2 + 1/3 + ... + 1/n)

(1 + 1/2 + 1/3 + ... + 1/n) 이러한 꼴은 조화급수라 함
= log(n + 1) 정도라고 할 수 있다고 한다.
따라서 이 알고리즘의 시간복잡도 = O(nlogn)

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, c, num, arr[2000001];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> num;
		int idx = 1;
		while (1) {
			if (num * idx > c)
				break;
			arr[num * idx] = 1;
			idx++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= c; i++) {
		if (arr[i])
			ans++;
	}
	cout << ans << '\n';
	
	return 0;
}