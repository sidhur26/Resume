/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize;          // initializes size as the size of the array

	SLLNode *endNode = new SLLNode(sortedArray[arrSize-1],NULL);   // creates a new node with the last elemnt in the array and point to NULL
	
	head = endNode;          // sets this node as the head


	for(int i = arrSize-2;i>=0;i--){
		SLLNode *newNode = new SLLNode(sortedArray[i],head);   // iterates from second last element of array to first element and creates nodes
		head = newNode;  // updates head to the first element in the array
	}

}
int SLLSet::getSize()
{
	
	//fixME
	return size;          // returns the size of the set
}
SLLSet SLLSet::copy()
{
	
	//fixME
	int new_arr[size];        // creates an array with the same size as the set
	int i =0;
	SLLNode* curr = head;
	while(curr!= NULL){
		new_arr[i] = curr->value;    // puts each element from the set into array
		curr = curr->next;           // iterates through the set
		i++;
	}
	return *(new SLLSet(new_arr,size));   // returns a identical new set using the new array and size
}
bool SLLSet::isIn(int v)
{
    //fixME
	SLLNode* curr = head;
	while(curr!=NULL){
		if(curr->value==v){     // checks if the value is in the set
			return true;
		}
		curr=curr->next;        // iterates through the set
	}
	return false;
}
void SLLSet::add(int v)
{
	SLLNode* curr = head;
	SLLNode* insert = new SLLNode(v,NULL);
	if(isIn(v) == false){                   // checks if element is already in set
		if(curr==NULL){                     //checks if its an empty set
			head = insert;                  // adds element to empty set as the head
		}
		for(curr=head;curr!=NULL;curr=curr->next){
			if(curr->value < v && curr->next != NULL && curr->next->value > v){  // checks if element needs to be added in the middle
				insert->next = curr->next;
				curr->next = insert;
				break;
			}
			if(curr->value < v && curr->next == NULL){   // checks if element needs to be added at the end
				curr->next = insert;
				insert->next = NULL;
			}
			if(curr->value > v && curr==head){          // checks if element needs to be added at the start
				insert->next = head;
				head = insert;
				break;
			}

		}
		size++;           // increments the size
	}
}
void SLLSet::remove(int v)
{
	SLLNode* prev = head;
	SLLNode* curr = prev->next;

	if(head->value==v){      // checks if the first element needs to be removed
		head = head->next;
		size--;              // decreases the size

	}
	while(curr!=NULL){
		if(curr->value==v){            // checks if value being removed is in the set
			prev->next = curr->next;
			size--;                    // decreases the size

		}
		curr = curr->next;
		prev = prev->next;
	}
   
}
SLLSet SLLSet::setUnion(SLLSet s)
{
    	//fixME
	SLLSet union_set = SLLSet();     // creates an empty union set
	SLLNode* curr = head;
	SLLSet input = s;
	SLLNode* curr_input = input.head;

	for(int i =0;i<size;i++){              // loops through the first set
		if(s.isIn(curr->value)==false){    // checks if element is not in the input set
			union_set.add(curr->value);    // adds elements not in the input set into the union set
		}
		curr= curr->next;
	}
	for(int i =0;i<s.size;i++){              // loops through the input set
		union_set.add(curr_input->value);    // adds each element to union set
		curr_input= curr_input->next;
	}



	 return union_set;
}
SLLSet SLLSet::intersection(SLLSet s)
{
    	//fixME
	SLLSet intersection = SLLSet();   // creates an empty intersection set
	SLLNode* curr = head;

	for(int i = 0;i<size;i++){
		if(s.isIn(curr->value)==true){      // check if element is in both sets
			intersection.add(curr->value);  // adds elements to intersection set if in both sets
		}
		curr = curr->next;
	}



	 return intersection;
}
SLLSet SLLSet::difference(SLLSet s)
{
    	//fixME
	SLLSet diff = SLLSet();         // creates an empty difference set
	SLLNode* curr = head;


	for(int i = 0;i<size;i++){
		if(s.isIn(curr->value)==false){   // checks if element is not in the input set
			diff.add(curr->value);        // adds elements not in the input set
		}
		curr = curr->next;
	}



	 return diff;
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
    	//fixME
	SLLSet list =  SLLSet();               // creates an empty set
	for(int i =0 ;i<size;i++){             // loops through the array of sets
		list = list.setUnion(sArray[i]);   // updates the empty set with the union of the sets in the array
	}
	 return list;
}
string SLLSet::toString()
{

   //fixME
	string output = "";           // creates an empty string
	SLLNode* curr = head;
	for(curr=head;curr!=NULL;curr=curr->next){
		output += to_string(curr->value);     // converts each element to string and adds to the output
		if(curr->next != NULL){               // checks if element is not last
			output += ", ";                   // separates element with a comma and a space
		}

	}



   return output;
}

