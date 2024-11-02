#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX = 100;
const int INF = 9999;

vector<vector<int>> D(MAX, vector<int>(MAX));
vector<vector<int>> S(MAX, vector<int>(MAX));
int n;

void floydWarshall();
void display(const vector<vector<int>>& mat, int n);

int main() {
    int ch, i, j;
    vector<vector<int>> G(MAX, vector<int>(MAX));

    cout << "\nEnter the number of vertices in the graph: ";
    cin >> n;

    // Input of adjacency matrix of the graph
    cout << "\nEnter the adjacency matrix for the given graph:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                cout << "\nIs there a direct edge between V" << i << " and V" << j << ":[1/0] ";
                cin >> ch;
                if (ch) {
                    cout << "\nWeight:";
                    cin >> G[i][j];
                } else {
                    G[i][j] = INF;
                }
            } else {
                G[i][i] = 0;
            }
        }
    }
    display(G, n);
    
    // Initialising the D and S matrix 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = G[i][j];
            S[i][j] = j;
        }
    }
    for (i = 0; i < n; i++) {
        S[i][i] = 0;
    }
    floydWarshall();
    
    cout << "\nThe final D matrix is:\n";
    display(D, n);
    cout << "\nThe final S matrix is:\n";
    display(S, n);

    return 0;
}

void floydWarshall() {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    S[i][j] = k;
                }
            }
        }
    }
}

void display(const vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout <<"\n";
    }
}