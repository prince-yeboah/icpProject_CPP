#include "Vertex.cpp"

class Edge {
public:
    Vertex *source;
    Vertex *destination;
    double weight = 0 ;
    Edge(Vertex , Vertex , double );
};

Edge::Edge(Vertex source, Vertex destination, double weight) {
    this->source = &source;
    this->destination = &destination;
    this->weight = weight;
}
