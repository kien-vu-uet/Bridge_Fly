#include "memories.h"

using namespace std;

ranked_list person;

void read_file(string path) {
	ifstream inf(path);

	for (int i = 0; i < 5; i++) {
		string _name; getline(inf, _name);
		string _score_str; getline(inf, _score_str);
		int _score = str_to_int(_score_str);
		person.input(_name, _score);
		list.push_back(person);
	}
	inf.close();
}

void print_memories(string path) {
	if (list[4].get_score() <= list[3].get_score()) return;
	string _name = list[4].get_name();
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (list[i].get_score() < list[j].get_score()) {
				swap(list[i], list[j]);
			}
		}
	}
	list[4].input(_name, 0);

	ofstream output(path);
	for (int i = 0; i < 4; i++) {
		output << list[i].get_name() << endl << list[i].get_score() << endl;
	}
	output.close();
}