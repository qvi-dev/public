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
#include "mxu3.h"
#include "test_LIW.h"

void func(int32_t* result)
{
	LIW(VR1, 10);
	SA(o, VR1, 0, result, 0);
	SA(o, VR1, 1, result, 32);
}
