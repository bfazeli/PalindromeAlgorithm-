/*
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;


void start();

bool isPalindrome(stack<char>, queue<char>);
void processPalindrome(stack<char> &, queue<char> &);
void buildStackAndQueue(stack<char>&, queue<char>&);
void emptyStackAndQueue(stack<char>&, queue<char>&);
//bool checkPalindrome();

int main()
{
	// Starts the program
	start();
	system("pause");
	return 0;
}


// Start implementation
void start()
{
	stack<char> pStack;
	queue<char> qStack;
	processPalindrome(pStack, qStack);
}

void processPalindrome(stack<char> & chStack, queue<char> & chQueue)
{
	do
	{
		cout << "\nPlease enter a word: ";
		buildStackAndQueue(chStack, chQueue);

		cout << "\nThe word ";

		if (isPalindrome(chStack, chQueue))
		{
			while (!chStack.empty())
			{
				if (chStack.top() == chQueue.front())
				{
					cout << chQueue.front();
				}
				chStack.pop();
				chQueue.pop();
			}
			cout << " is a palindrome.\n" << endl;
		}
		else
		{
			while (!chStack.empty())
			{
				cout << chQueue.front();

				chStack.pop();
				chQueue.pop();
			}
			cout << " is not a palindrome.\n" << endl;
		}
		//cout << "Would you like to try again? (y/n) ";

		if(!chStack.empty()) emptyStackAndQueue(chStack, chQueue);

		//cin.ignore(1, ' ');
		cout << "Would you like to try again? (y/n) ";
	} while (cin.get() != 'n' && cin.ignore());
}

void buildStackAndQueue(stack<char> & chStack, queue<char> & chQueue)
{
	do
	{
		chStack.push(tolower(cin.get()));
		if (chStack.top() != '\n')
		{
			chQueue.push(chStack.top());
		}
	} while (chStack.top() != '\n');

	chStack.pop();
}

bool isPalindrome(stack<char> chStack, queue<char> chQueue)
{
	while (!chStack.empty()) {
		if (chStack.top() != chQueue.front())
			return false;
		chStack.pop();
		chQueue.pop();
	}

	return true;
}

void emptyStackAndQueue(stack<char>& chStack, queue<char>& chQueue)
{
	while (!chStack.empty())
	{
		chStack.pop();
		chQueue.pop();
	}
}