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

	int t;
	cin >> t;
	while (t--) {
		int n, k, l;
		cin >> n >> k >> l;
		vector<int>a(n + 1), b(1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] + k <= l)b.push_back(i);
		}
		b.push_back(n + 1);
		bool flag = true;
		for (int i = 1; i < b.size(); ++i) {
			int now = b[i - 1] + 1, depth = k;
			bool up = true;
			while (now < b[i]) {
				if (up)depth--;
				else depth++;
				if (up && a[now] + depth > l) {
					depth = l - a[now];
				}
				if (depth<0 || a[now] + depth > l) {
					flag = false;
					break;
				}
				if (depth == 0)up = false;
				now++;
			}
			if (!flag)break;
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
		
	}


	return 0;

}