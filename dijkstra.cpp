// Dijkstra

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX = 100;
const int INF = numeric_limits<int>::max();

int G[MAX][MAX], status[MAX], dist[MAX], nxt[MAX];

int len(int v1, int v2);
void path(int v);

int main() {
    int ch, n, i, j, v0, v, v1;
    cout << "\nEnter the number of vertices: ";
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
    cout << "\nThe adjacency matrix is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == INF)
                cout << "\tI";
            else
                cout << "\t" << G[i][j];
        }
        cout << "\n";
    }
    cout << "\nEnter the starting vertex:";
    cin >> v0;

    status[v0] = 0;
    dist[v0] = 0;
    nxt[v0] = -1;

    for (v = 0; v < n; v++) {
        if (v != v0) {
            status[v] = -1;
            dist[v] = len(v0, v);
            nxt[v] = v0;
        }
    }

    for (i = 0; i <= n; i++) {
        v1 = i;
        if (status[i] == -1) {
            for (j = 0; j < n; j++) {
                if (status[j] == -1 && dist[j] < dist[v1]) {
                    v1 = j;
                }
            }
            status[v1] = 0;
            for (v = 0; v < n; v++) {
                if (status[v] == -1) {
                    if (dist[v] > dist[v1] + len(v1, v)) {
                        dist[v] = dist[v1] + len(v1, v);
                        nxt[v] = v1;
                    }
                }
            }
        }
    }

    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                cout << "\nStatus:\t";
                for (j = 0; j < n; j++) {
                    cout << status[j] << "\t";
                }
                break;
            case 1:
                cout << "\nDist:\t";
                for (j = 0; j < n; j++) {
                    cout << dist[j] << "\t";
                }
                break;
            case 2:
                cout << "\nNext:\t";
                for (j = 0; j < n; j++) {
                    cout << nxt[j] << "\t";
                }
                break;
        }
    }
    for (i = 1; i < v; i++) {
        cout << "\nPath from " << v0 << " to " << i << ": ";
        path(i);
        cout << "v" << i;
        cout << "\t\t\tWeight: " << dist[i];
    }

    return 0;
}

int len(int v1, int v2) {
    return G[v1][v2];
}

void path(int v) {
    if (nxt[v] != -1) {
        path(nxt[v]);
        cout << "v" << nxt[v] <<"->";
    }
}