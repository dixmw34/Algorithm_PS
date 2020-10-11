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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int par[1001];
int find(int x) {
	if (x == par[x])return x;
	return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, x, y, d;
	char gender[1001];
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> gender[i];
		par[i] = i;
	}
	priority_queue<pair<int, pi>>pq;
	while (m--) {
		cin >> x >> y >> d;
		if (gender[x] == gender[y])continue;
		pq.push(make_pair(-d, pi(x, y)));
	}
	int ans = 0, cnt = 0;
	while (!pq.empty()) {
		x = pq.top().second.first, y = pq.top().second.second, d = -pq.top().first; pq.pop();
		//if (gender[x] == gender[y])continue;
		x = find(x);  
		y = find(y);
		if (x != y) {
			ans += d;
			par[x] = par[y] = min(x, y);
			cnt++;
		}
	}

	if (cnt == n - 1)cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;

}