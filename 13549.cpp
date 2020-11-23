#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> PI;
int n, k;
int visit[100001];
priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    memset(visit, -1, sizeof(visit));
    visit[n] = 0;
    pq.push({ 0, n });
    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curSec = pq.top().first;
        pq.pop();
        if (curNode * 2 <= 100000 && visit[curNode * 2] == -1) {
            pq.push({ curSec, curNode * 2 });
            visit[curNode * 2] = curSec;
        }
        if (curNode + 1 <= 100000 && visit[curNode + 1] == -1) {
            pq.push({ curSec + 1, curNode + 1 });
            visit[curNode + 1] = curSec + 1;
        }
        if (curNode - 1 >= 0 && visit[curNode - 1] == -1) {
            pq.push({ curSec + 1, curNode - 1 });
            visit[curNode - 1] = curSec + 1;
        }
    }
    cout << visit[k] << '\n';

    return 0;
}