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

/*
 * Set * createSet (void):
 * It allocates memory for a type-Set object and returns a pointer to it.
 */
Set * createSet (void);

/*
 * void eraseSet (Set * a_set):
 * It deallocates all the memory used by the set pointed to by 'a_set' and sets 'a_set' to NULL.
 */
void eraseSet (Set *);

/*
 * void valueIn (double value, Set * a_set):
 * It takes the value in 'value' and, if it's not already in the set pointed to by 'a_set',
 * stores it in the so mentioned set.
 */
void valueIn (double, Set *);

/*
 * void valueOut (double value, Set * a_set):
 * If in the set pointed to by 'a_set', it takes the value in 'value' off the so mentioned set.
 * It does nothing otherwise.
 */
void valueOut (double, Set *);

/*
 * void allValuesOut (Set * a_set):
 * It takes all values in the set pointed to by 'a_set' off the so mentioned set. It does nothing otherwise.
 */
void allValuesOut (Set *);

/*
 * _Bool isValueIn (double value, Set * a_set):
 * It returns 1 if the value in 'value' is in the set pointed to by 'a_set' and 0 otherwise.
 */
_Bool isValueIn (double, Set *);

/*
 * size_t howManyIn (Set * a_set):
 * It returns the number of elements in the set pointed to by 'a_set'.
 */
size_t howManyIn (Set *);

/*
 * _Bool isSubset (Set * a_subset, Set * a_set):
 * It returns 1 if the set pointed to by 'a_subset' is a subset of the set pointed to
 * by 'a_set' and 0 otherwise.
 */
_Bool isSubset (Set *, Set *);

/*
 * Set * setsIntersection (Set * set_A, Set * set_B):
 * It returns a pointer to a set containing the elements that are in turn elements of the sets
 * pointed to by 'set_A' and 'set_B'.
 */
Set * setsIntersection (Set *, Set *);

/*
 * Set * setsUnion (Set * set_A, Set * set_B):
 * It returns a pointer to a set containing the elements that are in turn elements of the sets
 * pointed to by 'set_A' or 'set_B'.
 */
Set * setsUnion (Set *, Set *);

/*
 * void listValues (double * a_list, Set * a_set):
 * It writes into 'a_list' values of all elements contained in the set pointed to by 'a_set'.
 * It is user's responsibility to allocate the right amount of memory to the array pointed to by 'a_list'.
 * See 'size_t howManyIn (Set * a_set)'.
 */
void listValues (double *, Set *);


#endif /* INTERFACE_H_ */
