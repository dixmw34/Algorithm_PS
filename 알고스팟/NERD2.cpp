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

map<int, int>m;

bool insert(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.end())return true;
	return it->second < y;
}
void remove(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.begin())return;
	it--;
	while (1) {
		if (it->second < y) {
			if (it == m.begin()) {
				m.erase(it);
				return;
			}
			map<int, int>::iterator jt = it;
			jt--;
			m.erase(it);
			it = jt;
		}
		else return;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n, a, b, ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			if (insert(a, b)) {
				remove(a, b);
				m.insert(pi(a, b));
			}
			ans += m.size();
		}
		cout << ans << '\n';
		m.clear();
	}
	

	return 0;

}