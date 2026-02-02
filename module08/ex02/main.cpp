#include "MutantStack.hpp"

// subjecti meji main
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }


int main()
{
	MutantStack<int> mutant_stack;

	for (int i = 0; i < 10; i++)
		mutant_stack.push(i * 2);

	std::cout << "Forward iteration:\n";
	for (MutantStack<int>::iterator it = mutant_stack.begin(); it != mutant_stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	const MutantStack<int> cms(mutant_stack);
	std::cout << "Const iteration:\n";
	for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}