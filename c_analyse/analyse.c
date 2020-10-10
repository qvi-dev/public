/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : analyse.c
 * Authors    : hxu@ingenic.st.jz.com
 * Create Time: 2020-08-26:11:37:15
 * Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char class_mode[8];
	char class_src[8];
	char class_dst[8];	
};  

struct matrix
{
	char mode[8];
	float MScaleX, MSKexW , MTransX ;
	float MScaleY, MSKexY , MTransY ;
	float MPersp0, MPersp1, MPersp2 ;
} ;

typedef struct
{
	int len;
	int InitLen;
	char mode[8];
	char src_format[8];
	char dst_format[8];
	
} bs_box ;

int Sql_init()
{
	int i=0;
	FILE *data;
	char box_src_format[20];
	char box_dst_format[20];
	bs_list src[DATALEN], dst[DATALEN];
	bs_box box[200];
	struct class bscaler_class[200];
    struct	matrix matrix_box[DATALEN];

	

	

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

			//  classify 1
			memcpy( bscaler_class[0].class_mode , matrix_box[0].mode , sizeof ( char) * 8);
			memcpy( bscaler_class[0].class_src , matrix_box[0].src , sizeof ( char) * 8);
			memcpy( bscaler_class[0].class_dst , matrix_box[0].dst , sizeof ( char) * 8);
			
//			printf("%s\n",matrix_box[0].mode);
//			printf("%s\n",bscaler_class[0].class_mode);

			for (int j=1; j<DATALEN; j++ )
				{
					if ( ! strcmp (matrix_box[j].mode, bscaler_class[0].class_mode ) )
						{
							memcpy( bscaler_class[j].class_mode , matrix_box[j].mode , sizeof ( char) * 8);

							
						}
					else
						{
							j ++;
						}
				}





			for ( int j=0; j<DATALEN; j++ )
				{
					if ( j=0 )
					memcpy( box[0].mode , matrix_box[j].mode , sizeof ( char) * 8);
					else
						{
							for ( int q=0; q< 
						}
				}

			
			

			

			
			

			
	
	 

}

int main()
{
	Sql_init();
	return 0;
}

