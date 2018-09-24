#pragma once

#include "std.hxx"


class AVLNode
{
public:
	AVLNode(int value) : data(value) { }
	int data;
	AVLNode* left;
	AVLNode* right;
};

class AVL
{
public:
	typedef std::function<void(const AVLNode*)> visitor_t;

	AVL();
	~AVL();

	void insert(int);
	void destroy();

	void preorder(const visitor_t& func) const;

	std::string to_graphviz() const;

private:
	void insert(AVLNode* node, int value);
	void preorder(AVLNode* node, const visitor_t& func) const;

	AVLNode* root_;

};
