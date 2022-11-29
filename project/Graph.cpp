#include "Vertex.cpp"
#include "Edge.cpp"
#include <map>
#include <unordered_map>
#include "vector"
#include <bits/stdc++.h>

class Graph
{
public:
    int max_vertices = 15000;
    double **adjacencyMatrix;
    vector<Vertex> vertices;
    int vertex_count = 0;
    int edge_count = 0;
    unordered_map<int, int> predecessor;
    unordered_map<int, int>::iterator iter;

public:
    Graph();
    void printGraph() const;
    void addVertex(int id, string name);
    void printVertex();
    void addEdge(int source_id, int des_id, double weight);
    bool isAdjecent(int source, int destination) const;
    vector<int> getSuccessors(int source_id);
    vector<string> printPath(int destination);
    vector<string> searchAlgorithm(int source_id, int des_id);

private:
    string getVertexName(int source);
    int getVertexId(const string &source);
};

Graph::Graph()
{
    this->adjacencyMatrix = new double *[max_vertices];
    for (int i = 0; i < max_vertices; i++)
    {
        adjacencyMatrix[i] = new double[max_vertices];
    }
}

void Graph::addVertex(int id, string name)
{
    vertices.emplace_back(id, name);
    vertex_count++;
}

void Graph ::printVertex()
{
    for (int i = 0; i < vertex_count; i++)
    {
        vertices[i].toString();
    }
}

int Graph::getVertexId(const string &source)
{
    for (int i = 0; i < vertex_count; i++)
    {
        if (source == vertices[i].name)
        {
            return vertices[i].getId();
        }
    }
    return 0;
}

string Graph::getVertexName(int source)
{
    for (int i = 0; i < vertex_count; i++)
    {
        if (source == vertices[i].getId())
        {
            return vertices[i].getName();
        }
    }
    return " ";
}

void Graph::addEdge(int source_id, int des_id, double weight)
{
    if (source_id != des_id)
    {
        adjacencyMatrix[source_id][des_id] = weight;
        edge_count++;
    }
}

bool Graph::isAdjecent(int source, int destination) const
{
    if (adjacencyMatrix[source][destination] != 0)
    {
        return true;
    }
    return false;
}

vector<int> Graph::getSuccessors(int source_id)
{
    vector<int> successors;
    for (int i = 0; i < vertex_count; i++)
    {
        if (isAdjecent(source_id, vertices[i].getId()))
        {
            successors.push_back(vertices[i].getId());
        }
    }
    return successors;
}

vector<string> Graph::printPath(int destination)
{
    vector<string> solutionPath;
    solutionPath.push_back(getVertexName(destination));
    int current_node = destination;

    while (predecessor.find(current_node) != predecessor.end())
    {
        current_node = predecessor.find(current_node)->second;
        if (current_node == 0)
        {
            break;
        }
        solutionPath.push_back(getVertexName(current_node));
    }
    reverse(solutionPath.begin(), solutionPath.end());
    return solutionPath;
}

vector<string> Graph::searchAlgorithm(int source_id, int des_id)
{
    predecessor.insert({source_id, 0});

    if (source_id == des_id)
    {
        return printPath(des_id);
    }

    vector<bool> isVisited;
    isVisited.resize(max_vertices, false);

    isVisited[source_id] = true;
    list<int> queue;
    queue.push_back(source_id);

    while (!queue.empty())
    {
        int currentvertex = queue.front();
        queue.pop_front();

        if (currentvertex == des_id)
        {
            return printPath(des_id);
        }

        vector<int> successors = getSuccessors(currentvertex);
        for (auto successor : successors)
        {

            bool found = std::find(queue.begin(), queue.end(), successor) != queue.end();
            if (!found && !isVisited[successor])
            {
                iter = predecessor.begin();
                for (; iter != predecessor.end(); iter++)
                {

                    if (iter->first != successor)
                    {
                        predecessor.insert({successor, currentvertex});
                    }
                    else
                    {
                        predecessor[successor] = currentvertex;
                    }
                }

                queue.push_back(successor);
                isVisited[successor] = true;
            }
        }
    }
    return printPath(0);
}

void Graph::printGraph() const
{
    cout << "lets print";
    for (int i = 0; i < vertex_count; i++)
    {
        for (int j = 0; j < vertex_count; j++)
        {
            cout << to_string(adjacencyMatrix[i][j]) << " ";
        }
        cout << endl;
    }
}
