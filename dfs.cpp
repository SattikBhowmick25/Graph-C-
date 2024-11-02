#include <iostream>
#include <vector>

#define MAX 100

std::vector<int> stack;
int top = -1;

void PUSH(int item);
int POP();
void display(int A[MAX][MAX], int n);

int status[MAX], visited[MAX];

void DFS(int A[MAX][MAX], int n);

int main()
{
    int n, i, j, A[MAX][MAX];
    std::cout << "\nEnter the number of vertices:";
    std::cin >> n;
    std::cout << "\nEnter the adjacency matrix of the given graph:";
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            std::cout << "\nIs there an edge between V" << i << " and V" << j << "?:[Yes-1/No-0]: ";
            std::cin >> A[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            A[i][j] = A[j][i];
        }
    }
    display(A, n);

    DFS(A, n);
    return 0;
}

void display(int A[MAX][MAX], int n)
{
    int i, j;
    std::cout << "\nThe adjacency matrix is:";
    for (i = 0; i < n; i++)
    {
        std::cout << "\n";
        for (j = 0; j < n; j++)
        {
            std::cout << "\t" << A[i][j];
        }
    }
}

void PUSH(int item)
{
    if (top < MAX)
        stack.push_back(item);
    top++;
}

int POP()
{
    int item = -1;
    if (top > -1)
    {
        item = stack[top];
        stack.pop_back();
        top--;
    }
    return item;
}

void DFS(int A[MAX][MAX], int n)
{
    int s, v, i, j, count = 0;
    for (i = 0; i < n; i++)
        status[i] = 0;

    s = 0;
    PUSH(s);

    while (top != -1)
    {
        v = POP();
        if (status[v] == 0)
        {
            status[v] = 1;
            visited[count++] = v;
        }
        for (i = v; i < n; i++)
        {
            if (A[v][i] == 1)
            {
                if (status[i] == 0)
                {
                    PUSH(i);
                }
            }
        }
    }

    if (count == n)
        std::cout << "\n\nThe graph is connected";
    else
        std::cout << "\n\nThe graph is not connected";

    std::cout << "\n\nThe traversal order:";
    for (i = 0; i < n; i++)
    {
        std::cout << visited[i] << "->";
    }
}