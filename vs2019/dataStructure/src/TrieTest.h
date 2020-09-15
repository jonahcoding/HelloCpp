#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Trie.h"

class TrieTest
{
public:
	TrieTest()
	{
		cout << "====================" << endl;
		cout << "Tire Test!" << endl;
		cout << "--------------------" << endl;

		Trie trie;

		string str1 = "China";
		string str2 = "Chinese";
		string str3 = "Ch";
		string str4 = "Jonah";

		trie.add(str1);
		trie.add(str2);
		trie.add(str3);
		cout << "Does it exist the word 'China' £º ";
		if (trie.contains(str2))
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;

		cout << "Does it exist the prefix 'Ch' £º ";
		if (trie.isPrefix(str3))
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;

		cout << "The trie is empty £º ";
		if (trie.isEmpty())
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;
		cout << "The size of trie :  " << trie.size() << endl;

		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}

};
