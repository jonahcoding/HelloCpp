#pragma once

#include <list>
#include "BST.h"
#include "GetRandomNumbers.h"

class BSTTest
{
public:
	BSTTest()
	{
		vector<int> vGRN;
		bool GRN_REPEAT = false;
		bool GRN_ORDER = false;
		bool GRN_DESCEND = false;
		GetRandomNumbers grn(0, 100, 15, GRN_REPEAT, GRN_ORDER, GRN_DESCEND);
		vGRN = grn.getGRN();

		cout << "====================" << endl;
		cout << "BST Test!" << endl;
		cout << "--------------------" << endl;

		BST<int> bst;
		cout << "Binary Search Tree Is Empty? " << bst.isEmpty() << endl;
		
		for (vector<int>::iterator it = vGRN.begin(); it != vGRN.end(); it++)
		{
			bst.add(*it);
		}

		cout << "Binary Search Tree ´óÐ¡£º" << bst.size() << endl;
		bst.levelOrder();
		bst.preOrder();
		bst.preOrderNR();
		bst.inOrder();
		bst.inOrderNR();
		bst.postOrder();
		bst.postOrderNR();
		
		cout << endl;
		cout << "====================" << endl;
		cout << endl;
	}
};
