#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<queue<int>>arr(board[0].size());

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j])arr[j].push(board[i][j]);
        }
    }

    stack<int>s;
    for (int i = 0; i < moves.size(); i++) {
        int line = moves[i] - 1;
        if (!arr[line].empty()) {
            int doll = arr[line].front();
            arr[line].pop();
            if (s.empty() || s.top() != doll)s.push(doll);
            else {
                s.pop();
                answer += 2;
            }
        }
    }


    return answer;
}