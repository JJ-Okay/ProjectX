#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

const int graph_size = 6;

void algorithm(int graph[graph_size][graph_size], int start_point)
{
    int distance[graph_size], index;
    bool visited_point[graph_size];
    
    for(int i(0); i < graph_size; i++)
    {
        distance[i] = INT_MAX;
        visited_point[i] = false;
    }
    
    distance[start_point] = 0;
    
    for(int i(0); i < (graph_size - 1); i++)
    {
        int minimum = INT_MAX;
        
        for(int j(0); j < graph_size; j++)
            if (!visited_point[j] && distance[j] <= minimum)
            {
                minimum = distance[j];
                index = j;
            }
        
        visited_point[index] = true;
        
        for(int k(0); k < graph_size; k++)
            if (!visited_point[k] && graph[index][k] && distance[index] != INT_MAX && distance[index] + graph[index][k] < distance[k])
                distance[k] = distance[index] + graph[index][k];
    }
    
    cout << "Distances:" << endl;
    
    for(int i(0); i < graph_size; i++)
        if(i != start_point)
        {
            if(distance[i] != INT_MAX)
                cout << (start_point + 1) << " -> " << i+1 << " = " << distance[i] << endl;
            else
                cout << (start_point + 1) << " -> " << i+1 << " - " << "Route is inaccessible!" << endl;
        }
}

int main()
{
    
    int start_point,
    graph[6][6] = {
        {0, 0, 2, 0, 1, 0},
        {0, 0, 0, 8, 0, 8},
        {0, 0, 0, 9, 0, 0},
        {6, 3, 1, 0, 0, 1},
        {0, 2, 0, 0, 0, 6},
        {0, 0, 0, 9, 0, 0}};
    
    cout << "First top: ";
    cin >> start_point;
    cout << endl;
    
    algorithm(graph, start_point - 1);

    return 0;

}
