#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SUM = 2020;
const int NO_VAL = 0;

/* Assumption: no 0 */
int* two_sum(int number, int* entries) {
	static int arr[2] = {0, 0};
	
	for (int i = 1; i < number; i ++) {
		cout << i << ": " << entries[i] << endl;
		if (entries[i] == 1 && entries[number-i] == 1) {
			/* No duplicate entries: */
			if (i != SUM - number) {
				arr[0] = i;
				arr[1] = number-i;
				return arr;				
			}
		}
	}

	return arr;
}

/* O(n^2) runtime complexity */
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
		int* two_sum_vals = two_sum(SUM-i, &entries[0]);
		if (entries[i] == 1 && two_sum_vals[0] != NO_VAL) {
			cout << "Entries found: " << i << ", " << two_sum_vals[0] << ", " << two_sum_vals[1] << endl;
			cout << "Product of entries: " << i * two_sum_vals[0] * two_sum_vals[1] << endl;
			break;
		}
	}

	return 0;
}