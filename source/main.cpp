#include <iostream>
#include "../header/graph.h"

static int **allocateWeights(int size)
{
    int **weights = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        weights[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            weights[i][j] = vertex::NOT_CONNECTED;
        }
    }
    return weights;
}

static int **initializeWeights()
{
    const int SIZE = 6;
    int **weights = allocateWeights(SIZE);

    weights[5][4] = 9;
    weights[4][5] = 9;

    weights[5][0] = 14;
    weights[0][5] = 14;

    weights[0][1] = 7;
    weights[1][0] = 7;

    weights[1][3] = 15;
    weights[3][1] = 15;

    weights[3][4] = 6;
    weights[4][3] = 6;

    weights[2][1] = 10;
    weights[1][2] = 10;

    weights[2][0] = 9;
    weights[0][2] = 9;

    weights[2][5] = 2;
    weights[5][2] = 2;

    weights[2][3] = 11;
    weights[3][2] = 11;

    return weights;
}

using namespace std;

int main()
{
    const int NB_VERTICES = 6;
    int **weights = initializeWeights();
    graph graphe = graph( NB_VERTICES, weights);
	graphe.showMinimalTreeFrom(0);
	while (true) {
		
	}
    return 0;
}