#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land[0].size();
    vector<int>left, right;
    
    for(int k = 1; k<land.size(); ++k){
        left = vector<int>(n, 0);
        right = vector<int>(n, 0);
        left[0] = land[k-1][0];
        for(int i = 1; i<n; ++i){
            left[i] = max(left[i-1], land[k-1][i]);
        }
        right[n-1] = land[k-1][n-1];
        for(int i = n-2; i>=0; --i){
            right[i] = max(right[i+1], land[k-1][i]);
        }
        for(int i = 0; i<n; ++i){
            int a = (i-1>=0? left[i-1] : 0);
            int b = (i+1<n? right[i+1] : 0);
            land[k][i]+=max(a, b);
            answer = max(land[k][i], answer);
        }
    }

    return answer;
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges