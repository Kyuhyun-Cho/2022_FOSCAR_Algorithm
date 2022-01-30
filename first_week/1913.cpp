#include<iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int snail_array[N][N];
    int start_num = N * N;
    int count = 0;
    int count_standard = N - 1;

    string direction = "right";

    int x = 0;
    int y = 0;
    
    int M_x = 0;
    int M_y = 0;

    for (y = 0; y < N; y++) {
        snail_array[y][0] = start_num--;
    }

    y--;
    
    for (int i = 0; i < N*(N-1); i++) {
        if (direction == "right") {
            for (int count = 0; count < count_standard; count++) {
                x++;
                snail_array[y][x] = start_num--;
            }
            direction = "up";
            continue;
        }

        if (direction == "up") {
            for (int count = 0; count < count_standard; count++) {
                y--;
                snail_array[y][x] = start_num--;
            }
            count_standard--;
            direction = "left";
            continue;
        }   

        if (direction == "left") {
            for (int count = 0; count < count_standard; count++) {
                x--;
                snail_array[y][x] = start_num--;
            }
            direction = "down";
            continue;
        }

        if (direction == "down") {
            for (int count = 0; count < count_standard; count++) {
                y++;
                snail_array[y][x] = start_num--;
            }
            count_standard--;
            direction = "right";
            continue;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            cout << snail_array[i][j] << " ";
            if (snail_array[i][j] == M) {
                M_x = j + 1;
                M_y = i + 1;
            }
        }
        cout << endl;
    }

    cout << M_y << " " << M_x;
}