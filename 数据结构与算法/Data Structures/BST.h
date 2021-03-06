#pragma once

#include "BTNode.h"
#include "LoopQueue.h"
#include "ArrayStack.h"

template<class T>
class BST
{
public:
	BST() { root = NULL; m_size = 0; }
	void add(T num);
	void remove(T num);
	bool contains(T num);
	void preOrder();
	void inOrder();
	void postOrder();
	void preOrderNR();
	void inOrderNR();
	void postOrderNR();
	void levelOrder();
	int size() { return m_size; }
	bool isEmpty() { return m_size == 0; };
private:
	BTNode<T>* add(BTNode<T> *node, T num);
	BTNode<T>* remove(BTNode<T> *node, T num);
	bool contains(BTNode<T> *node, T num);
	void preOrder(BTNode<T> *node);
	void inOrder(BTNode<T> *node);
	void postOrder(BTNode<T> *node);
private:
	BTNode<T> *root;
	int m_size;
};

template<class T>
inline void BST<T>::add(T num)
{
	root = add(root, num);
}

template<class T>
inline void BST<T>::remove(T num)
{
	root = remove(root, num);
}

template<class T>
inline bool BST<T>::contains(T num)
{
	return contains(root, num);
}

template<class T>
inline void BST<T>::preOrder()
{
	cout << "Binary Serch Tree: " << "Size = " << m_size << endl;
	cout << "���������";
	preOrder(root);
	cout << endl;
}

template<class T>
inline void BST<T>::inOrder()
{
	cout << "Binary Serch Tree: " << "Size = " << m_size << endl;
	cout << "���������";
	inOrder(root);
	cout << endl;
}

template<class T>
inline void BST<T>::postOrder()
{
	cout << "Binary Serch Tree: " << "Size = " << m_size << endl;
	cout << "���������";
	postOrder(root);
	cout << endl;
}

template<class T>
inline void BST<T>::preOrderNR()
{
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "����������ǵݹ飩��";
	ArrayStack<BTNode<T> *> s;
	s.push(root);
	while (!s.isEmpty())
	{
		BTNode<T> *node = s.peek();
		cout << node->m_data << "  ";
		s.pop();
		if (node->right != NULL)
		{
			s.push(node->right);
		}
		if (node->left != NULL)
		{
			s.push(node->left);
		}
	}
	cout << endl;
}

template<class T>
inline void BST<T>::inOrderNR()
{
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "����������ǵݹ飩��";
	ArrayStack<BTNode<T>*> s;
	BTNode<T> *node = root;
	while (node != NULL || !s.isEmpty()) 
	{
		while (node != NULL) 
		{
			s.push(node);
			node = node->left;
		}
		node = s.peek();
		cout << node->m_data << "  ";
		s.pop();
		if (node->right != NULL) 
		{
			node = node->right;
		}
		else 
		{
			node = NULL;
		}
	}
	cout << endl;
}

template<class T>
inline void BST<T>::postOrderNR()
{
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "����������ǵݹ飩��";
	ArrayStack<BTNode<T>*> s;
	BTNode<T> *node = root;
	BTNode<T> *lastVisited = root;
	while (node != NULL || !s.isEmpty()) 
	{
		while (node != NULL) 
		{
			s.push(node);
			node = node->left;
		}
		node = s.peek();
		if (node->right != NULL && lastVisited != node->right)
		{
			node = node->right;
		}
		else 
		{
			lastVisited = node;
			cout << node->m_data << "  ";
			s.pop();
			node = NULL;
		}
	}
	cout << endl;
}

template<class T>
inline void BST<T>::levelOrder()
{
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "���������";
	LoopQueue<BTNode<T>*> q;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		BTNode<T> *node = q.front();
		cout << node->m_data << " ";
		q.dequeue();
		if (node->left != NULL)
		{
			q.enqueue(node->left);
		}
		if (node->right != NULL)
		{
			q.enqueue(node->right);
		}
	}
	cout << endl;
}

template<class T>
inline BTNode<T>* BST<T>::add(BTNode<T>* node, T num)
{
	if (node == NULL)
	{
		m_size++;
		return new BTNode<T>(num);
	}
	else if (num < node->m_data)
	{
		node->left = add(node->left, num);
	}
	else if (num > node->m_data)
	{
		node->right = add(node->right, num);
	}
	return node;
}

template<class T>
inline BTNode<T>* BST<T>::remove(BTNode<T>* node, T num)
{
	if (node == NULL)
	{
		return node;
	}
	if (num < node->m_data)
	{
		node->left = remove(node->left, num);
	}
	else if (num > node->m_data)
	{
		node->right = remove(node->right, num);
	}
	else if (num == node->m_data)
	{
		if (node->left == NULL)
		{
			BTNode<T> *rightNode = node->right;
			delete node;
			m_size--;
			return rightNode;
		}
		if (node->right == NULL)
		{
			BTNode<T> *leftNode = node->left;
			delete node;
			m_size--;
			return leftNode;
		}
		else
		{
			BTNode<T> *minNode = node->right;
			for (; minNode->left; minNode = minNode->left);
			node->m_data = minNode->m_data;
			node->right = remove(node->right, minNode->m_data);
			return node;
		}
	}
	return node;
}

template<class T>
inline bool BST<T>::contains(BTNode<T>* node, T num)
{
	if (node == NULL)
	{
		return false;
	}
	if (num == node->m_data)
	{
		return true;
	}
	else if (num < node->m_data)
	{
		return contains(node->left, num);
	}
	else
	{
		return contains(node->right, num);
	}
	return false;
}

template<class T>
inline void BST<T>::preOrder(BTNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->m_data << "  ";
	preOrder(node->left);
	preOrder(node->right);
}

template<class T>
inline void BST<T>::inOrder(BTNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}
	inOrder(node->left);
	cout << node->m_data << "  ";
	inOrder(node->right);
}

template<class T>
inline void BST<T>::postOrder(BTNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->m_data << "  ";
}
