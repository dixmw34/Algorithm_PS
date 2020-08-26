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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, p, f, cnts, cntw, s, w;
	cin >> t;
	while (t--) {
		cin >> p >> f >> cnts >> cntw >> s >> w;
		int ans = 0;

		if (p > f)swap(p, f);
		if (s > w) {
			swap(s, w);
			swap(cnts, cntw);
		}

		for (int i = min(cnts, p / s); i >= 0; i--) {
			int pw = min((p - i * s) / w, cntw);
			int fs = min(f / s, cnts - i);
			int fw = min((f - fs * s) / w, cntw - pw);
			ans = max(i + pw + fs + fw, ans);
		}
		cout << ans << '\n';
	}


	return 0;

}