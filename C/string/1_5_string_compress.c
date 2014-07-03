#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char           *
itoa(int val, int base)
{

	static char	buf [32] = {0};

	int		i = 30;

	for (; val && i; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i + 1];

}

char           *
compress(const char *string)
{
	long		length = 0;
	long		read_index = 0;
	long		write_index = 0;
	long		char_length = 1;
	long		num_length = 0;
	char           *num_str;
	char           *compressed_string;
	char		previous_char;
	char		current_char;

	length = strlen(string);
	compressed_string = (char *)malloc(2 * length);
	previous_char = string[read_index];
	for (read_index = 1; read_index <= length; read_index += 1) {
		current_char = string[read_index];
		if (current_char != previous_char) {
			compressed_string[write_index] = previous_char;
			write_index += 1;

			num_str = itoa(char_length, 10);
			num_length = strlen(num_str);			
			strcat(compressed_string, num_str);
			write_index += num_length;
			char_length = 1;
			previous_char = current_char;
		} else {
			char_length += 1;
		}
	}
	return compressed_string;
}

int
main(int argc, char const *argv[])
{
	long		string_length = 0;
	long		compressed_string_length = 0;
	const char     *string;
	char           *compressed_string;
	string = argv[1];
	compressed_string = compress(string);
	compressed_string_length = strlen(compressed_string);
	string_length = strlen(string);
	if (string_length > compressed_string_length) {
		printf("%s\n", compressed_string);
	} else {
		printf("%s\n", string);
	}

	return 0;
}
