#ifndef GRAPH_H
#endif
#include "vertex.h"
#include "priority_queue.h"
#include <vector>

class graph
{
  public:
    graph(int nbVertices = 0, int **weights = nullptr);
    void dijkstra(int idStart);
	void initializeVertices();
	void showMinimalTreeFrom(int idStart);

  private:
    vertex **_vertices; /*matrix of connectivity. null indicates not connected*/
    int _nbVertices;
    int **_weights;
};