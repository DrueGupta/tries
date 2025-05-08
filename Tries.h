#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

struct node
{
	unordered_map<char, node*> children;
};

class Trie
{
private:
	node* root;
public:
	Trie()
	{
		root = new node();
	}
	Trie(string filename)
	{
		this->root = new node();
		string temp;
		fstream inFile;
		inFile.open(filename);
		if (inFile.is_open())
		{
			while (inFile.good())
			{
				getline(inFile, temp);
				this->insert(temp);
			}
		}
		inFile.close();
	}
	void insert(string word)
	{
		node* current = this->root;
		for (char letter : word)
		{
			if (current->children[letter])
				current = current->children[letter];
			else
			{
				node* noob = new node();
				current->children[letter] = noob;
				current = current->children[letter];

			}
		}
		current->children['*'] == nullptr;
	}
	node* search(string word)
	{
		node* current = this->root;
		for (char letter : word)
		{
			if (current->children[letter])
				current = current->children[letter];
			else
				return nullptr;
		}
		return current;
	}
	bool exist(string word)
	{
		node* current = this->root;
		for (char letter : word)
		{
			if (current->children[letter])
				current = current->children[letter];
			else
				return false;
		}
		return current->children['*'] == nullptr;
	}
	void allWords(node* start, string prefix, vector<string>& words)
	{
		node* current = start;
		for (auto keyValuePair : start->children)
		{
			if (keyValuePair.first == '*')
				words.push_back(prefix);
			else
			{
				allWords(keyValuePair.second, prefix + keyValuePair.first, words);
			}
		}
	}

	vector<string> autocomplete(string prefix)
	{
		node* current = this->search(prefix);
		if (current == nullptr)
			return{};
		vector<string> results;
		this->allWords(current, prefix, results);
		return results;
	}
};
