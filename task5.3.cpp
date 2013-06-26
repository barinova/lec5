#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 64

char *strChange(char* str)
{ 
	char t;
	int j = 0;
	int k = 0, l = 0, i, tmp;
	for(; l < strlen(str) + 1; l++)
	{
	
		if(str[l] == ' ' || l == strlen(str))
		{
		if(j > 3)
			{
				for(i = l - j + 1; i < l - 1; i++)
				{
					tmp = rand()%j;
					t = str[i];
					str[i] = str[l - j + tmp];
					str[l - j + tmp] = t;
				}
			}
			j = 0;
		}
		else
			j++;
	}
	return str;
}

void change(char *s[N], int len)
{
	int i = 0;
	while(i < len - 1)
	{
		*s = strChange(*s);
		*s++;
		i++;
	}
}

int main()
{
char ch;
	int cnt = 0, i = 0, j;
	char buf[N][N];
	char *s[N];
	FILE *fin;
	fin=fopen("1.txt","rt");
	if(!fin) {
	printf("Error! (I can’t open text.txt)\n");
	return 1;
	}
	while((ch=fgetc(fin))!=EOF)
	{
		buf[cnt][i++] = ch;
		if(ch == '\n')
		{
			buf[cnt][i-1] = '\0';
			cnt++;
			i = 0;
		}
	}
	buf[cnt][i] = '\0';	
	buf[++cnt][0] = '\0';
	cnt = 0;
	do
	{
		s[cnt-1] = buf[cnt-1];
		cnt++;
	}while(buf[cnt-1][0] != '\0');
	 
	change(s, cnt);

	
	for( i = 0 ; i < cnt - 1; i++)
	{
		for( j = 0; j < strlen(s[i]); j++)
			printf("%c", s[i][j]);
		printf("\n");
	}
		

	fclose(fin);
	return 0;
}