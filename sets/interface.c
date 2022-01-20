/*
 * interface.c
 *
 *  Created on: 10 Jan 2022
 *      Author: Gabriel Malaspina
 */

#include "interface.h"
#include "implementation.h"

Set * createSet (void)
{
	return newSet ();
}

void eraseSet (Set * a_set)
{
	/*
	 * No need to check whether 'a_set' is empty, as 'emptySet'
	 * will not crash if it is.
	 */
	emptySet (a_set);
	delSet (a_set);
	a_set = NULL;
}

void valueIn (double value, Set * a_set)
{
	// Any value must be only once in any given set.
	if ((isValueInSet (value, a_set)) == NULL)
	{
		Element * an_element = newElement (value);
		elementIntoSet (an_element, a_set);
	}
}

void valueOut (double value, Set * a_set)
{
	/*
	 * No need to check whether 'value' is in 'a_set'.
	 * 'elementOutSet' will not crash if it's not.
	 */
	elementOutSet (&(Element) {value, NULL}, a_set);
}

void allValuesOut (Set * a_set)
{
	emptySet (a_set);
}

_Bool isValueIn (double value, Set * a_set)
{
	return isValueInSet (value, a_set)? 1: 0;
}

size_t howManyIn (Set * a_set)
{
	return howManyInSet (a_set);
}

_Bool isSubset (Set * a_subset, Set * a_set)
{
	return isItSubset (a_subset, a_set);
}

Set * setsIntersection (Set * set_A, Set * set_B)
{
	return setsInter (set_A, set_B);
}

Set * setsUnion (Set * set_A, Set * set_B)
{
	return setsUni (set_A, set_B);
}

void listValues (double * a_list, Set * a_set)
{
	getAllValues (a_list, a_set);
}
