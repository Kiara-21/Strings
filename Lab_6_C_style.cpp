#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()

{
	char s[80];
	cout << "Load text: ";
	cin.getline(s, 80);
	int a, i;
	a = 0;

	for (i = 0; i < strlen(s) - 1; i++)
		if ((s[i] == ' ') && (s[i + 1] != ' '))
			a = a + 1;
	if (s[0] != ' ')
		a = a + 1;
	
	cout << "Number of words: " << a << endl;
	
	char* p, * q;
	
	if (s == NULL)
		return EOF;
	
	for (p = q = s; (*p = *q) != '\0'; p++, q++)
		if (*p == ' ')
			while (*(q + 1) == ' ')
				q++;
	
	cout << "\n" << s << endl;
	
	char* t, * w = NULL, d[] = " .,!:\t\n";
	int m = -1;
	
	t = strtok(s, d);
	
	while (t != NULL) {

		int v = 0;
		char* o = t;
		while (*o != '\0') if (strchr("Aa,Ee,Ii,Oo,Uu", *o++) != NULL)
			++v;
		if (v > m) {
			w = t;
			m = v;
		}
		t = strtok(NULL, d);
	}

	if (w != NULL) printf("Biggest of vowel -: %s\n", w);

	return 0;
}