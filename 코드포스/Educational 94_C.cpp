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

	int t, x;
	string s;

	cin >> t;

	while (t--) {
		cin >> s >> x;
		bool check = true;
		int n = s.size();
		string result(n, '-');
		
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i >= x) {
					result[i - x] = '0';
				}
				if (i + x < n) {
					result[i + x] = '0';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				int num = 0;
				if (i >= x && result[i - x] != '0') {
					result[i - x] = '1';
					num++;
				}
				if (i + x < n && result[i + x] != '0') {
					result[i + x] = '1';
					num++;
				}
				if (num == 0) {
					check = false;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (result[i] == '-')result[i] = '1';
		}

		if (check)cout << result << '\n';
		else cout << -1 << '\n';

	}


	return 0;

}