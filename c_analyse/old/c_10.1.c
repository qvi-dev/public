/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : test.cpp
 * Authors    : hxu@ingenic.st.jz.com
 * Create Time: 2020-08-27:12:21:32
 * Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fp;
	char filename[10] , ch;
	scanf("%s",filename);
	getchar();
	if (( fp=fopen( filename , "w" )) == NULL)
		{
			printf("file created failed!\n");
			exit (0);
		}
	printf("input vaild value\n");
	ch = getchar();
	while ( ch != '#')
		{
			fputc(ch,fp);
			putchar(ch);
			ch = getchar();
		}
	fclose(fp);
   	putchar(10);  // not necessary
	return 0;
}
