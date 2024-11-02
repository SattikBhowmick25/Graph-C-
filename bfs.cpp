#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void display(const vector<vector<int>>& A, int n);
void BFS(const vector<vector<int>>& A, int n);

int main() {
    int n;
    cout << "\nEnter the number of vertices:";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n, 0));

    cout << "\nEnter the adjacency matrix of the given graph:";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "\nIs there an edge between V" << i << " and V" << j << "?:[Yes-1/No-0]: ";
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            A[i][j] = A[j][i];
        }
    }
    display(A, n);
    BFS(A, n);
    return 0;
}

void display(const vector<vector<int>>& A, int n) {
    cout << "\nThe adjacency matrix is:";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            cout << "\t" << A[i][j];
        }
    }
}

void BFS(const vector<vector<int>>& A, int n) {
    vector<int> status(n, 0);
    vector<int> visited(n);
    queue<int> Q;
    int count = 0;

    int s = 0;
    Q.push(s);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        if (status[v] == 0) {
            status[v] = 1;
            visited[count++] = v;
        }
        for (int i = v; i < n; i++) {
            if (A[v][i] == 1 && status[i] == 0) {
                Q.push(i);
            }
        }
    }

    if (count == n)
        cout << "\n\nThe graph is connected";
    else
        cout << "\n\nThe graph is not connected";

    cout << "\n\nThe traversal order:";
    for (int i = 0; i < count; i++) {
        cout << visited[i] <<"->";
    }
}