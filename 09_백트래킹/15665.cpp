// 15665번 N과 M(11): https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> numbers;     // 입력 받은 수
vector<int> sequence; // 출력할 수열

/**
 * 입력 받은 수에서 중복수열을 만든다.
 * 
 * m: 수열의 길이
 * cnt: 현재 뽑은 수의 개수
*/
void backtracking(int m, int cnt) {
    // 재귀 호출 종료 조건: m개의 수를 모두 뽑음
    if (cnt == m) {//현재 뽑은 수의 개수가 수열의 길이와 같다면
        // 수열 출력
        for (int i = 0; i < m; i++)
            cout << sequence[i] << ' ';//수열 출력하기
        cout << '\n';
        return;
    }
    // 중복을 허용해서 하나씩 수를 뽑아 수열에 저장
    for (auto num: numbers) {
        sequence[cnt] = num;//수열에 값 저장
        backtracking(m, cnt + 1);//재귀적으로 반복
    }
}

int main() {
    // 입력
    int n, m;
    cin >> n >> m;//n과 m값 입력받기
    while (n--) {//n이 0이 아니라면
        int num;
        cin >> num;//값 입력ㅂㄷ기
        numbers.insert(num);//입력받은 수 집합에 값 집어넣기
    }
    // 초기화
    sequence.assign(m, 0);
    // 연산
    backtracking(m, 0);
    return 0;
}