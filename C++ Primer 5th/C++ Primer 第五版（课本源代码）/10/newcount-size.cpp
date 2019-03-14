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
using std::find_if; using std::for_each;
using std::sort; using std::stable_sort; 
using std::unique; 

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "make_plural.h"

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

// determine whether a length of a given word is 6 or more
bool GT(const string &s, string::size_type m) 
{
    return s.size() >= m;
}

/* we'll explain this class in chapter 14,
 * the thing to know now, is that we can call an
 * object of type Shorter passing it a string
 * and that will execute the body of the the
 * function named operator(), which means that
 * calling an object of type Shorter will compare
 * the size of the given string with the value stored
 * in sz.  For example:
 * 		Shorter foobar(6);
 * 		string s = "something or another";
 * 		foobar(s); // will return true, because s.size() >= 6
*/
class Shorter {
public:
	Shorter(size_t i): sz(i) { }
	bool operator()(const string &s1) 
	{ return s1.size() >= sz; }
private:
	size_t sz;
};


void print(const string &s)
{
	cout << s << " ";
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
	for_each(words.begin(), words.end(), print);
	cout << endl;

    // unique reorders the input so that each word appears once in the
    // front part of the range 
	// returns an iterator one past the unique range
    vector<string>::iterator end_unique = 
					unique(words.begin(), words.end());
	for_each(words.begin(), words.end(), print);
	cout << endl;

    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());

	for_each(words.begin(), words.end(), print);
	cout << endl;
}

void 
biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words); // put words in alphabetical order and remove duplicates
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(), isShorter);

	// get an iterator to the first element whose size() is >= sz
    vector<string>::iterator wc = 
			find_if(words.begin(), words.end(), Shorter(sz));

	// compute the number of elements with size >= sz 
	vector<string>::size_type count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

	// print words of the given size or longer, each one followed by a space
	for_each(wc, words.end(), print);
	cout << endl;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }

	biggies(words, 5); // biggies changes its first argument

	return 0;
}
