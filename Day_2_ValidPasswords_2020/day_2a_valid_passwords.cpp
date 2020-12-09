#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MIN_COUNT_IDX = 0;
const bool VERBOSE = false;

/* Valid if min_count <= occurrences of char c <= max_count in password */
bool is_valid_password(int min_count, int max_count, char c, string password) {
	if (VERBOSE) {
		cout << "min_count: " << min_count << endl;
		cout << "max_count: " << max_count << endl;
		cout << "char: " << c << endl;
		cout << "password: " << password << endl;
	}

	int len = password.length();
	int c_count = 0;

	for (int i = 0; i < len; i ++) {
		if (password[i] == c) {
			c_count += 1;
			if (c_count > max_count) {
				return false;
			}
		}
	}
	return c_count >= min_count;
}

int main() {
	string filename = "passwords.txt";
	ifstream f_reader(filename);
	if (!f_reader) {
		cout << "File: " << filename << " not found" << endl;
		return 1;
	}

	string line;
	int min_count;
	int max_count;
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
		min_count = stoi(line.substr(MIN_COUNT_IDX, dash_idx));
		max_count = stoi(line.substr(dash_idx + 1, colon_idx - 2));
		c = line[colon_idx - 1];

		password = line.substr(colon_idx + 2, line.length() - (colon_idx + 2));

		if (is_valid_password(min_count, max_count, c, password)) {
			valid_passwords_count += 1;
		}
	}
	f_reader.close();

	cout << "Number of valid passwords is: " << valid_passwords_count << endl;

	return 0;
}