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


ll num[1000000],tree[4000000];

ll sum(int start, int end, int node, int left, int right) {
	if (right<start || left>end)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll update(int start, int end, int node, int idx, ll dif) {
	if (start > idx || end < idx)
		return tree[node];
	if (start == end)
		return tree[node] = dif;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, idx, dif) + update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(num, 0, sizeof(num));
	memset(tree, 0, sizeof(tree));

	int n, m;
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c)swap(b, c);
			cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
		else {
			update(0, n - 1, 1, b - 1, (ll)c);
		}
	}
	

	return 0;
}