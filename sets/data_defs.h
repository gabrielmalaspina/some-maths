/*
 * data_defs.h
 *
 *  Created on: 1 Jan 2022
 *      Author: Gabriel Malaspina.
 */

#ifndef DATA_DEFS_H_
#define DATA_DEFS_H_

typedef struct element
{
	double data;
	struct element * next;
} Element;

typedef struct
{
	Element * first;
} Set;

#endif /* DATA_DEFS_H_ */
