#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int POS_1_IDX = 0;
const bool VERBOSE = false;

/* Valid if char c occurs only once in pos_1 or pos_2 in password */
bool is_valid_password(int pos_1, int pos_2, char c, string password) {
	if (VERBOSE) {
		cout << "pos_1: " << pos_1 << endl;
		cout << "pos_2: " << pos_2 << endl;
		cout << "char: " << c << endl;
		cout << "password: " << password << endl;
	}

	/* Index starting at 1 */
	if (password[pos_1 - 1] == c) {
		return password[pos_2 - 1] != c;
	} else {
		return password[pos_2 - 1] == c;
	}
}

int main() {
	string filename = "passwords.txt";
	ifstream f_reader(filename);
	if (!f_reader) {
		cout << "File: " << filename << " not found" << endl;
		return 1;
	}

	string line;
	int pos_1;
	int pos_2;
	int dash_idx;
	int colon_idx;
	char c;
	string password;
	int valid_passwords_count = 0;

	/* Finding valid passwords: */
	while (getline(f_reader, line)) {
		/* Parsing rule: */
		dash_idx = line.find('-');
		colon_idx = line.find(':');
		pos_1 = stoi(line.substr(POS_1_IDX, dash_idx));
		pos_2 = stoi(line.substr(dash_idx + 1, colon_idx - 2));
		c = line[colon_idx - 1];

		password = line.substr(colon_idx + 2, line.length() - (colon_idx + 2));

		if (is_valid_password(pos_1, pos_2, c, password)) {
			valid_passwords_count += 1;
		}
	}
	f_reader.close();

	cout << "Number of valid passwords is: " << valid_passwords_count << endl;

	return 0;
}