#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<char> myown;
	std::cout << "MY TESTS" << std::endl;
	myown.push('a');
	myown.push('b');
	myown.push('c');
	myown.pop();
	myown.push('d');
	myown.pop();
	myown.pop();
	myown.push('e');
	myown.push('f');
	myown.push('g');

	int index = 0;
	MutantStack<char>::iterator nani = myown.begin(); 
	MutantStack<char>::iterator naniend = myown.end();
	while (nani != naniend)
	{
		std::cout << *nani << std::endl;
		nani++;
		index++;
	}
	std::cout << "Index = ";
	std::cout << index << std::endl;
	std::cout << "Stack size = ";
	std::cout << myown.size() << std::endl;
	std::cout << std::endl;

	MutantStack<std::string> moore;
	moore.push("bruh");
	moore.push("my");
	moore.push("name");
	moore.pop();
	moore.push("is");
	moore.pop();
	moore.pop();
	moore.push("dante");
	moore.push("how");
	moore.push("are");
	moore.push("you?");
	
	int testindex = 0;
	MutantStack<std::string>::iterator again = moore.begin(); 
	MutantStack<std::string>::iterator againend = moore.end();
	while (again != againend)
	{
		std::cout << *again << std::endl;
		again++;
		testindex++;
	}
	std::cout << "Testindex = ";
	std::cout << testindex << std::endl;
	std::cout << "Stack size = ";
	std::cout << moore.size() << std::endl;

	std::cout << std::endl;
	std::cout << "SUBJECT TESTS!!" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = ";
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << "SAME PROCESS AS THE ONE IN THE SUBJECT ONLY WITH STD::LIST, OUTPUT SHOULD BE THE SAME" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	//std::cout << "top = ";
	//std::cout << lst.() << std::endl;
	lst.pop_back();
	std::cout << "size = ";
	std::cout << lst.size() << std::endl;
	lst.push_back(3); 
	lst.push_back(5); 
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator bruh = lst.begin(); 
	std::list<int>::iterator bruhe = lst.end();
	++bruh;
	--bruh;
	while (bruh != bruhe) 
	{
		std::cout << *bruh << std::endl;
		++bruh; 
	}
	//std::stack<int> s(mstack); 
	std::cout << std::endl;
	return 0;
}