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

vector<ll>Tree;
vector<ll>arr;

ll init(int start, int end, int node) {
	if (start == end) return Tree[node] = arr[start];
	int mid = (start + end) / 2;
	return Tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int left, int right, int node) {
	if (left > end || right < start)return 0;
	else if (left <= start && right >= end)return Tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int idx, ll num, int node) {
	if (start == end) {
		if(start == idx)Tree[node] += num;
		return;
	}
	if (start <= idx && end >= idx) {
		Tree[node] += num;
		int mid = (start + end) / 2;
		update(start, mid, idx, num, node * 2);
		update(mid + 1, end, idx, num, node * 2 + 1);
	}
	return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	arr = vector<ll>(n);
	Tree = vector<ll>(4 * n);
	for (int i = 0; i < n; ++i)cin >> arr[i];

	init(0, n - 1, 1);

	int a, b;
	ll c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, n - 1, b - 1, c - arr[b - 1], 1);
			arr[b - 1] = c;
		}
		else {
			cout << sum(0, n - 1, b - 1, c - 1, 1) << '\n';
		}
	}


	return 0;

}