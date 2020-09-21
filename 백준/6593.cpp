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

int ax[] = { -1, 0, 0, 1, 0, 0 };
int ay[] = { 0, -1, 0, 0, 1, 0 };
int az[] = { 0, 0, -1, 0, 0, 1 };


struct Point
{
	int x;
	int y;
	int z;

};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	
	int L, R, C;

	while (cin >> L >> R >> C && L) {
		vector<vector<vector<char>>>arr(L, vector<vector<char>>(R, vector<char>(C)));

		queue<Point>man;

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')man.push(Point{ i, j, k });
				}
			}
		}

		int time = 0;
		int result = INF;
		while (!man.empty()) {
			int n = man.size();
			while (n--) {
				Point p = man.front(); man.pop();
				for (int i = 0; i < 6; ++i) {
					if (p.x + ax[i] >= 0 && p.x + ax[i] < L && p.y + ay[i] >= 0 && p.y + ay[i] < R && p.z + az[i] >= 0 && p.z + az[i] < C) {
						if (arr[p.x + ax[i]][p.y + ay[i]][p.z + az[i]] == '.') {
							arr[p.x + ax[i]][p.y + ay[i]][p.z + az[i]] = 'S';
							man.push(Point{ p.x + ax[i],p.y + ay[i],p.z + az[i] });
						}
						else if (arr[p.x + ax[i]][p.y + ay[i]][p.z + az[i]] == 'E') {
							result = time;
							break;
						}
					}
				}
			}
			if (result != INF)break;
			time++;
		}
		if (result == INF)cout << "Trapped!\n";
		else cout << "Escaped in " << result + 1 << " minute(s).\n";
	}

	return 0;

}