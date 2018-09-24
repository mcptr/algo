#include "avl.hxx"
#include "std.hxx"


int main()
{
	AVL tree;
	tree.insert(100);
	tree.insert(50);
	tree.insert(150);

	std::ofstream output_file("graph.viz.txt");
	if(output_file.good()) {
		output_file <<  tree.to_graphviz();
	}
	output_file.close();


	return 0;
}
