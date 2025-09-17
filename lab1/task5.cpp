#include <iostream>
using namespace std;

void multiplyMatrices(int A[50][50], int B[50][50], int C[50][50], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, n, p, q;
    int A[50][50], B[50][50], C[50][50];

    cout << "Enter rows and columns of first matrix (m n): ";
    cin >> m >> n;

    cout << "Enter rows and columns of second matrix (p q): ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible. Columns of A must equal rows of B." << endl;
        return 0;
    }

    cout << "Enter elements of first matrix (A):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix (B):" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, C, m, n, q);

    cout << "\nResultant Matrix (C = A x B):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
