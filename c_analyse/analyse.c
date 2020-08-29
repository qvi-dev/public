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

#define DATALEN 20000

typedef struct
{
	char format[8];
	int w;
	int h;
	int line_stride;	
} bs_list ;
	
struct matrix
{
	char mode[8];
	float MScaleX, MSKexW , MTransX ;
	float MScaleY, MSKexY , MTransY ;
	float MPersp0, MPersp1, MPersp2 ;
} ;

int Sql_init()
{
	int i=0;
	FILE *data;
	char box_src_format[20];
	char box_dst_format[20];
	bs_list src[DATALEN], dst[DATALEN];            
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
	int k=0;
    		
			for ( int k=0; k< DATALEN; k++ )
				{
					box_src_format[k] = src[k].format;
					box_dst_format[k] = dst[k].format;
					for ( )
					
					
	       	    	for ( int j=0; j< DATALEN; j++ )
						
			        	{
							
				        	if ( matrix_box[k].mode == 'PERSP' && src[j].format == src[k].format  )	
					        	{
									
						        	if ( dst[j].format != box_dst_format[0] )
										{
											int k++;
											
											
										}
										
								
					        	}
					
					
					
					
					
					
                        }
			
				}
			
			//  classify 2
			/*
			if( matrix_box[i].mode == 'PSESP')
				{
					if ( src[i].format==   && dst[i].format== )
						{
							
						}
					else if ( src[i].format==   && dst[i].format== )
						{
							
						}
					else if ( src[i].format==   && dst[i].format== )
						{
							
						}
					
				}
			else if( matrix_box[i].mode == 'RSZ' )
				{
					if ( src[i].format==   && dst[i].format== )
						{
							
						}
				}
			else if( matrix_box[i].mode== 'AFFINE')
				{
					if ( src[i].format==   && dst[i].format== )
						{
							
						}
				}
			else
				return 1;
				*/
	
	
	 

	

	
}

int main()
{
	Sql_init();
	return 0;
}

