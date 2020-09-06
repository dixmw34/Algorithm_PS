#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int ax[] = { 0, 1, 0, 1 };
int ay[] = {0, 0, 1, 1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    queue<pi>q;
    while (1) {
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                    q.push(pi(i, j));
                }
            }
        }

        if (q.empty())break;

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                if (board[x + ax[i]][y + ay[i]] != ' ') {
                    answer++;
                    board[x + ax[i]][y + ay[i]] = ' ';
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            queue<char>qch;
            for (int j = m - 1; j >= 0; --j) {
                if (board[j][i] != ' ') {
                    qch.push(board[j][i]);
                }
            }
            for (int j = m - 1; j >= 0; --j) {
                if (!qch.empty()) {
                    board[j][i] = qch.front();
                    qch.pop();
                }
                else board[j][i] = ' ';
            }
        }
    }

    return answer;
}