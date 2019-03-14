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

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

#include <sstream>
using std::ostringstream;

// chapter 7 will explain the code used in defining ErrCode
struct ErrCode { 
	ErrCode(int i) : num(i) { }  // initializes objects of type ErrCode
	string msg()                 // member function of ErrCode
	{ ostringstream s; s << "ErrCode " << num; return s.str(); }
	int num;  // data member, note uninitialized
};

// this file originally demonstrated initializer_list parameters,
// which is a C++ 11 library type
// this version replaces the initializer_list by pointers to a range of strings
void error_msg(ErrCode e, const string *beg, const string *end)
{
	cout << e.msg() << ": ";
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}

// overloaded version that takes only pointers to a range of strings
void error_msg(const string *beg, const string *end)
{
	while (beg != end)
		cout << *beg++ << " " ;
	cout << endl;
}

// function to illustrate list initializing return value
vector<string> functionX()
{
	string expected = "description", actual = "some other case";
	// . . .
	vector<string> retVals; // local variable that we'll return
	if (expected.empty())
		return retVals;  // return an empty vector
	else if (expected == actual) {
		retVals.push_back("functionX"); // build the vector 
		retVals.push_back("okay");
		return retVals;                 // and return it 
	} else {
		retVals.push_back("functionX");
		retVals.push_back(expected);
		retVals.push_back(actual);
		return retVals;  // return the vector
	}
}
	
int main()
{
	string expected = "description", actual = "some other case";
	vector<int> li;
	for (int i = 0; i < 4; ++i)
		li.push_back(i);

	// expected, actual are strings 
	if (expected != actual)
		{ const string arr[] = {"functionX", expected, actual};
		  error_msg(arr, arr + sizeof(arr)/sizeof(*arr)); }
	else
		{ static const string arr[] = {"functionX", "okay"};
		  error_msg(arr, arr + sizeof(arr)/sizeof(*arr)); }

	// expected, actual are strings 
	if (expected != actual)
		{ const string arr[] = {"functionX", expected, actual};
		  error_msg(ErrCode(42), arr, arr + sizeof(arr)/sizeof(*arr)); }
	else
		{ static const string arr[] = {"functionX", "okay"};
		  error_msg(ErrCode(0), arr, arr + sizeof(arr)/sizeof(*arr)); }
	
	// can pass an empty list, calls second version of error_msg
	error_msg(0, 0);   // prints blank line

	// call function that list initializes its return value
	// results is a vector<string>
	vector<string> results = functionX();
	for (vector<string>::const_iterator i = results.begin();
				i != results.end(); ++i) 
		cout << *i << " ";
	cout << endl;
}

