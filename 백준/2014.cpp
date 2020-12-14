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

	int k, n;
	cin >> k >> n;
	vector<ll>p(k);
	priority_queue<ll>pq;
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
		pq.push(-p[i]);
	}
	while (--n) {
		ll now = -pq.top(); pq.pop();
		for (int i = 0; i < k; ++i) {
			if (now*p[i] <= INT_MAX)pq.push(-now * p[i]);
			if (now%p[i] == 0)break;
		}
	}

	cout << -pq.top() << '\n';

	return 0;
}