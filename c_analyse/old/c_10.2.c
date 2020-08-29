/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : c_10.2.c
 * Authors    : hxu@ingenic.st.jz.com
 * Create Time: 2020-08-27:16:11:08
 * Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *in, *out;
	char ch, infile[10], outfile[10];
	printf("infile name is\n");
	scanf("%s",infile);
	printf("outfile name is\n");
	scanf("%s",outfile);
	
	if( (in = fopen(infile,"rb")) == NULL )
		{
			printf("can't open such file!\n");
			exit (0);
		}
	
	if( (out = fopen(outfile,"wb")) == NULL )
		{
			printf("can't open such file!\n");
			exit (0);
		}
	
	ch=fgetc(in);
	
	while(!feof(in))
		{
			fputc(ch,out);
			putchar(ch);
			ch=fgetc(in);
		}
	
	putchar(10);
	fclose(in);
	fclose(out);
	return 0;
	
}
