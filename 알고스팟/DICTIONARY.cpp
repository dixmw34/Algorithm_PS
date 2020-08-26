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

vector<vector<int>>link(26);
vector<int>inDegree;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		inDegree = vector<int>(26);

		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
				if (a[i][j] != a[i + 1][j]) {
					link[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
					inDegree[a[i + 1][j] - 'a']++;
					break;
				}
			}
		}

		queue<char>ans;
		queue<int>q;
		for (int i = 0; i < 26; i++) {
			if (inDegree[i] == 0)q.push(i);
		}

		while (!q.empty()) {
			int num = q.front(); q.pop();
			ans.push(num + 'a');

			for (int i = 0; i < link[num].size(); i++) {
				if (--inDegree[link[num][i]] == 0)q.push(link[num][i]);
			}
		}

		if (ans.size() == 26) {
			while (!ans.empty()) {
				cout << ans.front();
				ans.pop();
			}
			cout << '\n';
		}
		else {
			cout << "INVALID HYPOTHESIS\n";
		}
		for (int i = 0; i < 26; i++) link[i].clear();
		inDegree.clear();
	}


	return 0;

}