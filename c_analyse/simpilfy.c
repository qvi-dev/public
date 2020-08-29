/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : simpilfy.c
 * Authors    : hxu@ingenic.st.jz.com
 * Create Time: 2020-08-28:16:09:19
 * Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define DATALEN 20000

typedef struct
{
	char format[8];
	int w;
	int h;
	int line_stride;	
} bs_list ;

struct class
{
	
	

	
}
	
struct matrix
{
	char mode[8];
	float MScaleX, MSKexW , MTransX ;
	float MScaleY, MSKexY , MTransY ;
	float MPersp0, MPersp1, MPersp2 ;
} ;

int main()
{
	//                  define 
	FILE *data;
	bs_list src[DATALEN], dst[DATALEN];            
    struct	matrix matrix_box[DATALEN];

	//                 file operation 
   	int i=0;
	if ( (data=fopen("out.txt","r")) == NULL )
		{
			printf( "open file failed!\n");
			return 1;
		}
	
	while ( !feof(data) )
		{
			fscanf( data, "%s %s %d %d %d %s %d %d %d %f %f %f %f %f %f %f %f %f\n",matrix_box[i].mode, src[i].format ,&src[i].w ,&src[i].h ,&src[i].line_stride ,dst[i].format ,&dst[i].w ,&dst[i].h ,&dst[i].line_stride ,&matrix_box[i].MScaleX ,&matrix_box[i].MSKexW ,&matrix_box[i].MTransX ,&matrix_box[i].MScaleY ,&matrix_box[i].MSKexY ,&matrix_box[i].MTransY ,&matrix_box[i].MPersp0, &matrix_box[i].MPersp1, &matrix_box[i].MPersp2 );
			i++;
		}
	fclose( data );

	//                   classify
	// 1. define
	char mode_box[6];
	char src_format_box[20];
	char dst_format_box[20];
	int  j,k=0;

	// 2. processing
	for (j=0; j< DATALEN ; j++)
		{


			
			
			for ( 
				{
					
				}
		}
	
	

	





	return 0;

	
}


