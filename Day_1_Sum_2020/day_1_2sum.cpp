#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SUM = 2020;


/* O(n) runtime complexity */
int main() {

	string filename = "advent_1_2020_nums.txt";
	ifstream f_reader(filename);
	if (!f_reader) {
		cout << "File: " << filename << " not found" << endl;
		return 1;
	}

	int entries[SUM];
	string number;
	int idx;

	for (int i = 0; i < SUM; i ++) {
		entries[i] = NO_VAL;
	}

	/* Filling in existing entries */
	while (getline(f_reader, number)) {
		idx = stoi(number);
		entries[idx] = 1;
		cout << number << endl;
	}

	/* For each existing entry, find existing complement to 2020 */
	for (int i = 0; i < SUM; i ++) {
		if (entries[i] == 1 && entries[SUM - i] == 1) {
			cout << "Entries found: " << i << ", " << SUM - i << endl;
			cout << "Product of entries: " << i * (SUM - i) << endl;
			break;
		}
	}

	return 0;
}