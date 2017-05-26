#include "unittest.h"

//gets and or creates the singleton pointer
UnitTester* UnitTester::getInstance()
{
	static UnitTester* singleton = nullptr;

	//check if the singleton has been created
	if (singleton == nullptr)
	{
		//create unit tester instance
		singleton = new UnitTester();
	}

	return singleton;
}

//echo a failed test as an error, log and console message
void UnitTester::echoFailure()
{
	
}

//runs all of the tests for the unit tester
bool UnitTester::runTests()
{
	std::cout << "Unit test starting...\n";
	LOG->write("Unit test starting...");



	std::vector<int> vec1 = { 1,2,3 };
	LinkedList<int> list2 = LinkedList<int>();

	list2.pushBack(1);
	list2.pushBack(2);
	list2.pushBack(3);
	ASSERT(testEqual(vec1, list2), "pushBack in LinkedList");



	list2.clear();
	ASSERT(list2.size == 0, "clear in LinkedList");



	LinkedList<int> list3 = list2;
	ASSERT(testEqual(list2, list3), "duplicate LinkedList through assignment");



	LinkedList<int> list4 = LinkedList<int>(list3);
	ASSERT(testEqual(list2, list4), "duplicate LinkedList through construction");



	std::vector<int> vec2 = { 6,5,4};
	list2.pushFront(4);
	list2.pushFront(5);
	list2.pushFront(6);
	ASSERT(testEqual(vec2, list2), "pushFront in LinkedList");



	list3 = LinkedList<int>(6);
	ASSERT(list3.size == 6, "constructing LinkedList with size parameter");



	vec2.erase(vec2.begin());
	list2.popFront();
	ASSERT(testEqual(vec2, list2), "popFront in LinkedList");



	vec2.pop_back();
	list2.popBack();
	ASSERT(testEqual(vec2, list2), "popBack in LinkedList");



	LinkedList<int> list5 = LinkedList<int>();

	list5.pushBack(1);
	list5.pushBack(2);
	list5.pushBack(3);

	list5.pushFront(4);
	list5.pushFront(5);
	list5.pushFront(6);

	LinkedList<int>::Iterator iter = list5.begin();
	ASSERT(iter.m_node->value == 6, "begin in LinkedList");


	
	iter++;
	ASSERT(iter.m_node->value == 5, "++ overload in LinkedList::Iterator");



	iter += 1;
	ASSERT(iter.m_node->value == 4, "+= overload in LinkedList::Iterator");



	iter--;
	ASSERT(iter.m_node->value == 5, "-- overload in LinkedList::Iterator");



	iter -= 1;
	ASSERT(iter.m_node->value == 6, "-- overload in LinkedList::Iterator");



	iter = iter + 5;
	ASSERT(iter.m_node->value == 3, "+ overload in LinkedList::Iterator");



	iter = iter - 5;
	ASSERT(iter.m_node->value == 6, "- overload in in LinkedList::Iterator");



	LinkedList<int>::Iterator endIter = list5.end();
	ASSERT(endIter.m_node == nullptr, "end in LinkedList");



	iter += 6;
	ASSERT(iter == endIter, "comparing two identical LinkedList::Iterators");



	iter = list5.begin();
	ASSERT(iter != endIter, "comparing two different LinkedList::Iterators");



	ASSERT(list5[0] == 6, "subscript [] overload in LinkedList");
	ASSERT(list5[1] == 5, "subscript [] overload in LinkedList");
	ASSERT(list5[2] == 4, "subscript [] overload in LinkedList");
	ASSERT(list5[3] == 1, "subscript [] overload in LinkedList");
	ASSERT(list5[4] == 2, "subscript [] overload in LinkedList");
	ASSERT(list5[5] == 3, "subscript [] overload in LinkedList");



	LinkedList<int> list6 = LinkedList<int>();
	ASSERT(!list5.isEmpty(), "isEmpty in LinkedList");
	ASSERT(list6.isEmpty(), "isEmpty in LinkedList");



	std::vector<int> vec3 = { 6,5,4,0,1,2,3};
	list5.insert((list5.begin() + 3).m_node, 0);
	ASSERT(testEqual(vec3, list5), "insert in LinkedList");
	


	vec3.erase(vec3.begin() + 3);
	list5.erase((list5.begin() + 3).m_node);
	ASSERT(testEqual(vec3, list5), "erase in LinkedList");



	list6.pushBack(7);
	list6.pushBack(8);
	list6.pushBack(9);

	vec3.push_back(7);
	vec3.push_back(8);
	vec3.push_back(9);

	list5.pushList(list6);
	ASSERT(testEqual(vec3, list5), "pushList using two LinkedLists");



	LinkedTree<int> tree1 = LinkedTree<int>();
	ASSERT(tree1.getRoot() == nullptr, "getRoot in LinkedTree");



	TreeNode<int>* treeNode1 = new TreeNode<int>();
	treeNode1->value = 1;
	tree1.setRoot(treeNode1);
	ASSERT(tree1.getRoot()->value == 1, "setRoot in LinkedTree");



	tree1.extend(tree1.getRoot(), 2);
	tree1.extend(tree1.getRoot(), 3);
	ASSERT(tree1.getRoot()->value == 1, "extend with value in LinkedTree");



	TreeNode<int>* treeNode2 = new TreeNode<int>();
	treeNode2->value = 4;
	TreeNode<int>* child1 = tree1.getRoot()->children[0];
	tree1.extend(child1, treeNode2);
	ASSERT(tree1.getRoot()->children[0]->children[0]->value == treeNode2->value, "extend with node in LinkedTree");



	LinkedTree<int> tree2 = LinkedTree<int>();
	TreeNode<int>* root2 = new TreeNode<int>();
	root2->value = 5;
	tree2.setRoot(root2);

	tree2.extend(tree2.getRoot(), 6);
	tree2.extend(tree2.getRoot(), 7);

	TreeNode<int>* child2 = tree1.getRoot()->children[1];
	tree1.extend(child2, tree2);
	ASSERT(tree1.getRoot()->children[1]->children[0]->value == 5, "extend with tree in LinkedTree");
	ASSERT(tree1.getRoot()->children[1]->children[0]->children[0]->value == 6, "extend with tree in LinkedTree");
	ASSERT(tree1.getRoot()->children[1]->children[0]->children[1]->value == 7, "extend with tree in LinkedTree");



	TreeNode<int>* node1 = tree1.getRoot()->children[1]->children[0]->children[0];
	TreeNode<int>* root1 = node1->getRoot();
	ASSERT(tree1.getRoot() == root1, "getRoot in TreeNode");



	LinkedList<int*> breadth = tree1.getList(SearchMethod::BREADTH_ORDER);
	ASSERT(*breadth[0] == 1, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[1] == 2, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[2] == 3, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[3] == 4, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[4] == 5, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[5] == 6, "getList in breadth first order in LinkedTree");
	ASSERT(*breadth[6] == 7, "getList in breadth first order in LinkedTree");



	LinkedList<int*> depthPre = tree1.getList(SearchMethod::DEPTH_PRE_ORDER);
	ASSERT(*depthPre[0] == 1, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[1] == 2, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[2] == 4, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[3] == 3, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[4] == 5, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[5] == 6, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPre[6] == 7, "getList in depth first post order in LinkedTree");



	LinkedList<int*> depthPost = tree1.getList(SearchMethod::DEPTH_POST_ORDER);
	ASSERT(*depthPost[0] == 4, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[1] == 2, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[2] == 6, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[3] == 7, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[4] == 5, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[5] == 3, "getList in depth first post order in LinkedTree");
	ASSERT(*depthPost[6] == 1, "getList in depth first post order in LinkedTree");



	LinkedTree<int> subTree = tree1.getSubTree(tree1.getRoot()->children[1]);
	LinkedList<int*> subList = subTree.getList(SearchMethod::DEPTH_POST_ORDER);

	ASSERT(*subList[0] == 6, "getList in depth first post order in LinkedTree");
	ASSERT(*subList[1] == 7, "getList in depth first post order in LinkedTree");
	ASSERT(*subList[2] == 5, "getList in depth first post order in LinkedTree");



	tree1.prune(tree1.getRoot()->children[1]);
	ASSERT(tree1.getRoot()->children.size == 1, "prune in LinkedTree");



	tree1.clear();
	ASSERT(tree1.getRoot() == nullptr, "clear in LinkedTree");



	KeyNode<int> keyNode1 = KeyNode<int>();

	strcpy_s(keyNode1.key, "abc");
	keyNode1.value = 1;
	ASSERT(keyNode1.checkAlpha("ab") == -1, "checkAlpha in KeyNode");
	ASSERT(keyNode1.checkAlpha("a") == -1, "checkAlpha in KeyNode");
	ASSERT(keyNode1.checkAlpha("c") == 1, "checkAlpha in KeyNode");
	ASSERT(keyNode1.checkAlpha("abc") == 0, "checkAlpha in KeyNode");



	char* key = keyNode1.getKey();
	ASSERT(keyNode1.checkAlpha(key) == 0, "getKey in KeyNode");
	ASSERT(keyNode1.getValue() == 1, "getValue in KeyNode");



	KeyNode<int> keyNode2 = KeyNode<int>("abc", 1);
	ASSERT(keyNode2.checkAlpha(keyNode1.getKey()) == 0, "constructing KeyList with value");
	ASSERT(keyNode2.getValue() == 1, "constructing KeyList with value");



	KeyList<int> keyList1 = KeyList<int>();
	keyList1.insert("double", 4);
	keyList1.insert("banana", 2);
	keyList1.insert("apple", 1);
	keyList1.insert("chocolate", 3);
	keyList1.insert("egg", 5);
	keyList1.insert("zebra", 6);

	ASSERT(*keyList1.searchFor("double") == 4, "insert in KeyList");
	ASSERT(*keyList1.searchFor("chocolate") == 3, "insert in KeyList");
	ASSERT(*keyList1.searchFor("zebra") == 6, "insert in KeyList");
	ASSERT(keyList1.searchFor("nonexistent") == nullptr, "insert in KeyList");



	keyList1.remove("banana");
	keyList1.remove("apple");
	keyList1.remove("egg");

	ASSERT(keyList1.searchFor("banana") == nullptr, "remove in KeyList");
	ASSERT(keyList1.searchFor("apple") == nullptr, "remove in KeyList");
	ASSERT(keyList1.searchFor("egg") == nullptr, "remove in KeyList");
	ASSERT(*keyList1.searchFor("chocolate") == 3, "remove in KeyList");

	std::cout << "All tests were ran successfully.\n";
	LOG->write("All tests were ran successfully.");

	return true;
}
