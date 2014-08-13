#include <stdio.h>

int 
interleaving(char *a, int ain, char *b, int bin, char *c, int cin) {
	//printf("a: %d, b: %d, c: %d\n", ain, bin, cin);
	if (a[ain] == c[cin] && b[bin] == c[cin])
	{
		if (c[cin] == '\0')
		{
			return 1;
		} 
		else {
			return interleaving(a, ain + 1, b, bin, c, cin + 1) || interleaving(a, ain, b, bin + 1, c, cin + 1);
		}
	} 
	else if (a[ain] == c[cin])
	{
		if (c[cin] == '\0')
		{
			return 1;
		} else {
			return interleaving(a, ain + 1, b, bin, c, cin + 1);
		}
	} 
	else if (b[bin] == c[cin])
	{
		if (c[cin] == '\0')
		{
			return 1;
		} else {
			return interleaving(a, ain, b, bin + 1, c, cin + 1);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	char *a = "aaabbb";
	char *b = "acacacac";
	char *c = "aaaacacacacbbb";
	if (interleaving(a, 0, b, 0, c, 0))
	{
		printf("Interleaved\n");
	} 
	else {
		printf("Not Interleaved\n");
	}
	return 0;
}