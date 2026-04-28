#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

/**
 * @class Graph
 * @brief A template-based directed graph implementation using adjacency list.
 *
 * Supports BFS (Breadth-First Search) and DFS (Depth-First Search) traversals.
 * Uses dynamic vertex numbering.
 *
 * @tparam T The data type stored in graph vertices.
 */
template <typename T>
class Graph {
private:
    /**
     * @struct Edge
     * @brief Represents a directed edge in the graph.
     */
    struct Edge {
        int dest;
        T weight;
        
        Edge(int d, const T& w) : dest(d), weight(w) {}
    };
    
    /**
     * @struct Vertex
     * @brief Represents a vertex in the graph.
     */
    struct Vertex {
        int id;
        std::vector<Edge> adjacencyList;
        
        Vertex(int vertexId) : id(vertexId) {}
    };
    
    std::vector<Vertex*> vertices;
    int vertexCount;
    
public:
    /**
     * @brief Default constructor initializes an empty graph.
     */
    Graph() : vertexCount(0) {}
    
    /**
     * @brief Destructor deallocates all vertices.
     */
    ~Graph() {
        for (auto vertex : vertices) {
            delete vertex;
        }
    }
    
    /**
     * @brief Adds a vertex to the graph.
     * @return The ID of the newly added vertex.
     * Time Complexity: O(1)
     */
    int addVertex() {
        Vertex* newVertex = new Vertex(vertexCount);
        vertices.push_back(newVertex);
        return vertexCount++;
    }
    
    /**
     * @brief Adds a directed edge between two vertices.
     * @param src Source vertex ID.
     * @param dest Destination vertex ID.
     * @param weight Edge weight.
     * Time Complexity: O(1)
     */
    void addEdge(int src, int dest, const T& weight) {
        if (src < 0 || src >= vertexCount || dest < 0 || dest >= vertexCount) {
            throw std::out_of_range("Invalid vertex ID");
        }
        
        vertices[src]->adjacencyList.emplace_back(dest, weight);
    }
    
    /**
     * @brief Breadth-First Search (BFS) traversal.
     * @param startVertex The starting vertex for BFS.
     * Time Complexity: O(V + E) where V is vertices and E is edges.
     */
    void bfs(int startVertex) const {
        if (startVertex < 0 || startVertex >= vertexCount) {
            throw std::out_of_range("Invalid start vertex");
        }
        
        std::unordered_set<int> visited;
        std::queue<int> q;
        
        q.push(startVertex);
        visited.insert(startVertex);
        
        std::cout << "BFS Traversal: ";
        
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            
            std::cout << vertex << " ";
            
            for (const Edge& edge : vertices[vertex]->adjacencyList) {
                if (visited.find(edge.dest) == visited.end()) {
                    visited.insert(edge.dest);
                    q.push(edge.dest);
                }
            }
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Depth-First Search (DFS) traversal.
     * @param startVertex The starting vertex for DFS.
     * Time Complexity: O(V + E) where V is vertices and E is edges.
     */
    void dfs(int startVertex) const {
        if (startVertex < 0 || startVertex >= vertexCount) {
            throw std::out_of_range("Invalid start vertex");
        }
        
        std::unordered_set<int> visited;
        std::stack<int> s;
        
        s.push(startVertex);
        visited.insert(startVertex);
        
        std::cout << "DFS Traversal: ";
        
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            
            std::cout << vertex << " ";
            
            for (const Edge& edge : vertices[vertex]->adjacencyList) {
                if (visited.find(edge.dest) == visited.end()) {
                    visited.insert(edge.dest);
                    s.push(edge.dest);
                }
            }
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Displays the adjacency list representation of the graph.
     * Time Complexity: O(V + E)
     */
    void display() const {
        std::cout << "Graph (Adjacency List):" << std::endl;
        
        for (const auto* vertex : vertices) {
            std::cout << "Vertex " << vertex->id << ": ";
            
            for (const Edge& edge : vertex->adjacencyList) {
                std::cout << vertex->id << "->" << edge.dest << " ";
            }
            
            if (vertex->adjacencyList.empty()) {
                std::cout << "(no edges)";
            }
            std::cout << std::endl;
        }
    }
    
    /**
     * @brief Returns the number of vertices in the graph.
     */
    int getVertexCount() const {
        return vertexCount;
    }
    
    /**
     * @brief Returns the number of edges in the graph.
     * Time Complexity: O(V + E)
     */
    int getEdgeCount() const {
        int edgeCount = 0;
        for (const auto* vertex : vertices) {
            edgeCount += vertex->adjacencyList.size();
        }
        return edgeCount;
    }
};

#endif // GRAPH_HPP
