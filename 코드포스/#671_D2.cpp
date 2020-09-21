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

	int n, num;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		pq.push(num);
	}

	vector<int>ans(n);
	int result = 0;

	for (int i = 0; i < (n+1) / 2; ++i) {
		ans[2 * i] = pq.top();
		pq.pop();
	}
	
	for (int i = 0; i < n  / 2; ++i) {
		ans[2 * i + 1] = pq.top();
		pq.pop();
	}

	for (int i = 1; i < n; i += 2) {
		if (i + 1 < n && ans[i - 1] > ans[i] && ans[i + 1] > ans[i])result++;
	}

	cout << result << '\n';
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;

}