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
#include <climits>

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


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, a;
	cin >> n;
	deque<int>dq;
	for (int i = 1; i <= n; ++i)dq.push_back(i);

	cin >> m;
	int ans = 0;
	while (m--) {
		cin >> a;
		int i = 0;
		for (; i < dq.size(); ++i) {
			if (dq[i] == a)break;
		}
		ans += min(i, (int)dq.size() - i);
		while (i--) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		dq.pop_front();
	}
	cout << ans << '\n';

	return 0;

}