/*
 * interface.h
 *
 *  Created on: 13 Jan 2022
 *      Author: Gabriel Malaspina
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "data_defs.h"
#include <stddef.h>

Set * createSet (void);

void eraseSet (Set *);

void valueIn (double, Set *);

void valueOut (double, Set *);

void allValuesOut (Set *);

_Bool isValueIn (double, Set *);

size_t howManyIn (Set *);

_Bool isSubset (Set *, Set *);

Set * setsInter (Set *, Set *);

void listValues (double *, Set *);


#endif /* INTERFACE_H_ */
