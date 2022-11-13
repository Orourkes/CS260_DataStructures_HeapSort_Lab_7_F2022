#pragma once
#include <string>
using namespace std;

class Node
{
private:
	int storedVal;
	Node* leftChild;
	Node* rightChild;

public:
	Node();
	Node(int value);
	~Node() {}

	int getValue() { return storedVal; }

	void setValue(int newVal) { storedVal = newVal; }

	Node* getLeft() { return leftChild; }

	Node* getRight() { return rightChild; }

	void setLeft(Node* newLeft) { leftChild = newLeft; }

	void setRight(Node* newRight) { rightChild = newRight; }

};