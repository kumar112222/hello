#include <iostream>
using namespace std;

char func(char arr[3][3]) {
    if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]&&arr[0][0]!='.') {
        return arr[0][0];
    }
    if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]&&arr[1][1]!='.') {
        return arr[1][1];
    }
    if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]&&arr[2][2]!='.') {
        return arr[2][2];
    }
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]&&arr[0][0]!='.') {
        return arr[0][0];
    }
    if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]&&arr[1][1]!='.') {
        return arr[1][1];
    }
    if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]&&arr[2][2]!='.') {
        return arr[2][2];
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]&&arr[0][0]!='.') {
        return arr[0][0];
    }
    if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2]&&arr[1][1]!='.') {
        return arr[1][1];
    }

    return 'D';  // Draw
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        char arr[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> arr[i][j];
            }
        }

        char ans = func(arr);

        if (ans == 'D'||ans=='.') {
            cout << "DRAW" << endl;
        }

         else {
            cout << ans << endl;
        }
    }

    return 0;
}
