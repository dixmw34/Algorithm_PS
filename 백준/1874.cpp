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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, a[100000], idx = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];

	stack<int>s; vector<char>ans;
	for (int i = 0; i < n; ++i) {
		s.push(i + 1);
		ans.push_back('+');
		while (!s.empty() && s.top() == a[idx]) {
			s.pop();
			idx++;
			ans.push_back('-');
		}
	}

	if (!s.empty())cout << "NO\n";
	else {
		for (int i = 0; i < ans.size(); ++i)cout << ans[i] << '\n';
	}
	

	return 0;

}