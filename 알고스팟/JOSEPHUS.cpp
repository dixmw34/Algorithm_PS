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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n, k;
		cin >> n >> k;
		queue<int>q;
		for (int i = 1; i <= n; ++i)q.push(i);
		int test = 0;
		while (q.size() > 2) {
			if (test == 0) {
				q.pop();
				test = k - 1;
			}
			else {
				--test;
				q.push(q.front());
				q.pop();
			}
		}
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();

		cout << min(a, b) << ' ' << max(a, b) << '\n';

	}


	return 0;

}