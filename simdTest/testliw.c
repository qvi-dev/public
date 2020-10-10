/*
 *        (C) COPYRIGHT Ingenic Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : test_LIW.c
 * Authors    : zhliu@taurus
 * Create Time: 2019-12-03:17:51:16
 * Description:
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "test_LIW.h"

int main()
{
	int32_t result[16];
    func(result);
	for(int i = 0; i < 16; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}
