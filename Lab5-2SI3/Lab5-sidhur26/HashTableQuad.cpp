#include "HashTableQuad.h"
#include <iostream>
using namespace std;

HashTableQuad::HashTableQuad(int maxNum, double load)
{
    // TODO
	double exact_size = maxNum/load;
	max_load = load;
	max_keys = maxNum;
	size = maxNum/load;
	keys = 0;
	if(exact_size != size){
		size++;
	}
	while(is_prime(size)!= true){
		size++;
	}
	for(int i = 0;i<size;i++){
		table.push_back(0);
	}
}

void HashTableQuad::insert(int n)
{
    // TODO
	if(keys + 1  > max_keys){
		rehash();
	}
	int i = n % size;
	if(table[i] == 0){
		table[i] = n;
		keys++;
	}
	else if(table[i] == n){
		return;
	}
	else{
		for(int j = 0;j<size;j++){
			int k = (i + j*j) % size;
			if(table[k] == n){
				return;
			}
			 if(table[k] == 0){
				 table[k] = n;
				 keys++;
				 break;
			 }
		}
	}
}

void HashTableQuad::rehash()
{
    // TODO
	int orig_size = max_keys/max_load;
	double size_double = max_keys/max_load;
	if(size_double != orig_size){
		orig_size++;
	}
	while(is_prime(orig_size)!= true ){
		orig_size++;
	}
	int new_size = 2 * orig_size;
	while(is_prime(new_size) != true){
		new_size++;
	}
	std::vector<int> new_table;
	for(int i = 0;i<new_size;i++){
		new_table.push_back(0);
	}
	std::vector<int> temp;
	for(int i =0;i<size;i++){
		if(table[i] != 0){
			temp.push_back(table[i]);
		}
	}
	table = new_table;
	size = new_size;
	keys = 0;
	for(int i =0;i<temp.size();i++){
		insert(temp[i]);
	}
}

bool HashTableQuad::isIn(int n)
{
    // TODO, change following code after completing this function
	int i = n % size;
	if(table[i] == n){
		return true;
	}
	else{
		for(int j = 0;j<size;j++){
			int k = (i + j*j) % size;
			if(table[k] == n){
				return true;
			}
		}

	}

    return false;
}
// Runtime: n
// Space: 1

void HashTableQuad::printKeys()
{
    // TODO
	for(int i = 0;i<table.size();i++){
		if(table[i] != 0){
			std::cout << table[i];
			std::cout << " ";
		}
	}
}

void HashTableQuad::printKeysAndIndexes()
{
    // TODO
	for(int i = 0;i<table.size();i++){
		if(table[i] != 0){
			std::cout << "Index: ";
			std::cout << i;
			std::cout << "Key: ";
			std::cout << table[i];
			std::cout << " ";
		}
	}
}

int HashTableQuad::getNumKeys() {
	// TODO, change following code after completing this function
    return keys;
}

int HashTableQuad::getTableSize() {
	// TODO, change following code after completing this function
    return size;
}

double HashTableQuad::getMaxLoadFactor() {
	// TODO, change following code after completing this function
    return max_load;
}

std::vector<double> HashTableQuad::simProbeSuccess()
{
    // TODO, change following code after completing this function
    vector<double> result(9);
    return result;
}
bool HashTableQuad::is_prime(int x){

	if(x == 1 || x == 0){
		return false;
	}
	for(int i = 2;i <= x/2;i++){
		if(x%i == 0){
			return false;
		}
	}
	return true;

}
