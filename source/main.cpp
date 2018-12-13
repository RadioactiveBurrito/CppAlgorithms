#include <iostream>
#include "../header/graph.h"

using namespace std;
template <class T>
static void printTable(T** table, int height, int width) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}
template <class T>
static T** initializeTable(int height, int width) {
	T** table = new T*[height];
	for (int i = 0; i < height; ++i) {
		table[i] = new T[width];
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			table[i][j] = 0;
		}
	}

	return table;
}

template <class T>
static void deleteTable(int height, int width, T** table) {

}

static int lcsLength(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	int** lookupTable = initializeTable<int>(m + 1, n + 1);
	char** directions = initializeTable<char>(m, n);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s1[i] == s2[j]) {
				lookupTable[i+1][j+1] = lookupTable[i][j] + 1;
				directions[i][j] = '\\';
			}
			else if (lookupTable[i][j+1] >= lookupTable[i+1][j]) {
				lookupTable[i+1][j+1] = lookupTable[i][j+1];
				directions[i][j] = '|';
			}
			else {
				lookupTable[i+1][j+1] = lookupTable[i+1][j];
				directions[i][j] = '-';
			}
		}
	}

	printTable<int>(lookupTable, m + 1, n + 1);
	cout << endl;
	printTable<char>(directions, m, n);
	deleteTable<char>(m, n, directions);
	deleteTable<int>(m + 1, n + 1, lookupTable);
	return 0;
}

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

static void matrixChain(int dimensions[5]) {
	int NB_MATRICES = 5;
	int** costMatrix = initializeTable<int>(NB_MATRICES, NB_MATRICES);
	int** splitPoint = initializeTable<int>(NB_MATRICES, NB_MATRICES);

	for (int v = 2; v < NB_MATRICES; ++v) {
		for (int i = 1; i < NB_MATRICES - v + 1; ++i) {
			int j = i + v - 1;
			costMatrix[i][j] = 999999;

			for (int k = i; k <= j-1; ++k) {
				int q = costMatrix[i][k] + costMatrix[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
				if (q < costMatrix[i][j]) {
					costMatrix[i][j] = q;
					splitPoint[i][j] = k;
				}
			}
		}
	}

	printTable<int>(costMatrix, NB_MATRICES, NB_MATRICES);
	cout << endl;
	printTable<int>(splitPoint, NB_MATRICES, NB_MATRICES);
	deleteTable(NB_MATRICES, NB_MATRICES, costMatrix);
	deleteTable(NB_MATRICES, NB_MATRICES, splitPoint);
}


int main()
{
    const int NB_VERTICES = 6;
    int **weights = initializeWeights();
    graph graphe = graph( NB_VERTICES, weights);
	graphe.showMinimalTreeFrom(0);

	lcsLength("abba", "abat");
	int dimensions[5] = { 2, 4, 3, 6, 2 };
	matrixChain(dimensions);

	while (true) {
		
	}
    return 0;
}