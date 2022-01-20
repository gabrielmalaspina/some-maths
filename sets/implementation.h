/*
 * implementation.h
 *
 *  Created on: 13 Jan 2022
 *      Author: Gabriel Malaspina
 */

#ifndef IMPLEMENTATION_H_
#define IMPLEMENTATION_H_

#include "data_defs.h"
#include <stddef.h>

/*
 * Element * newElement (double value):
 * It allocates memory for a structure of type Element, it initialises its
 * members to the value in 'value' and NULL, and returns a pointer to the
 * so mentioned structure to the calling function.
 */
Element * newElement (double);

/*
 * void delElement (Element * an_element):
 * It deallocates memory from the element pointed to by 'an_element'.
 */
void delElement (Element *);

/*
 * Set * newSet (void):
 * It allocates memory for a structure of type Set, it initialises its
 * member to NULL, and returns a pointer to the so mentioned structure to
 * the calling function.
 */
Set * newSet (void);

/*
 * void delSet (Set * a_set):
 * It deallocates memory from the element pointed to by 'a_set'.
 */
void delSet (Set *);

/*
 * _Bool isEmptySet (Set * a_set):
 * It returns 1 if the set pointed to by 'a_set' is empty and 0 otherwise.
 */
_Bool isEmptySet (Set *);

/*/
 * void elementIntoSet (Element * an_element, Set * a_set):
 * It places the element pointed to by 'an_element' into the set.
 * More specifically, at the first position in the set -linked list- pointed
 * to by 'a_set'.
 */
void elementIntoSet (Element *, Set *);

/*
 * Element * isValueInSet (double value, Set * a_set):
 * If contents of 'value' matches a value stored in any element in the set
 * pointed to by 'a_set', it returns a pointer to that element.
 * A NULL pointer otherwise.
 */
Element * isValueInSet (double, Set *);

/*/
 * size_t howManyInSet (Set * a_set):
 * It returns the number of elements in the set pointed to by 'a_set'.
 */
size_t howManyInSet (Set *);

/*
 * void elementOutSet (Element * an_element, Set * a_set):
 * It takes the element pointed to by 'an_element', compares its value against values in
 * elements in the set pointed to by 'a_set', and deallocates the element whose value
 * matches, if any. If none does it remains silent.
 */
void elementOutSet (Element *, Set *);

/*
 * _Bool isItSubset (Set * a_subset, Set * a_set):
 * It returns 1 if the set pointed to by 'a_subset' is a subset of the set pointed to
 * by 'a_set' and 0 otherwise.
 */
_Bool isItSubset (Set *, Set *);

/*
 * Set * setsInter (Set * set_A, Set * set_B):
 * It returns a pointer to a set containing the elements that are in turn elements of the sets
 * pointed to by 'set_A' and 'set_B'.
 */
Set * setsInter (Set * , Set * );

/*
 * Set * setsUni (Set * set_A, Set * set_B):
 * It returns a pointer to a set containing the elements that are in turn elements of the sets
 * pointed to by 'set_A' or 'set_B'.
 */
Set * setsUni (Set *, Set *);

/*
 * void emptySet (Set * a_set):
 * It deallocates all memory in use by the implementation -linked list- and sets the
 * member in the structure pointed to by 'a_set' to NULL.
 */
void emptySet (Set *);

/*
 * void getAllValues (double * a_list, Set * a_set):
 * It writes in the array pointed to by 'a_list' all the values in elements of the set
 * pointed to by 'a_set'. The size of the array should be known prior to the call.
 */
void getAllValues (double *, Set *);

#endif /* IMPLEMENTATION_H_ */
