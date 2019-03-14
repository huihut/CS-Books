/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <functional>
using std::plus; using std::negate; using std::less_equal; 

#include <iostream>
using std::cout; using std::endl;

#include <algorithm>
using std::count_if; 

#include <vector>
using std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string; 

struct Size_compare {
	Size_compare(string::size_type i): sz(i) { }
	bool operator()(const string &s) { return s.size() >= sz; }
private:
	size_t sz;
};

struct LessVal {
	LessVal(int i): sz(i) { }
	bool operator()(int i) { return less_equal<int>()(i, sz); }
private:
	int sz;
};

int main() {

	cout << plus<int>()(3,4) << endl; // prints 7
	
	plus<int> intAdd;      // object that can add two int values
	negate<int> intNegate; // object that can negate an int value
	
	// uses intAdd::operator(int, int) to add 10 and 20
	int sum = intAdd(10, 20);         // equivalent to sum = 30
	cout << sum << endl;
	
	sum = intNegate(intAdd(10, 20));  // equivalent to sum = -30
	cout << sum << endl;
	
	// uses intNegate::operator(int) to generate -10 
	// as the second argument to intAdd::operator(int, int)
	sum = intAdd(10, intNegate(10));  // sum = 0
	
	cout << sum << endl;
	
	int vals[] = {0,1,2,3,4,5,16,17,18,19};
	
	// bind second argument to less_equal
	cout << count_if(vals, vals + sizeof(vals)/sizeof(*vals), 
					 LessVal(10));
	cout << endl;
	
	vector<string> svec;
	string in;
	while (cin >> in) 
		svec.push_back(in);

	cout << count_if(svec.begin(), svec.end(), Size_compare(6))
	     << endl;

	return 0;
}
