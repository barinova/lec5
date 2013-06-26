#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 64



void printWord(char *str , char *addr)
{
	char t[N];
	int i = 0;
	str = addr;
	while(*str && *str !=' ' && *str !='\n')
		printf("%c",*str++);
	printf(" ");
}

void getWords(char str[N], char *t[N], int *i)
{
	char *res;
	int j = 0;
	res = str;
	*i = 0;
	t[(*i)++] = &str[j];
	while(*res)
	{
		if(*res == ' ')
		{
			*res++;
			t[(*i)++]= &str[j + 1];
		}
		else
			*res++;

		j++;
	}
}
int main()
{
	char str[N], *get[N], *print;
	int i, tmp;
	printf("Enter string: ");
	fgets(str, N, stdin);
	getWords(str, get, &i);
	i--;
	while( i + 1 != 0)
	{
		tmp = rand()%(i + 1);
		printWord(str, get[tmp]);
		get[tmp] = get[i--];
	}
	return 0;
}