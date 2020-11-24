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

bool cmp(pi a, pi b) {
	if (a.second == b.second)return a.first > b.first;
	else return a.second < b.second;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, d;
	cin >> n;
	vector<pi>arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].first > arr[i].second)swap(arr[i].first, arr[i].second);
	}
	cin >> d;

	sort(arr.begin(), arr.end(), cmp);

	int test = 0, ans = 0, start = arr[0].second;
	int k = 0;
	priority_queue<int, vector<int>, greater<int>>pq;
	while (k < n) {
		int t = k;
		while (!pq.empty() && pq.top() < arr[k].second - d)pq.pop();
		while (t <= n) {
			if (t == n)break;
			if (arr[t].second != arr[k].second)break;
			if (arr[k].second - d <= arr[t].first)pq.push(arr[t].first);
			t++;
		}
		ans = max(ans, (int)pq.size());
		k = t;
	}
	cout << ans << '\n';


	return 0;
}