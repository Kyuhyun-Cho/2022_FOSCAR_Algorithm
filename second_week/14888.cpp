#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int factorial(int n) { 
    if (n <= 1) 
        return 1; 
    else 
        return n*factorial(n-1);
}

int main() {
    int n; cin >> n;
    
    int arr[n];
    int oprt[4] = {0, 0, 0, 0}; // {+, -, *, /}

    for (int i = 0; i < n; i++) { // 수열 배열 
        int tmp; cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 0; i < 4; i++) { // 연산자 배열
        int tmp; cin >> tmp;
        oprt[i] = tmp;
    }

    int cnt = oprt[0] + oprt[1] + oprt[2] + oprt[3];
    cnt = factorial(cnt);

    for (int i = 0; i < 4; i++) { // 연산자 삽입 경우의 수 계산
        if (oprt[i] > 0) {
            cnt /= oprt[i];
        }
    }  

    vector<int> oprt_vec; 

    for (int i = 0; i < 4; i++) { // 연산자 +, -, *, / -> 1, 2, 3, 4 치환
        for (int j = 0; j < oprt[i]; j++) 
            oprt_vec.push_back(i);
    }

    vector<int> values;
    do {
        int val = 0;
        for (int i = 0; i < n-1; i++) {
            if (i == 0) {
                if (oprt_vec[0] == 0) val = arr[0] + arr[1]; 
                else if (oprt_vec[0] == 1) val = arr[0] - arr[1]; 
                else if (oprt_vec[0] == 2) val = arr[0] * arr[1]; 
                else if (oprt_vec[0] == 3) val = arr[0] / arr[1]; 
            }
            else {
                if (oprt_vec[i] == 0) val = val + arr[i+1]; 
                else if (oprt_vec[i] == 1) val = val - arr[i+1]; 
                else if (oprt_vec[i] == 2) val = val * arr[i+1]; 
                else if (oprt_vec[i] == 3) val = val / arr[i+1]; 
            }
        }
        values.push_back(val);
    } while (next_permutation(oprt_vec.begin(), oprt_vec.end()));

    sort(values.begin(), values.end(), greater<int>());

    cout << values.front() << '\n' << values.back() << ' ' << '\n';
}