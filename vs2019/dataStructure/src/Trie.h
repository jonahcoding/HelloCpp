#pragma once

#include <iostream>
#include <string>

#include "TrieNode.h"

class Trie
{
public:
	Trie() { m_size = 0; }
	int size() const { return m_size; }
	bool isEmpty() const { return m_size == 0; }

	void add(std::string word)
	{
		TrieNode* cur = &root;
		for (int i = 0; i < word.size(); i++)
		{
			char c = word[i];
			if (!cur->next->contains(c)) {
				TrieNode* node = new TrieNode;
				cur->next->add(c, node);
			}
			cur = cur->next->get(c);
		}
		if (!cur->isWord)
		{
			cur->isWord = true;
			m_size++;
		}
	}

	bool contains(std::string word)
	{
		TrieNode* cur = &root;
		for (int i = 0; i< word.size(); i++)
		{
			char c = word[i];
			if (!cur->next->contains(c))
			{
				return false;
			}
			cur = cur->next->get(c);
		}
		return cur->isWord;
	}

	bool isPrefix(std::string prefix)
	{
		TrieNode* cur = &root;
		for (int i = 0; i < prefix.size(); i++)
		{
			char c = prefix[i];
			if (!cur->next->contains(c))
			{
				return false;
			}
			cur = cur->next->get(c);
		}
		return true;
	}

private:
	TrieNode root;
	int m_size;
};
