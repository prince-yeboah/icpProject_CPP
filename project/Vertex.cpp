#include <string>
#include <iostream>
using namespace std;

class Vertex {
public:
    int id;
    string name;
    Vertex(int, string);
    int getId() const;
    string getName() const;
    void toString();
};

Vertex::Vertex(int id, string name) {
    this->id = id;
    this->name = name;
}

int Vertex :: getId() const{
    return id;
}

string Vertex :: getName() const{
    return name;
}
void Vertex::toString() {
    cout << "ID: "+ to_string(getId()) + " Name " + getName() << endl;
}
