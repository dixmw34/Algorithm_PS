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

int par[10000], enemy[10000], num[10000];

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

int merge(int a, int b) {
	if (a == -1 || b == -1)
		return max(a, b);
	a = find(a), b = find(b);
	if (a == b)
		return a;
	if (a > b)
		swap(a, b);
	par[b] = a;
	num[a] += num[b];
	num[b] = 0;
	return a;
}

bool ack(int a, int b) {

	a = find(a), b = find(b);
	int ea = (enemy[a] == -1 ? -1 : find(enemy[a]));
	int eb = (enemy[b] == -1 ? -1 : find(enemy[b]));

	if (a == eb || b == ea)
		return false;

	int x = merge(a, b);
	int y = merge(ea, eb);
	enemy[x] = y;
	if (y != -1)enemy[y] = x;
	return true;
}

bool dis(int a, int b) {

	a = find(a), b = find(b);
	int ea = (enemy[a] == -1 ? -1 : find(enemy[a]));
	int eb = (enemy[b] == -1 ? -1 : find(enemy[b]));

	if (a == b || (ea != -1 && ea == eb))
		return false;

	int x = merge(a, eb);
	int y = merge(ea, b);
	enemy[x] = y;
	enemy[y] = x;
	return true;
}

int sum(int n) {
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (par[i] != i)
			continue;
		if (enemy[i] == -1) {
			result += num[i];
		}
		else {
			if (enemy[i] > i)
				continue;
			result += max(num[i], num[enemy[i]]);
		}
	}
	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(enemy, -1, sizeof(enemy));
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			num[i] = 1;
		}
		string s;
		int a, b, ans = INF;
		for (int i = 1; i <= m; ++i) {
			cin >> s >> a >> b;
			bool flag = true;
			if (s == "ACK") {
				flag = ack(a, b);
			}
			else {
				flag = dis(a, b);
			}
			if (!flag) {
				ans = min(ans, i);
			}
		}
		if (ans == INF) {
			cout << "MAX PARTY SIZE IS " << sum(n) << '\n';
		}
		else {
			cout << "CONTRADICTION AT " << ans << '\n';
		}
	}

	

	return 0;
}