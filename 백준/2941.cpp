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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	map<string, int>m;
	m["c="] = m["c-"] = m["dz="] = m["d-"] = m["lj"] = m["nj"] = m["s="] = m["z="] = 1;

	string a;
	
	cin >> a;

	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (i + 2 < a.size() && m[a.substr(i, 3)]) {
			i += 2;
		}
		else if (i + 1 < a.size() && m[a.substr(i, 2)]) {
			++i;
		}
		ans++;
	}
	cout << ans << '\n';

	return 0;

}