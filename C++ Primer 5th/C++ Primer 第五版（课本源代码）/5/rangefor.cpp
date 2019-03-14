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

// This file illustrates the range for statement, 
// which is a C++ 11 feature

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
	vector<int> ivec;
	// C++ code: list initialization
	//vector<int> v = {0,1,2,3,4,5,6,7,8,9};

	// replace with
	int temp[] = {0,1,2,3,4,5,6,7,8,9};
	// copy from first up to one past the last element from temp
	vector<int> v(temp, temp + sizeof(temp)/sizeof(*temp));

	// range variable must be a reference so we can write to the elements
	// C++11 code: range for statement
	// for (auto &r : v)   // for each element in v
		//r *= 2;         // double the value of each element in v

	// replace with traditional for loop:
	for (vector<int>::iterator r = v.begin(); r != v.end(); ++r)
		*r *= 2; // r is an iterator, *r is the element
	
	// print every element in v
	// C++11 code: range for statement
	//for (int r : v)
		//cout << r << " "; // print the elements in v

	for (vector<int>::const_iterator r = v.begin(); r != v.end(); ++r)
		cout << *r << " "; // print the elements in v
	cout << endl;

	return 0;
}
