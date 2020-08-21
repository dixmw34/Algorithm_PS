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

	int t;
	string s;

	cin >> t;
	while (t--) {
		cin >> s;
		bool check = true;
		int num = 1;
		int left = 0, right = s.size() - 1;

		while (left < right) {
			if (s[left] != s[right]) {
				if (num == 0)break;
				num--;
				if (s[left + 1] == s[right]) {
					int i = left + 2, j = right - 1;
					while (i < j) {
						if (s[i] != s[j]) {
							check = false;
							break;
						}
						else {
							i++; j--;
						}
					}
					if (check)break;
				}
				if (s[left] == s[right - 1]) {
					check = true;
					int i = left + 1, j = right - 2;
					while (i < j) {
						if (s[i] != s[j]) {
							check = false;
							break;
						}
						else {
							i++; j--;
						}
					}
					if (check)break;
				}
				else {
					check = false;
					break;
				}
			}
			else {
				left++;
				right--;
			}
		}
		if (check) {
			if (num == 1)cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else cout << 2 << '\n';
	}


	return 0;

}