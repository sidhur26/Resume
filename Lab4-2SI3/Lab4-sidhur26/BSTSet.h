#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>

class BSTSet
{
private:
	// must contain only one private field
	TNode* root = NULL;

public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();

	// required methods
	bool isIn(int v);
	void add(int v);
	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	// provided helper methods
	void printBSTSet(TNode* t);
	TNode* findMin(TNode* t);
	TNode* removeRecursion(int e, TNode* t);
	int sizeRecursion(TNode* t);
	int heightRecursion(TNode* t);
	void InOrderUnion(TNode* t);

};

#endif /* BSTSET_H_ */
