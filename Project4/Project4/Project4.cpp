#include <iostream>

using namespace std;

char* new_strncat(char* strDest, const char* strSource, size_t count) {

	char* pointer = strDest;
	while (*pointer != '\0') {

		pointer++;
	}

	size_t i{0};

	while (i < count && strSource[i] != '\0') {

		*pointer = strSource[i];
		pointer++;
		i++;
	}

	*pointer = '\0';
	return strDest;
}

bool isNumber(char x) {

	return (x >= '0' && x <= '9');
}

bool isPalindrom(char* src, int length) {

	for (int i = 0; i < length; i++) {
		if (isNumber(src[i]) == false) {

			return false;

		}
	}

	int begining = 0;
	int end = length - 1;

	while (begining < end) {
		if (src[begining] != src[end]) {

			return false;
		}
		begining++;
		end--;
	}
	return true;
}

int main() {

	char dest[100] = "Hello ";
	char source[100] = "world! xexexe";

	cout << dest << '\n';
	cout << source << '\n';

	new_strncat(dest, source, 2);
	cout << dest << '\n';

	char dest2[100] = "Hello ";
	new_strncat(dest2, source, 0);
	cout << dest2 << '\n';

	char dest3[100] = "Hello ";
	new_strncat(dest3, source, 14);
	cout << dest3 << '\n';

	cout << "Enter string (<300 elem):" << '\n';
	char string[301];
	cin.getline(string, 301);

	int found = 0;  
	int first_word = -1;         
	int first_word_length = 0;
	int second_word = -1;  
	int second_word_length = 0;     

	int i = 0;
	
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			
			i++;
			continue;
		}

		int word_start = i;

		while (string[i] != '\0' && string[i] != ' ') {
			
			i++;
		}

		int word_length = i - word_start;

		if (isPalindrom(&string[word_start], word_length)) {
			
			found++;

			if (found == 1) {
				
				first_word = word_start;
				first_word_length = word_length;
			}
			
			else if (found == 2) {
				
				second_word = word_start;
				second_word_length = word_length;
				break;
			}
		}
	}

	if (found == 0) {
		
		cout << "No palindroms. :(" << '\n';
	}
	
	else if (found == 1) {
		
		cout << "Found one palindrom: ";
		for (int j = 0; j < first_word_length; j++) {
			
			cout << string[first_word + j];
		}
		
		cout << '\n';
	}
	
	else {
		
		cout << "Found second palindrom: ";
		for (int j = 0; j < second_word_length; j++) {
			
			cout << string[second_word + j];
		}
	}

	return 0;
}
