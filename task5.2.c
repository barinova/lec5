#include <stdio.h>
#include <stdlib.h>
#define N 64

void clear(char arr[N][N])
{
	int i = 0, j = 0;
	for(; i < N; i++)
		for(; j < N; j++)
			arr[i][j] = 0;
}

void paint(char arr[N][N])
{
	int i = 0, j = 0;
	for(; i < N/4; i++)
	{
		for(; j < N/4; j++)
		{
			 switch (rand() % 2) {
				case 0: arr[i][j] = '*'; break;
				case 1: arr[i][j] = ' '; break;
			 }
			 printf("%c",arr[i][j]);
		}
		j = 0;
		printf("\n");
	}

}

void copy(char arr[N][N])
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(arr[i][j] == ' ' || arr[i][j] == '*')
				j = N/4;
			arr[i][j] = arr[i%(N/4)][j%(N/4)];
		}
		j = N/4;
	}
}

void print(char arr[N][N])
{
	char c;
	int i = 0, j = 0;
	do
	{
		for(; j < N; j++)
			printf("%c", arr[i][j]);
		i++;
		j = 0;
		scanf("%c", &c);
	}while(c == '\n' && i < N);
}

/*void p(char arr[N][N])
{
	int i = 0, j = 0;
	for(; i < N; i++)
	{
		for(; j < N; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}*/

int main()
{
	char arr[N][N];
	clear(arr);
	paint(arr);
	copy(arr);
	print(arr);
	return 0;
}