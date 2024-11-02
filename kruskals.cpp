// Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 20

std::vector<int> P(MAX);
int edge[3][MAX] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                    {2, 6, 3, 7, 4, 5, 7, 6, 7},
                    {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int find(int x) {
    if (P[x] == x) {
        return x;
    } else {
        return find(P[x]);
    }
}

void disjUnion(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        P[py] = px;
    }
}

int kMin(int k) {
    int e = 9, temp = -999, min, imin;
    while (k > 0) {
        min = edge[2][0];
        imin = 0;
        for (int i = 1; i < e; i++) {
            if (edge[2][i] < min && edge[2][i] > temp) {
                min = edge[2][i];
                imin = i;
            }
        }
        temp = min;
        k--;
    }
    return imin;
}

int main() {
    int v = 7, e = 9, count = 0, imin, rx, ry, weight = 0;
    std::vector<std::vector<int>> t(2, std::vector<int>(MAX));
    
    for (int i = 0; i <= v; i++) {
        P[i] = i;
    }
    
    for (int i = 1; i <= e; i++) {
        imin = kMin(i);
        int x = edge[0][imin];
        int y = edge[1][imin];
        rx = find(x);
        ry = find(y);
        
        if (rx != ry) {
            t[0][count] = edge[0][imin];
            t[1][count] = edge[1][imin];
            disjUnion(rx, ry);
            count++;
            weight += edge[2][imin];
        }
    }
    
    std::cout << "\nThe result:";
    for (int j = 0; j < 2; j++) {
        std::cout << "\n";
        for (int i = 0; i < count; i++) {
            std::cout << "\t" << t[j][i];
        }
    }
    std::cout << "\nThe total weight of the MST: " << weight;
    
    return 0;
}