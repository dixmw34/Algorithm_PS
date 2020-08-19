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

bool result = true;
int p[100001]; //도시 인구수
int h[100001]; //행복지수
int a[100001]; //전체인구수
int hp[100001];//행복한 사람수
vector<vector<int>>arr(100001);

void dfs(int now, int anc) {

	int sub = 0;
	a[now] = p[now];

	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (next == anc)continue;
		dfs(next, now);
		sub += hp[next];
		a[now] += a[next];
	}

	if ((a[now] + h[now]) % 2)result = false;
	hp[now] = (a[now] + h[now]) / 2;
	if (hp[now] < sub)result = false;
	if (hp[now] < 0 || hp[now]>a[now])result = false;


}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a, b, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)cin >> p[i];
		for (int i = 1; i <= n; i++)cin >> h[i];
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		result = true;
		dfs(1, 0);
		if (result)cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <= n; i++) {
			arr[i].clear();
		}
	}

	return 0;

}