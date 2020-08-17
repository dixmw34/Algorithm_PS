#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

const int MIN = -1e9 - 1;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b, end, now = 0, ans = 0;
	priority_queue<int>pq;
	vector<pi>arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back(pi(a, b));
	}
	cin >> end >> now;
	
	sort(arr.begin(), arr.end());
	int i = 0;

	while (1) {
		if (now >= end)break;
		for (; i < n && arr[i].first <= now; i++) {
			pq.push(arr[i].second);
		}
		if (pq.empty()) {
			cout << -1 << '\n';
			return 0;
		}
		now += pq.top();
		pq.pop();
		ans++;
	}

	cout << ans << '\n';


	return 0;

}