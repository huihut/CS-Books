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

#include <algorithm>
using std::find;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	int ia[] = {27, 210, 12, 47, 109, 83};
	const int iaSz = sizeof(ia)/sizeof(*ia);
	int val = 83;
	int* result = find(ia, ia + iaSz, val);
	cout << "The value " << val
	     << (result == ia + iaSz
	           ? " is not present" : " is present") << endl;
	
	// search starting from ia[1] up to but not including ia[4]
	result = find(ia + 1, ia + 4, val);
	
	 // initialize the vector with some values
	vector<int> vec(ia, ia + sizeof(ia)/sizeof(*ia));
	val = 42; // value we'll look for

	// result2 will denote the element we want if it's in vec, 
	// or vec.end() if not
	vector<int>::const_iterator result2 = 
			find(vec.begin(), vec.end(), val);

	// report the result
	cout << "The value " << val
	     << (result2 == vec.end()
	           ? " is not present" : " is present") << endl;
	
	// now use find to look in a list of strings
	list<string> lst;
	lst.push_back("val1");
	lst.push_back("val2");
	lst.push_back("val3");

	string sval = "a value";  // value we'll look for
	// this call to find looks through string elements in a list
	list<string>::const_iterator result3 = 
			find(lst.begin(), lst.end(), sval);
	cout << "The value " << sval
	     << (result3 == lst.end()
	           ? " is not present" : " is present") << endl;

	return 0;
}
	
