/*
 * delay.c
 *
 *  Created on: Jul 20, 2024
 *      Author: Mina
 */

#include"delay.h"

void Delay_MS(uint64 n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}



