/*

간단히 set<string>을 사용하여 풀 수 있다.
하지만 hashtable을 사용하여 풀어보았다.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue> 

#define tblsz 400007
#define a 524287
#define b 131071

using namespace std;

int n, m;
char arr[10001][501];
char sr[501];
int hashtable[tblsz];

int hashfunc(char *str) {
	int val = 0;
	int i = 0;
	while (str[i] != '\0') {
		int num = (a*(str[i] - '0') + b) % tblsz;
		val += num;
		val %= tblsz;
		i++;
	}
	return val;
}

int _strcmp(char *s1, char *s2) {
	int i = 0;
	while (s1[i] != '\0' || s2[i] != '\0') {
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return 0;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		int num = hashfunc(arr[i]);
		while (1) {
			if (hashtable[num] == 0) {
				hashtable[num] = i;
				break;
			}
			else {
				num++;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> sr;
		int num = hashfunc(sr);
		if (hashtable[num] == 0) {
			continue;
		}
		else {
			while (1) {
				if (_strcmp(arr[hashtable[num]], sr) == 0) {
					ans++;
					break;
				}
				else if (hashtable[num] == 0)
					break;
				else {
					num++;
				}
			}
		}
	}
	cout << ans << '\n';


	return 0;
}