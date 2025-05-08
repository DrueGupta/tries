#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

int main()
{
	Trie* lang = new Trie("../dictionary.txt");
	lang->insert("bussin");
	lang->insert("heat");
	lang->insert("gooner");
	lang->insert("yeet");
	lang->insert("sigma");
	lang->insert("jonkler");
	lang->insert("ts");

	vector<string> results = lang->autocomplete("bus");
	for (string s : results)
	{
		cout << s << endl;
	}
}
