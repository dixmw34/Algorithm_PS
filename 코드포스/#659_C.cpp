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
#include <climits>

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

vector<vector<int>>arr(26);
vector<bool>visit;

void dfs(int start) {
	for (int i = 0; i < arr[start].size(); i++) {
		if (!visit[arr[start][i]]) {
			visit[arr[start][i]] = true;
			dfs(arr[start][i]);
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		bool impossible = false;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				impossible = true;
				break;
			}
			else if (a[i] < b[i]) {
				arr[a[i] - 'a'].push_back(b[i] - 'a');
				arr[b[i] - 'a'].push_back(a[i] - 'a');
			}
		}
		if (impossible)cout << -1 << '\n';
		else {
			visit = vector<bool>(26, false);
			int ans = 26;
			for (int i = 0; i < 26; i++) {
				if (!visit[i]) {
					visit[i] = true;
					dfs(i);
					ans--;
				}
			}
			cout << ans << '\n';
		}
		for (int i = 0; i < 26; i++)arr[i].clear();
	}

	return 0;

}