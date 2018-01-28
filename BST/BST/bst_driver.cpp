
#include <iostream>
#include <string>
#include "bst.cpp"
//Sample driver.  Make correction and changes as necessary
using namespace std;
int main()
{

	cout << "Test1: default constructor\n";
	bst  myTree;

	myTree.print_tree();
	cout << "End Test1\n";

	cout << "Test2:insert\n";
	myTree.insert("new-county", 234658);
	myTree.print_tree();
	cout << "End Test2\n";

	cout << "Test3: population_ranges\n";
	myTree.population_ranges(0, 50000);
	cout << "End Test3\n";

	cout << "Test4: del_populaton\n";
	myTree.del_populaton(173094);
	myTree.print_tree();
	cout << "End Test4\n";

	cout << "Test5: del_name\n";
	myTree.del_name("miami-dade");
	cout << "End Test5\n";

	cout << "Test6: sorted_info\n";
	myTree.sorted_info();
	cout << "End Test6\n";

	return 0;
}

