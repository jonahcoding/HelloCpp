#pragma once

#include "BSTMap.h"

class TrieNode
{
public:
	TrieNode(bool isWord = false)
	{
		this->isWord = isWord;
		BSTMap<char, TrieNode*>* p = new  BSTMap<char, TrieNode*>;
		next = p;
	}

	TrieNode operator= (TrieNode & node)
	{
		this->isWord = node.isWord;
		this->next = node.next;
		return *this;
	}

public:
	bool isWord;
	BSTMap<char, TrieNode*>* next;
};
