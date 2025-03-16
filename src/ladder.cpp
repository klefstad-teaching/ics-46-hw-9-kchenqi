#include "ladder.h"
#include <stdexcept>
#include <fstream>

void error(string word1, string word2, string msg) {
	cerr << "Error: " << msg << word1 << " -> " << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
}

bool is_adjacent(const string& word1, const string& word2) {
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
}

void load_words(set<string> & word_list, const string& file_name) {
	ifstream infile(filename);
	string word;
	while (infile >> word)
		word_list.insert(word);
}

void print_word_ladder(const vector<string>& ladder) {
	for (size_t i = 0; i < ladder.size(); ++i) {
		if (i != ladder.size() - 1) { cout << ladder[i] << " -> "; }
		else { cout << ladder[i]; }
}

#define my_assert(e) { cout << #e << ((e) ? " passed" : " failed") << endl; }
void verify_word_ladder() {
	set<> word_list;
	load_words(word_list, "words.txt");

	my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
	my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
	my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
	my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
	my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
	my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
