#include "avl.hxx"


AVL::AVL()
	: root_(nullptr)
{
}

AVL::~AVL()
{
	destroy();
	if(root_)
		delete root_;
}

void AVL::insert(int value)
{
	insert(root_, value);
}

void AVL::destroy()
{
}

void AVL::insert(AVLNode* node, int value)
{
	if(!node) {
		node = new AVLNode(value);
	}
	else if(value < node->data) {
		insert(node->left, value);
	}
	else {
		insert(node->right, value);
	}
}

void AVL::preorder(const AVL::visitor_t& func) const
{
	preorder(root_, func);
}

void AVL::preorder(AVLNode* node, const AVL::visitor_t& func) const
{
	if(node) {
		func(node);
		preorder(node->left, func);
		preorder(node->right, func);
	}
}


std::string AVL::to_graphviz() const
{
	std::stringstream s;
	s << "graph {\n";
	s << "\tnull[shape=point];\n";
	preorder(
		root_,
		[&](const AVLNode* node) {
			if(node) {
				s << node->data << " -- { ";

				if(node->left)
					s << node->left->data;
				else
					s << "null";

				s << " ";

				if(node->left)
					s << node->left->data;
				else
					s << "null";

				s << "}\n";
			}
		}
	);

	s << "}\n";

	return s.str();
}
