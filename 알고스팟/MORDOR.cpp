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

int h[100000], small[400000], big[400000];

int init_small(int start, int end, int node) {
	if (start == end)return small[node] = h[start];

	int mid = (start + end) / 2;
	return small[node] = min(init_small(start, mid, node * 2), init_small(mid + 1, end, node * 2 + 1));
}

int find_small(int start, int end, int left, int right, int node) {
	if (left > end || right < start)return INT_MAX;
	if (left <= start && right >= end)return small[node];

	int mid = (start + end) / 2;
	return min(find_small(start, mid, left, right, node * 2), find_small(mid + 1, end, left, right, node * 2 + 1));
}

int init_big(int start, int end, int node) {
	if (start == end)return big[node] = h[start];

	int mid = (start + end) / 2;
	return big[node] = max(init_big(start, mid, node * 2), init_big(mid + 1, end, node * 2 + 1));
}

int find_big(int start, int end, int left, int right, int node) {
	if (left > end || right < start)return INT_MIN;
	if (left <= start && right >= end)return big[node];

	int mid = (start + end) / 2;
	return max(find_big(start, mid, left, right, node * 2), find_big(mid + 1, end, left, right, node * 2 + 1));
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; ++i)cin >> h[i];

		init_small(0, n - 1, 1);
		init_big(0, n - 1, 1);

		int a, b;
		while (q--) {
			cin >> a >> b;
			if (a == b) {
				cout << 0 << '\n';
				continue;
			}
			cout << find_big(0, n - 1, a, b, 1) - find_small(0, n - 1, a, b, 1) << '\n';
		}
	}

	return 0;

}