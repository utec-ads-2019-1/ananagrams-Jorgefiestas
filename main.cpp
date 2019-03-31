#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
map<string, int> anagrams;
map<string, bool> printed;
vector<pair<string,string>> words;

void add_to_map(string &);
string get_map(string);

int main() {
	string word, word_key;
	while(cin>>word){
		if(word == "#") break;
		word_key = get_map(word);
		anagrams[word_key]++;
		words.push_back(make_pair(word, word_key));
	}
	sort(words.begin(), words.end());
	for(int i = 0; i<words.size(); i++){
		if(printed[words[i].first]) continue;
		if(anagrams[words[i].second] == 1 || words[i].first.size() == 1){
			cout<<words[i].first<<endl;
			printed[words[i].first] = true;
		}
	}
	return 0;
}

string get_map(string word){
	string ans = word;
	transform(word.begin(), word.end(),word.begin(), ::tolower);
	sort(word.begin(), word.end());
	return word;
}
