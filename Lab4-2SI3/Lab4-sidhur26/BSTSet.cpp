#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;

BSTSet::BSTSet()
{
	// TODO
	root = NULL;
}

BSTSet::BSTSet(const std::vector<int>& input)
{
	// TODO, change following code after completing this function
	root = NULL;
	for(int i=0;i<input.size();i++){
		add(input[i]);
	}
}

BSTSet::~BSTSet()
{
	// TODO

}

bool BSTSet::isIn(int v)
{
	// TODO
	TNode* ptr = root;
	while(ptr!=NULL){
		if(v < ptr->element){
			ptr = ptr->left;
		}
		else if(v > ptr->element){
			ptr = ptr->right;
		}
		else{
			return true;
		}
	}

    return false; //change this after completing this function

// Time: n
// Space: n
}

void BSTSet::add(int v)
{
	// TODO
	if(root == NULL){
		root = new TNode(v,NULL,NULL);
		return;
	}
	TNode* ptr = root;
	TNode* ptr2 =  NULL;
	while(ptr!=NULL){
		ptr2 = ptr;
		if(v < ptr->element){
			ptr = ptr->left;
		}
		else if(v>ptr->element){
			ptr = ptr->right;
		}
		else{
			return;
		}
	}
	if(v < ptr2->element){
		ptr2->left = new TNode(v,NULL,NULL);
	}
	else if (v>ptr2->element){
		ptr2->right = new TNode(v,NULL,NULL);
	}

// Time: n
// Space: 2n
}

bool BSTSet::remove(int v)
{
	// TODO
	if(!isIn(v)){
		return false;
	}
//	else{
//		removeRecursion(v,root);
//	}

    return true; //change this after completing this function
}

void BSTSet::Union(const BSTSet& s)
{
	// TODO
	InOrderUnion(s.root);

// Time: n^2
// Space: 2n
}

void BSTSet::intersection(const BSTSet& s)
{
	// TODO
}

void BSTSet::difference(const BSTSet& s)
{
	// TODO
}

int BSTSet::size()
{
	// TODO
	return sizeRecursion(root);

// Time: n
// Space: 1
}

int BSTSet::height()
{
	// TODO
	return heightRecursion(root);

// Time: n
// Space: 1
}

// create and use class MyStack
void BSTSet::printNonRec()
{
	// TODO
	if (root == NULL){
		std::cout << "";
	}

}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
TNode* BSTSet::findMin(TNode* t)
{

	if(t == NULL){
		return NULL;
	}
	while(t->left != NULL){
		t = t->left;
	}
	return t;

}
TNode* BSTSet::removeRecursion(int e, TNode* t)
{
	if(t == NULL){
		return NULL;
	}
	if(e < t->element){
		removeRecursion(e,t->left);
	}
	else if(e > t->element){
		removeRecursion(e,t->right);
	}
	else if(t->left != NULL && t->right != NULL){
		t->element = findMin(t->right)->element;
		removeRecursion(t->element, t->right);
	}
	else{
		TNode* oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;

	}
	return t;

}
int BSTSet::sizeRecursion(TNode* t){
	if(t == NULL){
		return 0;
	}
	else{
		return(sizeRecursion(t->left)+sizeRecursion(t->right)+1);
	}
}
int BSTSet::heightRecursion(TNode* t)
{
	if(t == NULL){
		return -1;
	}
	else{
		int left_height = heightRecursion(t->left);
		int right_height = heightRecursion(t->right);

		if(left_height > right_height){
			return(left_height + 1);
		}
		else{
			return(right_height+1);
		}
	}

}
void BSTSet::InOrderUnion(TNode* t)
{
	if(t == NULL){
		return;

	}
	if(t->left != NULL){
		InOrderUnion(t->left);
	}

	this->add(t->element);



	if(t->right != NULL){
		InOrderUnion(t->right);
	}

}
