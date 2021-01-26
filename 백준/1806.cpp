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
#include <cassert>

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

	int ans = INF;
	int n, s, a, sum = 0;

	cin >> n >> s;
	queue<int>q;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		sum += a;
		q.push(a);
		while (sum >= s) {
			ans = min(ans, (int)q.size());
			sum -= q.front(); q.pop();
		}
	}

	if (ans == INF) {
		cout << 0 << '\n';
	}
	else
		cout << ans << '\n';

	
	

	return 0;
}