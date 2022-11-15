#include <iomanip>
#include "Node.hpp"

Node::Node()
{
	storedVal = 0;
	rightChild = nullptr;
	leftChild = nullptr;
}
Node::Node(int value)
{
	storedVal = value;
	rightChild = nullptr;
	leftChild = nullptr;
}
