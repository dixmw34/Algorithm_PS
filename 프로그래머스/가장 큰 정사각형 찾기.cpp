#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0, n = board.size(), m = board[0].size();

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(board[i][j] == 1){
                answer = 1;
            }
        }
    }
    
    for(int i = 1; i<n; ++i){
        for(int j = 1; j<m; ++j){
            if(board[i][j] == 1 && board[i-1][j-1] && board[i-1][j]&& board[i][j-1]){
                board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1]))+1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer*answer;
}