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

	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];

	vector<int>up;
	for (int i = 0; i < n; ++i) {
		if (up.empty() || up.back() < a[i])up.push_back(a[i]);
		else {
			int idx = lower_bound(up.begin(), up.end(), a[i]) - up.begin();
			up[idx] = a[i];
		}
	}

	cout << n - up.size() << '\n';



	return 0;

}