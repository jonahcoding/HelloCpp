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
		GetRandomNumbers grn(1, 15, 15, GRN_REPEAT, GRN_ORDER, GRN_DESCEND);
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

		bst.levelOrder();
		bst.preOrder();
		bst.inOrder();
		bst.postOrder();
		bst.preOrderNR();
		bst.inOrderNR();
		bst.postOrderNR();

		cout << "�Ƿ���Ԫ��8�� " << bst.contains(8) << endl;
		bst.preOrder();
		bst.inOrder();
		bst.remove(8);
		cout << "�Ƿ���Ԫ��8�� " << bst.contains(8) << endl;
		bst.preOrder();
		bst.inOrder();
		bst.add(16);
		bst.preOrder();
		bst.inOrder();

		cout << endl;

		cout << "====================" << endl;
		cout << endl;
	}
};
