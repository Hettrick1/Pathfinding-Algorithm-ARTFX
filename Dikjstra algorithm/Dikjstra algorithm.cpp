#include <iostream>

#include <vector>
#include <algorithm>

#define inf std::numeric_limits<int>::max()

int graph[12][12] = {
//  A    B    C    D    E    F    G    H    I    J    K    L
{   0,   2,   inf, inf, 13,  inf, inf, inf, inf, inf, 7,   10  }, //A
{   inf, 0,   inf, inf, inf, inf, 1,   inf, inf, inf, inf, inf }, //B
{   inf, inf, 0,   inf, 1,   inf, inf, 1,   inf, 2,   inf, inf }, //C
{   inf, inf, inf, 0,   inf, 8,   inf, 4,   inf, inf, inf, inf }, //D
{   inf, inf, inf, inf, 0,   inf, inf, inf, inf, 5,   inf, inf }, //E
{   inf, inf, inf, inf, inf, 0,   inf, inf, inf, inf, inf, inf }, //F
{   inf, inf, inf, 5,   inf, inf, 0,   2,   inf, inf, inf, 3   }, //G
{   inf, inf, inf, inf, inf, 10,  inf, 0,   4,   7,   inf, inf }, //H
{   inf, inf, inf, inf, inf, 5,   inf, inf, 0,   inf, inf, inf }, //I
{   inf, inf, inf, inf, inf, 1,   inf, inf, 9,   0,   inf, inf }, //J
{   inf, inf, 3,   inf, 8,   inf, inf, inf, inf,   inf, 0, 5   }, //K
{   inf, inf, inf, inf, inf, inf, inf, 12,  inf, inf, inf, 0   }, //L
};

int distance[12];
int previous[12];

void CalculateDikjstra(int Start, int graph[12][12], int* dist, int* prev);

int main()
{
    CalculateDikjstra(0, graph, distance, previous);
    std::cout << "Hello World!\n";
    for (int i = 0; i < 12; i++) {
        std::cout << static_cast<char>('A' + i ) << ":\t" << distance[i] << " \t: " << static_cast<char>('A' + previous[i]) << std::endl;
    }
}

void CalculateDikjstra(int src, int graph [12][12], int* dist, int* prev)
{

    std::vector<int> openNodes;

    for (int i = 0; i < 12; i++) {
        dist[i] = inf;
        prev[i] = -1;
        openNodes.push_back(i);
    }
    dist[src] = 0;

    while (openNodes.size() > 0) {
        int u = -1;
        int min = inf;
        for (int i = 0; i < openNodes.size(); i++) {
            if (dist[openNodes[i]] < min) {
                u = i;
                min = dist[openNodes[i]];
            }
        }
        int tempU = openNodes[u];
        openNodes.erase(openNodes.begin() + u);
        u = tempU;

        for (int j = 0; j < 12; j++) {
            if (graph[u][j] != inf && u !=j ) {
                int tempDist = dist[u] + graph[u][j];
                if (tempDist < dist[j]) {
                    dist[j] = tempDist;
                    prev[j] = u;
                }
            }
        }
    }
}
