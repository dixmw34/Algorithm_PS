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

vector<int>arr;
vector<int>big;
vector<int>small;

int make_big(int start, int end, int node) {
	if (start == end)return big[node] = arr[start];
	else if (start > end)return 0;

	int mid = (start + end) / 2;
	int num1 = make_big(start, mid, node * 2);
	int num2 = make_big(mid + 1, end, node * 2 + 1);
	return big[node] = max(num1, num2);
}

int find_big(int start, int end, int node, int left, int right) {
	if (start >= left && end <= right)return big[node];
	else if (start > end || right<start || left>end)return 0;

	int mid = (start + end) / 2;
	return max(find_big(start, mid, node * 2, left, right), find_big(mid + 1, end, node * 2 + 1, left, right));
}

int make_small(int start, int end, int node) {
	if (start == end)return small[node] = arr[start];
	else if (start > end)return MAX;

	int mid = (start + end) / 2;
	int num1 = make_small(start, mid, node * 2);
	int num2 = make_small(mid + 1, end, node * 2 + 1);
	return small[node] = min(num1, num2);
}

int find_small(int start, int end, int node, int left, int right) {
	if (start >= left && end <= right)return small[node];
	else if (start > end || right<start || left>end)return MAX;

	int mid = (start + end) / 2;
	return min(find_small(start, mid, node * 2, left, right), find_small(mid + 1, end, node * 2 + 1, left, right));
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	big = vector<int>(4 * n);
	small = vector<int>(4 * n);

	make_big(0, n - 1, 1);
	make_small(0, n - 1, 1);

	while (m--) {
		cin >> a >> b;
		cout << find_small(0, n - 1, 1, a - 1, b - 1) <<' '<< find_big(0, n - 1, 1, a - 1, b - 1) << '\n';
	}


	return 0;
	

}