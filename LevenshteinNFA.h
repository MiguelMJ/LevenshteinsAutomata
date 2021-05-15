#ifndef __LEVENSHTEINNFA_H_
#define __LEVENSHTEINNFA_H_

#include <list>
#include <forward_list>
#include <vector>
#include <string>

namespace LevenshteinAutomata
{

    class LevenshteinNFA;
    typedef LevenshteinNFA* LevenshteinNFAPtr;
	class LevenshteinNFA
	{		
	public:
		static LevenshteinNFAPtr ConstructNFA(std::string str, int maxDist);
        
		LevenshteinNFA(int size, int state, std::list<int> finalStates);
		~LevenshteinNFA();

		enum Constants
		{
			Deletion = '|',
			Dead = '\0',
			Insertion = '~'
		};
		void AddTransition(int from, int to, char input);
		std::list<int> Move(std::list<int> states, char inp);
		void Show();

		int initialState;
		std::list<int> finalStates;
		std::forward_list<char> inputs;
		std::vector<char> *transTable;
		//char** transTable;
		int size;
	};
}
#endif
