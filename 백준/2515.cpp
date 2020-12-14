#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, s;
	cin >> n >> s;
	vector<pi>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());

	int ans = 0, Max = 0;
	priority_queue<pi>pq;
	for (int i = 0; i < n; ++i) {
		while (!pq.empty() && -pq.top().first + s <= a[i].first) {
			Max = max(Max, pq.top().second);
			pq.pop();
		}
		ans = max(ans, a[i].second + Max);
		pq.push(pi(-a[i].first, a[i].second + Max));
	}
	cout << ans << '\n';

	return 0;
}