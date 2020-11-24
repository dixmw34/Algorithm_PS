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

map<pi, bool>m;

struct Water
{
	int a;
	int b;
	int time;
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int full_a, full_b, x, y;

	cin >> full_a >> full_b >> x >> y;

	queue<Water>q;
	q.push(Water{ 0, 0, 0 });
	m[pi(0, 0)] = true;
	while (!q.empty()) {
		Water w = q.front(); q.pop();
		if (w.a == x && w.b == y) {
			cout << w.time << '\n';
			return 0;
		}

		if (m.find(pi(full_a, w.b)) == m.end()) {
			m[pi(full_a, w.b)] = true;
			q.push(Water{ full_a, w.b, w.time + 1 });
		}
		if (m.find(pi(0, w.b)) == m.end()) {
			m[pi(0, w.b)] = true;
			q.push(Water{ 0, w.b, w.time + 1 });
		}
		if (m.find(pi(max(0, w.a + w.b - full_b), min(w.a + w.b, full_b))) == m.end()) {
			m[pi(max(0, w.a + w.b - full_b), min(w.a + w.b, full_b))] = true;
			q.push(Water{ max(0, w.a + w.b - full_b),min(w.a + w.b, full_b), w.time + 1 });
		}

		if (m.find(pi(w.a, full_b)) == m.end()) {
			m[pi(w.a, full_b)] = true;
			q.push(Water{ w.a, full_b, w.time + 1 });
		}
		if (m.find(pi(w.a, 0)) == m.end()) {
			m[pi(w.a, 0)] = true;
			q.push(Water{ w.a, 0, w.time + 1 });
		}
		if (m.find(pi(min(w.a + w.b, full_a), max(0, w.a + w.b - full_a))) == m.end()) {
			m[pi(min(w.a + w.b, full_a), max(0, w.a + w.b - full_a))] = true;
			q.push(Water{ min(w.a + w.b, full_a), max(0, w.a + w.b - full_a), w.time + 1 });
		}
	}

	cout << -1 << '\n';


	return 0;
}