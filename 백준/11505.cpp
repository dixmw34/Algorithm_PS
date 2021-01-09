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
#include<cassert>

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

const ll Mod = 1000000007;
ll tree[4000000], num[1000000];

ll init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = num[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2)*init(mid + 1, end, node * 2 + 1)) % Mod;
}

ll update(int start, int end, int node, int idx) {
	if (idx<start || idx>end)return tree[node];
	if (start == end) {
		return tree[node] = num[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (update(start, mid, node * 2, idx)*update(mid + 1, end, node * 2 + 1, idx)) % Mod;
}

ll mul(int start, int end, int node, int left, int right) {
	if (right<start || left>end)return 1LL;
	if (start>=left && end<=right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return (mul(start, mid, node * 2, left, right)*mul(mid + 1, end, node * 2 + 1, left, right)) % Mod;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	init(0, n - 1, 1);
	while (m + k) {
		cin >> a >> b >> c;
		if (a == 1) {
			num[b - 1] = (ll)c;
			update(0, n - 1, 1, b - 1);
		}
		else {
			if (b > c) 
				cout << mul(0, n - 1, 1, c - 1, b - 1) << '\n';
			else
				cout << mul(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
		m--;
	}
	

	return 0;
}