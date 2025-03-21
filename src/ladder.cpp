#include "ladder.h"
#include <cmath>

void error(string word1, string word2, string msg) {
	cerr << "Error: " << msg << word1 << " -> " << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
	if (abs(static_cast<int>(str1.length() - str2.length())) > 1)
		return false;
	int difference = 0;
	size_t i = 0, j = 0;
	while (i < str1.length() && j < str2.length()) {
		if (str1[i] != str2[j]) {
			++difference;
				if (difference > d)
					return false;
			if (str1.length() > str2.length())
				++i;
			else if (str1.length() < str2.length())
				++j;
			else
				++i, ++j;
		}
		else
			++i, ++j;
	}
	if (i < str1.length() || j < str2.length())
		++difference;
	return difference <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
	return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
	queue<vector<string>> ladder_queue;
	ladder_queue.push({begin_word});
	set<string> visited;
	visited.insert(begin_word);
	
	while (!ladder_queue.empty()) {
		vector<string> ladder = ladder_queue.front();
		ladder_queue.pop();
		string last_word = ladder.back();
		for (const string& word : word_list) {
			if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
				vector<string> new_ladder = ladder;
				new_ladder.push_back(word);
				visited.insert(word);
				if (word == end_word) return new_ladder;
				ladder_queue.push(new_ladder);
			}
		}
	}
	return {};
}

void load_words(set<string> & word_list, const string& file_name) {
	ifstream infile(file_name);
	if (!infile) {
		error("Unable to open file.", " ", " ");
		return;
	}
	string word;
	while (infile >> word)
		word_list.insert(word);
}

void print_word_ladder(const vector<string>& ladder) {
	if (ladder.empty()) {
		cout << "No word ladder found." << endl;
		return;
	}
	cout << "Word ladder found: ";
	for (size_t i = 0; i < ladder.size(); ++i) {
		cout << ladder[i] << " ";
	}
	cout << endl;
}

#define my_assert(e) { cout << #e << ((e) ? " passed" : " failed") << endl; }
void verify_word_ladder() {
	set<string> word_list;
	load_words(word_list, "words.txt");

	my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
	my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
	my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
	my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
	my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
	my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
