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

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		priority_queue<int>pq;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			pq.push(-a);
		}

		int ans = 0;
		while (pq.size() > 1) {
			a = -pq.top();
			pq.pop();
			a -= pq.top();
			pq.pop();
			ans += a;
			pq.push(-a);
		}
		cout << ans << '\n';
		
	}

	return 0;

}