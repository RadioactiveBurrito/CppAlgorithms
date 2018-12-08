#ifndef PRIORITY_QUEUE
#endif
#include <vector>

template <class T>
class priority_queue
{
public:
	priority_queue(T **array = nullptr, int size = 0)
	{
		_elements.push_back(nullptr); //just to make computation of keys easier
		for (int i = 0; i < size; ++i)
		{
			_elements.push_back(array[i]);
		}
		_currentSize = size;
		heapify();
	}

	T *extract_min()
	{
		if (isEmpty())
		{
			return nullptr;
		}
		T *min = _elements[1];
		_elements[1] = _elements[_currentSize];
		_elements.pop_back();
		--_currentSize;
		if (_currentSize > 1) {
			percolateDown(1);
		}
		return min;
	}

	bool isEmpty()
	{
		return _currentSize == 0;
	}

	void heapify()
	{
		for (int i = _currentSize / 2; i > 0; --i)
		{
			percolateDown(i);
		}
	}

private:
	std::vector<T *> _elements;
	int _currentSize;

	void percolateDown(int hole)
	{
		int child;
		T *tmp = _elements[hole];

		for (; hole * 2 <= _currentSize; hole = child)
		{
			child = hole * 2;

			if (child != _currentSize && *_elements[child + 1] < *_elements[child])
			{
				++child;
			}
			if (*_elements[child] < *tmp)
			{
				_elements[hole] = _elements[child];
			}
			else
			{
				break;
			}
		}

		_elements[hole] = tmp;
	}
};