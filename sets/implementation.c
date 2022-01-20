/*
 * implementation.c
 *
 *  Created on: 13 Jan 2022
 *      Author: Gabriel Malaspina
 */

#include "data_defs.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "implementation.h"

Element * newElement (double value)
{
	errno = 0;
	Element * an_element = (Element *) malloc (sizeof (Element));

	if (errno)
	{
		fprintf (stderr, "%s", strerror (errno));
		exit (EXIT_FAILURE);
	}

	an_element->data = value;
	an_element->next = NULL;

	return an_element;
}

void delElement (Element * an_element)
{
	free (an_element);
}

Set * newSet (void)
{
	errno = 0;
	Set * a_set = (Set *) malloc (sizeof (Set));

	if (errno)
	{
		fprintf (stderr, "%s", strerror (errno));
		exit (EXIT_FAILURE);
	}

	a_set->first = NULL;

	return a_set;
}

void delSet (Set * a_set)
{
	free (a_set);
}

_Bool isEmptySet (Set * a_set)
{
	return (a_set->first == NULL ? 1 : 0);
}

void elementIntoSet (Element * an_element, Set * a_set)
{
	an_element->next = a_set->first;
	a_set->first = an_element;
}

Element * isValueInSet (double value, Set * a_set)
{
	/*
	 * Returned value is a NULL pointer if value is not found
	 * or the address of the element containing 'value' otherwise.
	 */
	Element * an_element = &(Element) {value, NULL};
	Element * temp = a_set->first;

	while ((temp != NULL) && (temp->data != an_element->data))
		temp = temp->next;

	return temp;
}

size_t howManyInSet (Set * a_set)
{
	Element * temp = a_set->first;
	size_t qty = 0;

	while (temp != NULL)
	{
		++qty;
		temp = temp->next;
	}

	return qty;
}

void elementOutSet (Element * an_element, Set * a_set)
{
	Element ** temp_back = &a_set->first;
	Element * temp_ahead = *temp_back;

	while ((temp_ahead != NULL) && (temp_ahead->data != an_element->data))
	{
		temp_back = &temp_ahead->next;
		temp_ahead = temp_ahead->next;
	}

	if (temp_ahead != NULL)
	{
		*temp_back = temp_ahead->next;
		temp_ahead->next = NULL;
		delElement (temp_ahead);
	}
}

_Bool isItSubset (Set * a_subset, Set * a_set)
{
	_Bool is_subset = 1;
	Element * temp = a_subset->first;

	while ((temp != NULL) && is_subset)
		if ((isValueInSet (temp->data, a_set)) != NULL)
			temp = temp->next;
		else
			is_subset = 0;

	return is_subset;
}

Set * setsInter (Set * set_A, Set * set_B)
{
	Set * inter_set = newSet ();
	Element * temp = set_A->first;

	while (temp != NULL)
	{
		if ((isValueInSet (temp->data, set_B)) != NULL)
		{
			Element * inter_element = newElement (temp->data);
			elementIntoSet (inter_element, inter_set);
		}
		temp = temp->next;
	}

	return inter_set;
}

Set * setsUni (Set * set_A, Set * set_B)
{
	Set * union_set = newSet ();
	Element * temp = NULL;

	temp = set_A->first;
	while (temp != NULL)
	{
		Element * union_element = newElement (temp->data);
		elementIntoSet (union_element, union_set);
		temp = temp->next;
	}

	temp = set_B->first;
	while (temp != NULL)
	{
		if ((isValueInSet (temp->data, union_set)) == NULL)
		{
			Element * union_element = newElement (temp->data);
			elementIntoSet (union_element, union_set);
		}
		temp = temp->next;
	}

	return union_set;
}

void emptySet (Set * a_set)
{
	Element ** temp_back = &a_set->first;
	Element * temp_ahead = a_set->first;

	while (temp_ahead != NULL)
	{
		temp_ahead = temp_ahead->next;
		(*temp_back)->next = NULL;
		delElement (*temp_back);
		*temp_back = temp_ahead;
	}
}

void getAllValues (double * a_list, Set * a_set)
{
	Element * an_element = a_set->first;

	while (an_element != NULL)
	{
		*a_list = an_element->data;
		++a_list;
		an_element = an_element->next;
	}
}
