#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 100001;
// 문제
// KOI 본선 대회에 N명의 학생이 참가했다. 이 학생들을 각각 1부터 N까지 정수로 표현하자. 대회가 끝나고 성적을 발표하는데, 
// 이 대회는 전체 학생의 등수를 발표 하는 대신, 두 학생 A, B가 대회 본부에 찾아가면 본부는 두 학생 중 어느 학생이 더 잘 했는지를 알려준다. 
// 둘 이상의 학생이 동점인 경우는 없다.
// 자신의 전체에서 등수가 궁금한 학생들은 둘 씩 짝을 지어서 대회 본부에 총 M번 질문을 했다.
// 여러분은 등수를 알고 싶은 학생 X와 대회 본부의 질문에 대한 답들 로부터 이 학생 X의 등수 범위를 찾아서 출력한다. 질문에 대한 답으로 알 수 있는 최대한 정확한 답을 출력한다.
// ---------------------------------
// 입력
// 표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에 세 정수 N, M, X가 공백을 사이에 두고 주어진다. (2 ≤ N ≤ 105, 1 ≤ M ≤ min(N(N-1)/2, 5×105), 1 ≤ X ≤ N) . 
// 다음 M 줄에는 각각 두 정수 A, B가 주어지는데, 이 뜻은 학생 A가 학생 B보다 더 잘했다는 뜻이다. 같은 A, B가 둘 이상의 줄에 주어지는 경우는 없고, 입력된 값이 정확함이 보장된다.
// ---------------------------------
// 출력
// 표준 출력으로 두 정수 U, V (1 ≤ U ≤ V ≤ N)를 출력한다. 이는 학생 X의 가능한 가장 높은 등수가 U, 가능한 가장 낮은 등수가 V임을 나타낸다. 만약 학생 X의 가능한 등수가 정확하게 하나라면, U = V이다.
// ---------------------------------
// 자기 뒤에 몇명 있는지 확인 + 자기 앞에 몇명 있는지 확인?
// 자기 앞에 몇명 있는지 확인 방법 
// 자기 뒤에 몇명 있는지 확인 방법 
int n, m, a, b, x, u, v;

vector<int> arr[MAX], rev_arr[MAX];
int visited[MAX];
int fr = -1, ba = -1;

// 뒤에 몇명 있는지 확인하자
// 내 뒤로 몇명이 있으면 나는 n - ba + 1 등이 최악
void dfs(int cur) {
    if(visited[cur]) {
        return;
    }

    ba++;
    visited[cur] = 1;
    for(int i=0; i<arr[cur].size(); i++) {
        int nxt = arr[cur][i];
        dfs(nxt);
    }
}

// 앞에 몇명 있는지 확인하자
// 내 뒤로 몇명이 있으면 나는 fr + 1 등이 최악
void rev_dfs(int cur) {
    if(visited[cur]) {
        return;
    }
    fr++;
    visited[cur] = 1;
    for(int i=0; i<rev_arr[cur].size(); i++) {
        int nxt = rev_arr[cur][i];
        rev_dfs(nxt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> x;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a].push_back(b);
        rev_arr[b].push_back(a);
    }

    dfs(x);
    memset(visited, 0, sizeof(visited));
    rev_dfs(x);

    cout << fr + 1 << ' ' << n - ba << endl;
    return 0;
}