/*
This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.
*/




#include <iostream>
#include <string>

using namespace std;

class treenode
{
public:
	string country_name;
	string info;
	double population_size;
	treenode *lchild, *rchild;
};

class bst
{
public:
	bst()

	{

		root = 0;

	}
	~bst();


	bool empty();
	void insert(string item);
	void insert(treenode * &, string item);
	void del_name(string item);
	void del_name(treenode * & loc_ptr, string ob);

	void del_population(double item);

	void del_population(treenode *&loc_ptr, double ob);


	treenode * search_tree(treenode *, string item);
	treenode * search_tree(string item);


	treenode * inorder_succ(treenode *);
	treenode * parent();
	void print_tree();
	void print_tree(treenode *);

private:
	treenode *root;

};

bool bst::empty()
{
	return (root == 0);
}

void bst::insert(string item)
{

	insert(root, item);
}

void bst::insert(treenode * & loc_ptr, string item)
{
	
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->info = item;
	}
	else if (loc_ptr->info>item)
		insert(loc_ptr->lchild, item);
	else if (loc_ptr->info<item)
		insert(loc_ptr->rchild, item);
	else
		cout << "the item is already in the tree\n";
}

treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}

treenode * bst::search_tree(treenode * loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->info == item)
			return loc_ptr;
		else if (loc_ptr->info>item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}



void bst::del_name(string item)
{
	del_name(root, item);
}

void bst::del_name(treenode * & loc_ptr, string ob)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->info > ob)
		del_name(loc_ptr->lchild, ob);

	else if (loc_ptr->info < ob)
		del_name(loc_ptr->rchild, ob);

	else
	{
		treenode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->info = ptr->info;
			del_name(loc_ptr->rchild, ptr->info);
		}
	}

}

treenode * bst::inorder_succ(treenode * loc_ptr)
{

	treenode *ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

void bst::print_tree()
{
	print_tree(root);
}

void bst::print_tree(treenode * loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->info << endl;
		print_tree(loc_ptr->rchild);
	}
}


bst::~bst()
{
	while (root != 0)
	{
		del_name(root->info);
	}
}

int main()
{
	bst B;
	//treenode *root1=0, *root2=0;
	string s;
	char ch;
	string key3;
	string key4;
	string response;
	string r1, r2;
	cout << "enter command, c=count, i=insert item,s=search tree,d=delete item,p=print tree, r = range, e=exit: ";
	cin >> ch;
	cout << endl;

	while (ch != 'e')
	{
		switch (ch)
		{
		case 'i':cout << "enter string: ";
			cin >> s;
			B.insert(s);
			break;

		case 's':cout << "enter word to search for: ";
			cin >> s;
			if (!B.search_tree(s))
				cout << s << "not in tree\n";
			else
				cout << s << " was found in the tree\n";
			break;
		case 'd':cout << "enter word to delete: ";
			cin >> s;
			B.del_name(s);
			break;
		case 'p':cout << "...printing tree...\n";
			B.print_tree();
			break;

		default:break;
		}
		cout << "enter command, i=insert item,s=search tree,d=delete item,p=print tree, e=exit: ";
		cin >> ch;
		cout << endl;
	}

	cout << endl << "no more binary tree.....\n";
	return 0;
	

}