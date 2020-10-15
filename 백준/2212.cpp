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
	cin.tie(NULL); std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];

	if (n <= k) {
		cout << 0 << '\n';
		return 0;
	}

	sort(a.begin(), a.end());
	priority_queue<int>pq;
	for (int i = 1; i < n; ++i)pq.push(a[i] - a[i - 1]);
	k--;
	while (k--)pq.pop();

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << '\n';
	

	return 0;

}