#include "Poly.h"
#include <iostream>
#include <cmath>

using namespace std;

Poly::Poly() {
	head = new PolyNode(-1, 0, NULL);
}

Poly::Poly(const std::vector<int> &deg, const std::vector<double> &coeff) {
	head = new PolyNode(-1, 0, NULL);
	PolyNode *currNode = head;

	for (long long unsigned int i = 0; i < deg.size(); i++) {
		currNode->next = new PolyNode(deg[i], coeff[i], NULL);
		currNode = currNode->next;
	}
}

Poly::~Poly() {
	PolyNode *delNode = head;
	while (delNode != NULL) {
		PolyNode *temp = delNode->next;
		delete delNode;
		delNode = temp;
	}
}

void Poly::addMono(int i, double c) {
	if (c != 0.0) {
		bool flag = 0;
		PolyNode *currNode = head;

		while (currNode->next != NULL) {

			if (currNode->next->deg > i) {
				currNode = currNode->next;
			} else if (currNode->next->deg == i) {

				if (currNode->next->coeff + c == 0) {
					currNode->next = currNode->next->next;
				} else {
					currNode->next->coeff += c;
				}

				flag = 1;
				break;
			} else if (currNode->next->deg < i) {

				PolyNode *temp = new PolyNode(i, c, NULL);
				temp->next = currNode->next;
				currNode->next = temp;

				flag = 1;
				break;
			}
		}

		if (!flag) { //if no nodes were added
			currNode->next = new PolyNode(i, c, NULL);
		}
	}
}
//	Time: n
//	Space: n+1

void Poly::addPoly(const Poly &p) {
	PolyNode *currNode = p.head;

	while (currNode->next != NULL) {
		addMono(currNode->next->deg, currNode->next->coeff);
		currNode = currNode->next;
	}
}
//	Time: n^2
//	Space: 2n

void Poly::multiplyMono(int i, double c) {
	if (c == 0.0) {
		head->next = NULL;
	} else {
		PolyNode *currNode = head;

		while (currNode->next != NULL) {
			currNode->next->deg = currNode->next->deg + i;
			currNode->next->coeff = currNode->next->coeff * c;

			currNode = currNode->next;
		}
	}
}
//Time: n
//Space: n

void Poly::multiplyPoly(const Poly &p) {
	PolyNode *currNode = head;
	PolyNode *pMult = p.head;
	Poly newPoly = Poly();

	while (currNode->next != NULL) {

		while (pMult->next != NULL) {

			if (currNode->next->deg + pMult->next->deg != 0) {
				newPoly.addMono(currNode->next->deg + pMult->next->deg,
						currNode->next->coeff * pMult->next->coeff);
			}

			pMult = pMult->next;
		}

		pMult = p.head;
		currNode = currNode->next;
	}
	newPoly.duplicate(*this);
}
//Time: n^3
//Space: 3n

void Poly::duplicate(Poly &outputPoly) {

	PolyNode *currNode = head;

	outputPoly.head = new PolyNode(-1, 0, NULL);
	PolyNode *currCopy = outputPoly.head;

	while (currNode->next != NULL) {

		if (currCopy->next == NULL) {
			currCopy->next = new PolyNode(-1, 0, NULL);
		}

		currCopy->next->deg = currNode->next->deg;
		currCopy->next->coeff = currNode->next->coeff;
		currNode = currNode->next;
		currCopy = currCopy->next;
	}
}
// Time: n
// Space: 2n

int Poly::getDegree() {
	if (head->next != NULL) {
		return head->next->deg;
	} else {
		return -1;
	}
}
// Time: 1
// Space: 1

int Poly::getTermsNo() {
	int counter = 0;
	PolyNode *currNode = head;

	if (currNode->next == NULL) {
		return 0;
	} else {
		while (currNode->next != NULL) {
			currNode = currNode->next;

			if (currNode->deg == -1) {
				return 0;
			}

			counter++;
		}
		return counter;
	}
}
// Time: n
// Space: n+1

double Poly::evaluate(double x) {
	double result = 0;
	PolyNode *currNode = head;

	while (currNode->next != NULL) {

		result += currNode->next->coeff * pow(x, currNode->next->deg);

		currNode = currNode->next;
	}
	return result;
}

std::string Poly::toString() {
	string str = "";
	PolyNode *currNode = head;

	while (currNode->next) {
		str += to_string(currNode->next->coeff) + " ";
	}

	str += "; deg: " + to_string(getDegree());

	return str;
}
