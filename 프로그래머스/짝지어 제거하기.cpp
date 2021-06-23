#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (temp.empty() || temp.back() != s[i]) {
            temp += s[i];
        }
        else
            temp.pop_back();
    }

    return (temp.empty() ? 1 : 0);
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges