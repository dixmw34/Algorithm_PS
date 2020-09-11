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

bool sol(string a) {
	vector<bool>arr(26, 0);
	char ch = ' ';
	for (int i = 0; i < a.size(); ++i) {
		if (ch != a[i]) {
			ch = a[i];
			if (arr[ch - 'a'])return false;
			arr[ch - 'a'] = true;
		}
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, ans = 0;
	string a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (sol(a))ans++;
	}
	cout << ans << '\n';

	return 0;

}