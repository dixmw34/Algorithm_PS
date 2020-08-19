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

	string s;
	string result = "";
	cin >> s;
	int a = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') {
			a++;
		}
		else {
			if (a % 2) {
				cout << -1 << '\n';
				return 0;
			}
			if (a % 4) {
				for (int j = 0; j < a-2; j++) {
					result += 'A';
				}
				result += "BB";
			}
			else {
				for (int j = 0; j < a; j++) {
					result += 'A';
				}
			}
			result += s[i];
			a = 0;
		}
	}

	if (a > 0) {
		if (a % 2) {
			cout << -1 << '\n';
			return 0;
		}
		if (a % 4) {
			for (int j = 0; j < a - 2; j++) {
				result += 'A';
			}
			result += "BB";
		}
		else {
			for (int j = 0; j < a; j++) {
				result += 'A';
			}
		}
	}

	cout << result << '\n';

	return 0;

}