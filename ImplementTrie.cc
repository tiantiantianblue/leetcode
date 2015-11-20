#include<all.h>
class TrieNode {
public:
	TrieNode() {
	}
	unsigned char pos[26]={0};
	vector<TrieNode *> v;
	bool exist=false;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		auto p=root;
		for(char c: word)
		{
			auto &posi = p->pos[c-'a'];
			if(posi)
			p=p->v[posi-1];
			else
			{
			p->v.push_back(new TrieNode);
			posi=p->v.size();
			p=p->v[posi-1];
			}
		}
		p->exist=true;
	}

	bool search(string word) 
	{
		auto p=root;
		for(char c:word)
			{
			auto posi = p->pos[c-'a'];
			if(posi)
			p=p->v[posi-1];
			else
			return false;
		}
		return p->exist;
	}

	bool startsWith(string prefix) 
	{
		auto p=root;
		for(char c:prefix)
		{
			auto posi = p->pos[c-'a'];
			if(posi)
			p=p->v[posi-1];
			else
			return false;
		}
		return true;
	}

private:
	TrieNode* root;
};
