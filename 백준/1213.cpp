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
#include <string.h>
#include <iomanip>

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

	string s, ans = "";
	cin >> s;
	vector<int>arr(26, 0);
	for (int i = 0; i < s.size(); ++i) {
		arr[s[i] - 'A']++;
	}
	char ch = ' ';
	for (int i = 0; i < 26; ++i) {
		while (arr[i]) {
			if (arr[i] == 1) {
				if (ch != ' ') {
					cout << "I'm Sorry Hansoo\n";
					return 0;
				}
				else ch = 'A' + i;
				--arr[i];
			}
			else {
				ans += 'A' + i;
				arr[i] -= 2;
			}
		}
	}

	if (ch == ' ') {
		cout << ans;
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	else {
		cout << ans << ch;
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}


	return 0;

}