#include "HugeInteger.h"
#include<string>
#include <random>

HugeInteger::HugeInteger(const std::string& val) {
	// TODO

	if(val[0]==0){
		throw std::invalid_argument("Invalid Input");
	}
	if(val[0]== '-'){
		int i = 1;
		if(val[i]-48 > 0 && val[i] - 48 <= 9){
			huge_int.push_back(-(val[i]- 48));
		}
		else{
			throw std::invalid_argument("Invalid Input");
		}
		for(int i=2;i<val.size();i++){
			if(val[i]-48 >= 0 && val[i]- 48 <= 9){
				huge_int.push_back(val[i]- 48);

			}
			else{
				throw std::invalid_argument("Invalid Input");
			}
		}

	}
	else{
		for(int i = 0;i<val.size();i++){
			if(val[i]-48 > 0 && val[i]- 48 <= 9){
				huge_int.push_back(val[i]- 48);

			}
			else{
				throw std::invalid_argument("Invalid Input");
			}
		}

	}


}

HugeInteger::HugeInteger(int n) {
	// TODO
	if(n>=1){
		int random_int = rand() % 10 + 1;
		huge_int.push_back(random_int);
		for(int i = 1;i<n;i++){
			random_int = rand() % 10;
			huge_int.push_back(random_int);
		}
	}
	else{
		throw std::invalid_argument("Invalid Input");
	}
}

HugeInteger HugeInteger::add(const HugeInteger& h) {
	// TODO
/*
	int carry = 0;
	HugeInteger sum;
	if(huge_int.size() == h.huge_int.size()){
		for(int i = huge_int.size() - 1;i>=0;i--){
			sum.huge_int[i] == huge_int[i] + h.huge_int[i] + carry;
			if(sum.huge_int[i] > 9){
				sum.huge_int[i] %= 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		}
	}
	else if(huge_int.size() > h.huge_int.size()){
		for(int i =0;i<huge_int.size();i++){
			sum.huge_int[i] == huge_int[i];
		}
		for(int i = h.huge_int.size() - 1;i>=0;i--){
			sum.huge_int[i] += h.huge_int[i] + carry;
			if(sum.huge_int[i] > 9){
				sum.huge_int[i] %= 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		}
	}
	else{
		for(int i =0;i<h.huge_int.size();i++){
			sum.huge_int[i] == h.huge_int[i];
		}
		for(int i = huge_int.size() - 1;i>=0;i--){
			sum.huge_int[i] += huge_int[i] + carry;
			if(sum.huge_int[i] > 9){
				sum.huge_int[i] %= 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		}
	}
*/
	return HugeInteger("");
}

HugeInteger HugeInteger::subtract(const HugeInteger& h) {
	// TODO
	return HugeInteger("");
}

HugeInteger HugeInteger::multiply(const HugeInteger& h) {
	// TODO
	return HugeInteger("");
}

int HugeInteger::compareTo(const HugeInteger& h) {
	// TODO
	return 0;
}

std::string HugeInteger::toString() {
	// TODO
	std::string output;
	for(int i=0;i<huge_int.size();i++){
		output += std::to_string(huge_int[i]);
	}

	return output;
}
