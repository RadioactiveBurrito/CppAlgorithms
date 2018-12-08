#include "../header/vertex.h"

vertex::vertex(vertex *previous, int distance, int id)
{
    _distance = distance;
    _previous = previous;
    _id = id;
}

vertex::vertex()
{
    _distance = UNKNOWN_DISTANCE;
    _id = -1;
    _previous = nullptr;
}

vertex::vertex(vertex *toCopy)
{
    _id = toCopy->_id;
    _distance = toCopy->_distance;
    if (toCopy->_previous != nullptr && toCopy != this)
    {                                              //to prevent stackOverflow
        _previous = new vertex(toCopy->_previous); //memory leak? nop!
    }
}

std::vector<vertex *> vertex::getNeighbors(int **weights, vertex ** vertices, int nbVertices)
{
    std::vector<vertex *> neighbors = std::vector<vertex *>();
    vertex* v;
    for (int i = 0; i < nbVertices; ++i)
    {
        v = vertices[i];
        if (*v != this && weights[_id][v->_id] != -1)
        {
            neighbors.push_back(v);
        }
    }
    return neighbors;
}

int vertex::getId()
{
    return _id;
}

int vertex::getDistance()
{
    return _distance;
}

vertex *vertex::getPrevious()
{
    return _previous;
}

void vertex::setDistance(int distance)
{
    _distance = distance;
}

void vertex::setPrevious(vertex *previous)
{
    _previous = previous;
}

bool vertex::operator<(const vertex &v)
{
    return _distance < v._distance;
}

bool vertex::operator>(const vertex &v)
{
    return _distance > v._distance;
}

bool vertex::operator==(const vertex &v)
{
    return _id == v._id;
}

bool vertex::operator!=(const vertex &v) {
    return !(*this == v);
}