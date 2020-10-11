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

int A[52], temp[52], n;
vector<string>ans;

void sol(vector<int>arr) {

	string s = "";
	int size = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == 0)continue;
		s += " " + to_string(arr[i]);
		size++;
	}
	s = to_string(size) + s;
	ans.push_back(s);

	int idx = 0, start = n;
	for (int i = arr.size()-1; i >= 0; --i) {
		start -= arr[i];
		for (int j = 0; j < arr[i]; ++j) {
			temp[idx++] = A[start + j];
		}
	}

	for (int i = 0; i < n; ++i)A[i] = temp[i];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> A[i];

	

	for (int t = 0; t < n / 2; ++t) {
		int x, y;
		for (int i = 0; i < n; ++i) {
			if (A[i] == t + 1)x = i;
			else if (A[i] == n - t)y = i;
		}
		int a = x, b = y;
		if (x > y)swap(x, y);

		sol({ t, x + 1 - t, y - x - 1, n - y - t, t });

		if (a < b) {
			sol({ t,1, n - 2 - 2 * t,1,  t });
			
		}
		else {
			if (t != 0)sol({ t, n - 2 * t, t });
		}
		//cout << ans.size() << '\n';
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << '\n';
	}

	return 0;

}