#include <iostream>
#include<bits/stdc++.h>

class Graph {

    private:
    std::unordered_map<int, std::vector<int>> adjacency_list;

    public:
    void addVertex(int vertex) {
       adjacency_list[vertex] = std::vector<int>();
    }

   void addEdge(int vertex1, int vertex2) {
    adjacency_list[vertex1].push_back(vertex2);
    adjacency_list[vertex2].push_back(vertex1);
   }  

   void display() {
    for( auto& pair : adjacency_list) {
        int vertex = pair.first;
        std::cout << vertex << " -> ";
    for( auto& list : pair.second) {
        std::cout << list << " ";
            }
        std::cout<< std::endl;
         }
     }
};

int main() {

   Graph g;

  

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    // Add edges
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

  g.display();
    return 0;
}