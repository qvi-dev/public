/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : simplifi.c
 * Authors    : hxu@ingenic.st.jz.com
 * Create Time: 2020-08-31:15:28:18
 * Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATALEN  20000
#define InitSize 200

typedef struct
{
	char mode[8];
	char src[8];
	char dst[8];
} sim_box ;

typedef struct   // not use temporary
{
	int w;
	int h;
	int stride;
	
} com_box ;

typedef struct  // not use temporary
{
	float MScaleX , MSKexW , MTransX ;
	float MScaleY , MSKexY , MTransY ;
	float MPersp0 , MPersp1 , MPersp2 ;
} martix ;

int main ( )
{  
	//   1. init
	FILE *  data ;
	sim_box box_src_sim[DATALEN];   // handle 
	sim_box box_dst_sim[DATALEN];   // handle
	sim_box bs_box[ InitSize ];     // handle
	com_box box_src_com[DATALEN];
	com_box box_dst_com[DATALEN];
	martix  bs_martix[DATALEN];

    //   2. file operation
	int i=0 ;
	if ( (data=fopen("out.txt","r")) == NULL )
		{
			printf( "open file failed!\n");
			exit (0);
		}
	while ( ! feof(data) )
     	{
			fscanf( data, "%s %s %d %d %d %s %d %d %d %f %f %f %f %f %f %f %f %f\n", box_src_sim[i].mode , box_src_sim[i].src ,&box_src_com[i].w ,&box_src_com[i].h ,&box_src_com[i].stride , box_dst_sim[i].dst  ,&box_dst_com[i].w ,&box_dst_com[i].h ,&box_dst_com[i].stride ,&bs_martix[i].MScaleX ,&bs_martix[i].MSKexW ,&bs_martix[i].MTransX ,&bs_martix[i].MScaleY ,&bs_martix[i].MSKexY ,&bs_martix[i].MTransY ,&bs_martix[i].MPersp0 ,&bs_martix[i].MPersp1 ,&bs_martix[i].MPersp2 ) ;
				i++ ;
		}	

	fclose(data) ;


	//   3. classify   ----->>>>>        hardcore

	for ( int q=0 ; q<12 ; q++ )
		{
			memcpy ( bs_box[q].mode , box_src_sim[q].mode , sizeof(char) * 8 );
			memcpy ( bs_box[q].src  , box_src_sim[q].src  , sizeof(char) * 8 );
			memcpy ( bs_box[q].dst  , box_dst_sim[q].dst  , sizeof(char) * 8 );
		}

	/* printf(" %s %s %s \n", bs_box[0].mode , bs_box[0].src , bs_box[0].dst ); */
	int num1=0, num2=0 ;
	for ( int k=0; k<12 ; k++ )
		{
			if ( !( strcmp( bs_box[k].mode , "PERSP" ) ) && ! ( strcmp( bs_box[k].src , "ABRG" ) ) && ! ( strcmp( bs_box[k].dst , "ABRG" ) ) )
				{
					num1 ++ ;
				}

			if ( !( strcmp( bs_box[k].mode , "PERSP" ) ) && ! ( strcmp( bs_box[k].src , "ABGR"))&& ! ( strcmp( bs_box[k].dst , "ABGR") ) )
				{
					num2 ++ ;
				}
			
		}


	// report
	
	printf("Mode: %s, %s --->>> %s   num: %d\n " , bs_box[0].mode , bs_box[0].src , bs_box[0].dst , num1 );
			//	printf("Mode: %s, %s --->>> %s   num: %d\n " , bs_box[0].mode , bs_box[0].src , bs_box[0].dst , num2 );
			


}


