#pragma once

#include <iostream>
using namespace std;

//Review 1
// ADT  ： 二叉查找树
template<class Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() { root = NULL; }
	BinarySearchTree(const BinarySearchTree & rhs)
	{
		root = clone(rhs.root);
	}
	~BinarySearchTree()
	{
		makeEmpty();
		root = NULL;
	}

	const Comparable & findMin()const
	{
		BinaryNode * t = findMin(root);
		return t->element;
	}
	const Comparable & findMax()const
	{
		BinaryNode * t = findMax(root);
		return t->element;
	}
	bool contains(const Comparable &x)const
	{
		return contains(x, root);
	}
	bool isEmpty()const
	{
		return root == NULL;
	}
	void printTree()const
	{
		printTree(root);
	}

	void makeEmpty()
	{
		makeEmpty(root);
	}
	void insert(const Comparable & x)
	{
		insert(x,root);
	}
	void remove(const Comparable & x)
	{
		remove(x,root);
	}

	const BinarySearchTree & operator=(const BinarySearchTree & rhs)
	{
		if (this != &rhs)
		{
			makeEmpty();
			root = clone(rhs.root);
		}
		
		return *this;
	}

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode * left;
		BinaryNode * right;

		BinaryNode(const Comparable & ele, BinaryNode * lt, BinaryNode * rt) :element(ele), left(lt), right(rt)
		{}
	};

	BinaryNode * root;

	void insert(const Comparable &x, BinaryNode * & t)const
	{
		if (t == NULL)
			t = new BinaryNode(x,NULL,NULL);
		else if (x < t->element)
		{
			insert(x,t->left);
		}
		else if (x > t->element)
		{
			insert(x, t->right);
		}
		else
			;
		// using while
		//while (t != NULL)
		//{
		//	if (x < t->element)
		//		t = t->left;
		//	else if (x > t->element)
		//		t = t->right;
		//	else
		//		return;
		//}
		//t = new BinaryNode(x, NULL, NULL);
	}
	void remove(const Comparable &x, BinaryNode * & t)
	{
		if (t == NULL)
			return;
		else if (x < t->element)
		{
			remove(x,t->left);
		}
		else if (x > t->element)
		{
			remove(x, t->right);
		}
		// find x
		else if(t->left != NULL && t->right != NULL)
		{
			t->element = (findMin(t->right))->element;
			remove(t->element,t->right);
		}
		else
		{
			BinaryNode * old = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete old;
		}
	}
	BinaryNode * findMin(BinaryNode * t)const
	{
		if (t == NULL)
		{
			return NULL;
		}
		if (t->left == NULL)
			return t;
		else findMin(t->left);
	}
	BinaryNode * findMax(BinaryNode * t)const
	{
		if (t != NULL)
		{
			while (t->right != NULL)
			{
				t = t->right;
			}
		}
		return t;	
	}
	bool contains(const Comparable &x, BinaryNode * & t)const
	{
		if (NULL == t)
		{
			return false;
		}
		else if (x < t->element)
		{
			return contains(x,t->left);
		}
		else if (x > t->element)
		{
			return contains(x, t->right);
		}
		else
			return true;
	}
	void makeEmpty(BinaryNode *& t)
	{
		if(t != NULL)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}

		t = NULL;
	}
	void printTree(BinaryNode * t)const
	{
		// 中序遍历
		if (t != NULL)
		{
			cout << t->element << endl;
			printTree(t->left);
			printTree(t->right);
		}

	}
	BinaryNode * clone(BinaryNode * t) const
	{
		if (t == NULL)
			return NULL;

		return new BinaryNode(t->element,clone(t->left),clone(t->right));
	}

};

