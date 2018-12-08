#ifndef VERTEX_H
#endif
#include <limits>
#include <vector>

class vertex
{
public:
	static const int NOT_CONNECTED = -1;
	static const int UNKNOWN_DISTANCE = INT_MAX;

	vertex(vertex *previous, int distance, int id);
	vertex(vertex *toCopy);
	vertex();

	vertex *getPrevious();
	int getDistance();
	int getId();
	std::vector<vertex*> getNeighbors(int **weights, vertex ** vertices, int nbVertices);
	bool operator<(const vertex &v);//omparison with distance
	bool operator>(const vertex &v);//comparison with distance
	bool operator==(const vertex &v);//comparison with id
	bool operator!=(const vertex &v);//compares with id

	void setPrevious(vertex *previous);
	void setDistance(int distance);

private:
	vertex *_previous; //necessary for the object to have finite size.
	int _distance;
	int _id;
};