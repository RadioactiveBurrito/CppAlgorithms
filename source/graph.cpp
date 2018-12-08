#include "../header/graph.h"
#include <iostream>

graph::graph(int nbVertices, int **weights)
{
    _nbVertices = nbVertices;
    _weights = weights;
	initializeVertices();
}

void graph::initializeVertices()
{
	_vertices = new vertex *[_nbVertices];
	for (int i = 0; i < _nbVertices; ++i)
		_vertices[i] = new vertex((vertex*)nullptr, vertex::UNKNOWN_DISTANCE, i);
}

void graph::dijkstra(int idStart)
{
	initializeVertices();
	vertex* start = _vertices[idStart];
    start->setDistance(0);

    priority_queue<vertex> queue = priority_queue<vertex>(_vertices, _nbVertices);
    vertex *previous = nullptr;
    int alternateDistance;
    std::vector<vertex *> neighbors;
	vertex *mostPromisingOption = start;
    while (!queue.isEmpty())
    {
        neighbors = mostPromisingOption->getNeighbors(_weights, _vertices, _nbVertices);
        for (vertex *neighbor : neighbors)
        {
            alternateDistance = mostPromisingOption->getDistance() + _weights[mostPromisingOption->getId()][neighbor->getId()];
            if (alternateDistance < neighbor->getDistance())
            {
                neighbor->setDistance(alternateDistance);
                neighbor->setPrevious(mostPromisingOption);
            }
        }
        queue.heapify();
        mostPromisingOption = queue.extract_min();
    }
}

void graph::showMinimalTreeFrom(int idStart)
{
	dijkstra(idStart);
	for (int i = 0; i < _nbVertices; ++i) 
	{
		if (i != idStart) 
		{ 
			std::cout << "Node " << i << " comes from " << _vertices[i]->getPrevious()->getId() << std::endl;
		}
	}
}