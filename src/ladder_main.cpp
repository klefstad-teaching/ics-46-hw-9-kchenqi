#include "ladder.h"
#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	set<string> word_list;
	string file_name = "src/words.txt";
	load_words(word_list, file_name);
	string start, end;
	cin >> start;
	cin >> end;
	vector<string> ladder = generate_word_ladder(start, end, word_list);
	print_word_ladder(ladder);
	return 0;
}