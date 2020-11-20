#include <string>
#include <vector>

using namespace std;

int ans[2] = { 0, 0 };
vector<vector<int>>a;

void sol(int x, int y, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (a[x][y] != a[x + i][y + j]) {
				sol(x, y, size / 2);
				sol(x + size / 2, y, size / 2);
				sol(x, y + size / 2, size / 2);
				sol(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}

	ans[a[x][y]]++;
	return;
}

vector<int> solution(vector<vector<int>> arr) {

	a = arr;

	sol(0, 0, arr.size());
	return {ans[0], ans[1]};
}