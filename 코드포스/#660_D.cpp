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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	ll ans = 0;
	cin >> n;
	vector<ll>a(n);
	vector<int>b(n);
	vector<int>inDegree(n, 0);

	for (int i = 0; i < n; i++)cin >> a[i];

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (--b[i] >= 0)inDegree[b[i]]++;
	}
	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0)q.push(i);
	}
	queue<int>pos;
	stack<int>neg;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans += a[now];
		if (a[now] >= 0) {
			pos.push(now);
			if (b[now] >= 0) {
				a[b[now]] += a[now];
				if(--inDegree[b[now]] == 0)q.push(b[now]);
			}
		}
		else {
			neg.push(now);
			if (b[now] >= 0 && --inDegree[b[now]] == 0) {
				q.push(b[now]);
			}
		}
	}

	cout << ans << '\n';
	while (!pos.empty()) {
		cout << pos.front() + 1 << ' ';
		pos.pop();
	}
	while (!neg.empty()) {
		cout << neg.top() + 1 << ' ';
		neg.pop();
	}
	cout << '\n';

	return 0;

}