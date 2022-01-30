#include<iostream>

using namespace std;

int N, M, K;

int main() {    
    cin >> N >> M;
    int first_matrix[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> first_matrix[i][j]; 
        }
    }


    cin >> M >> K;
    int second_matrix[M][K];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> second_matrix[i][j]; 
        }
    }

    int multiple_matrix[N][K];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            multiple_matrix[i][j] = 0; // 전역변수 선언 시 자동으로 '0으로 초기화, but 지역변수는 초기화 필요
            for (int k = 0; k < M; k++) {
                multiple_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
            cout << multiple_matrix[i][j] << " ";
        } 
        cout << endl;
    }
}