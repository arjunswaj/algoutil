#include <stdio.h>

void
eliminate_duplicates(char str[]) {
	int read_index = 0;
	int write_index = 0;
	int hash[256] = {0};
	char ch;
	while ('\0' != (ch = str[read_index])) {		
		if (0 == hash[ch])
		{
			str[write_index] = str[read_index];
			write_index += 1;
		}
		hash[ch] += 1;
		read_index += 1;		
	}
	str[write_index] = '\0';

}

int 
main(int argc, char const *argv[])
{
	char str[] = "eliminate the duplicates";
	printf("String: %s\n", str);
	eliminate_duplicates(str);
	printf("String with no duplicates: %s\n", str);
	return 0;
}