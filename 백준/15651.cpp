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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<int>visit;
vector<int>v;
int n, m;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) {
			v.push_back(i + 1);
			visit[i]--;
			dfs(cnt + 1);
			visit[i]++;
			v.pop_back();
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	visit = vector<int>(n, m);

	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
		visit[i]--;
		dfs(1);
		visit[i]++;
		v.pop_back();
	}

	return 0;

}