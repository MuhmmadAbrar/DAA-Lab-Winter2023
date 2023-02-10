#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void printOptimalParens(vector< vector<int> > &s, int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(vector<int> &p) {
    int n = p.size() - 1;
    vector< vector<int> > m(n + 1, vector<int>(n + 1, 0));
    vector< vector<int> > s(n + 1, vector<int>(n + 1, 0));
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications is " << m[1][n] << endl;
    cout << "The optimal parenthesis are: ";
    printOptimalParens(s, 1, n);
}

int main() {
    vector<int> p = { 30, 35, 15, 5, 10, 20, 25 };
    matrixChainOrder(p);
    return 0;
}
