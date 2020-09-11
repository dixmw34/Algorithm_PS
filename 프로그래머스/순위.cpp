#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	bool win[100][100] = { false, };
	bool lose[100][100] = { false, };

	for (int i = 0; i < results.size(); i++) {
		int a = results[i][0] - 1, b = results[i][1] - 1;
		win[a][b] = true;
		lose[b][a] = true;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (!win[i][j] && win[i][k] && win[k][j])win[i][j] = true;
				if (!lose[i][j] && lose[i][k] && lose[k][j])lose[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (win[i][j])num++;
			else if (lose[i][j])num++;
		}
		if (num == n - 1)answer++;
	}

	return answer;
}