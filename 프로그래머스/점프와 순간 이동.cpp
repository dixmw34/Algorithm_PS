#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int solution(int n)
{
    int ans = 0;
    while(n){
        if(n%2 == 1)
            ans++;
        n/=2;
    }
    return ans;
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges