#include <stdio.h>
#include <string.h>
void
replace_space(char *string)
{
	long		index = 0;
	long		last_char_pos = 0;
	long		length = strlen(string);
	index = length - 1;

	while (string[index] == ' ') {
		index -= 1;
	}
	last_char_pos = index;
	index = length - 1;

	while (last_char_pos != -1) {
		if (string[last_char_pos] == ' ') {
			string[index] = '0';
			index -= 1;
			string[index] = '2';
			index -= 1;
			string[index] = '%';
		} else {
			string[index] = string[last_char_pos];
		}
		last_char_pos -= 1;
		index -= 1;
	}
}

int
main(int argc, char const *argv[])
{
	char		string    [] = "Mr John Smith    ";
	replace_space(string);
	printf("%s\n", string);
	return 0;
}
