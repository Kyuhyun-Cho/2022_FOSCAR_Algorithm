#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt;
    cin >> n;
    
    int con_arr[n];
    int arr[n];
    int tmp = 0;
    int min = 9;
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        con_arr[i-1] = i;
        arr[i-1] = i;
        cout << arr[i-1] << " ";
    }
    cout << '\n';

    sort(con_arr, con_arr + n, greater<int>());

    while ( !equal(con_arr, con_arr + n, arr) ) {
        for (int i = n-1; i > 0; i--) {
            if (arr[i-1] < arr[i]) {
                for(int j = n-1; j >= i; j--) {
                    if (arr[i-1] < arr[j] && arr[j] < min) {
                        min = arr[j];
                        idx = j;
                    }
                }
                tmp = arr[i-1];
                arr[i-1] = arr[idx];
                arr[idx] = tmp;
                reverse(arr+i, arr+n);

                for (int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << '\n'; // endl은 flush를 겸하기 때문에 매우 매우 매우 매우 매우 느림! '\n'을 사용하도록 하자. 단 '\n'은 긴 문장 출력 시 버퍼에 담겨서 안나올수 있음.
                              // flush란? 버퍼엔 담긴 데이터가 모두 쏟아지는 것

                min = 9; // arr[j] 초기화
                idx = 0; // j 초기화
                break;
            }
        }
    }
}