#include <iostream>
#include <climits>
using namespace std;
#define I 9999

void prims(int cost[8][8], int T[2][6]);
void Tprint(int T[2][6]);

int main()
{
    int G[8][8] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}
    };

    int T[2][6];
    prims(G, T);
    Tprint(T);

    return 0;
}

void prims(int cost[8][8], int T[2][6])
{
    int i, j, k, min = I, u, v, n = 7;

    int near[8] = {I, I, I, I, I, I, I, I};

    // Initial Step
    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    T[0][0] = u;
    T[1][0] = v;
    near[u] = 0;
    near[v] = 0;
    
    for(i = 1; i <= n; i++)
    {
        if(near[i] != 0)
        {
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Repeating Step
    for(i = 1; i < n-1; i++)
    {
        min = I;
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && (cost[j][near[j]] < min))
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        T[0][i] = k;
        T[1][i] = near[k];
        near[k] = 0;

        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && (cost[j][k] < cost[j][near[j]]))
                near[j] = k;
        }
    }
}

void Tprint(int T[2][6])
{
    int i, j, n = 6;
    std::cout << "The MST (Represented by T matrix):" << std::endl;
    for(i = 0; i < 2; i++)
    {
        std::cout << std::endl;
        for(j = 0; j < n; j++)
            std::cout << T[i][j] << " ";
    }
}
