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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

const int MAX = 1e9 + 7;

vector<ll>arr;
vector<ll>sum;

ll make(int start, int end, int node) {
	if (start == end)return sum[node] = arr[start];
	else if (start > end)return 0;

	int mid = (start + end) / 2;
	ll num1 = make(start, mid, node * 2);
	ll num2 = make(mid + 1, end, node * 2 + 1);
	return sum[node] = num1 +num2;
}

ll find(int start, int end, int node, int left, int right) {
	if (start >= left && end <= right)return sum[node];
	else if (start > end || right<start || left>end)return 0;

	int mid = (start + end) / 2;
	return find(start, mid, node * 2, left, right) + find(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, ll dif) {
	if (idx<start || idx>end)return;
	sum[node] += dif;
	if (start == end)return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
	return;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, x, y;
	ll a, b;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	sum = vector<ll>(4 * n);

	make(0, n - 1, 1);

	while (m--) {
		cin >> x >> y >> a >> b;
		if (x > y)swap(x, y);
		cout << find(0, n - 1, 1, x-1, y-1) << '\n';
		ll num = b - arr[a - 1];
		arr[a - 1] = b;
		update(0, n - 1, 1, a - 1, num);
	}


	return 0;
	

}