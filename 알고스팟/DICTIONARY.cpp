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

const int Max = 26;
int inDegree[26];
vector<vector<int>>arr(26);


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {

		memset(inDegree, 0, sizeof(inDegree));
		for (int i = 0; i < Max; ++i)arr[i].clear();

		int n;
		cin >> n;
		vector<string>s(n);
		for (int i = 0; i < n; ++i)cin >> s[i];
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < min(s[i].size(), s[i + 1].size()); ++j) {
				if (s[i][j] != s[i + 1][j]) {
					inDegree[s[i + 1][j] - 'a']++;
					arr[s[i][j]-'a'].push_back(s[i + 1][j] - 'a');
					break;
				}
			}
		}
		queue<int>q; vector<char>ans;
		for (int i = 0; i < Max; ++i) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int num = q.front(); q.pop();
			ans.push_back((char)(num + 'a'));
			for (int i = 0; i < arr[num].size(); ++i) {
				if (--inDegree[arr[num][i]] == 0)q.push(arr[num][i]);
			}
		}

		if (ans.size() == Max) {
			for (int i = 0; i < ans.size(); ++i)cout << ans[i];
			cout << '\n';
		}
		else cout << "INVALID HYPOTHESIS\n";
	}

	

	return 0;

}