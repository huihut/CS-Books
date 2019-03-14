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

// This file was revised to eliminate forward declarations
// and scoped enums, both of which are C++ 11 features

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

enum open_modes {input, output, append};

// input is an enumerator of open_modes
open_modes om = input; 

enum intTypes {
	charTyp = 8, shortTyp = 16, intTyp = 16, 
	longTyp = 32, long_longTyp = 64
};

const intTypes charbits = charTyp;

enum intValues {
	charVal = 255, shortVal = 65535, intVal = 65535, 
	longVal = 4294967295UL, 
	long_longVal = 18446744073709551615ULL
};

int main() 
{
	enum color {red, yellow, green};   // unscoped enumeration 
	// enumerators changed to avoid conflict with those in color
	enum peppers {redPep, yellowPep, greenPep};
	
	// unnamed, unscoped enum
	enum {floatPrec = 6, doublePrec = 10, double_doublePrec = 10};
	
	// enumerators are in scope for an unscoped enumeration
	color eyes = green; 
	
	color hair = red;   // we can explicitly access the enumerators
	peppers p2 = redPep; // using red from peppers 
	
	int i = red;   // unscoped enumerator implicitly converted to int
	
	// point2d is 2, point2w is 3, point3d is 3, point3w is 4
	enum Points { point2d = 2, point2w,
	              point3d = 3, point3w };

	return 0;
}
