# sets

This is my implementation of sets, as methematically defined, and some operations normally carried out on them.
The work comprises two parts: The interface, grouping end-user functions to manipulate sets and their elements; and the implementation, which contains the data definitions as well as the functions that deal with such data. See below for an example on how it works:


### Interface:
#### Functions:


* `Set * createSet (void)` Allocates memory for a type-Set object and returns a pointer to it.

* `void eraseSet (Set * a_set)` Deallocates all the memory used by the set pointed to by _a_set_ and sets _a_set_ to NULL.

* `void valueIn (double value, Set * a_set)` Takes the value in _value_ and, if it's not already in the set pointed to by _a_set_, stores it in the so mentioned set. It does nothing otherwise.

* `void valueOut (double value, Set * a_set)` If in the set pointed to by _a_set_, it takes the value in _value_ off the so mentioned set. It does nothing otherwise.

* `void allValuesOut (Set * a_set)` Takes all values in the set pointed to by _a_set_ off the so mentioned set.

* `_Bool isValueIn (double value, Set * a_set)` Returns 1 if the value in _value_ is in the set pointed to by _a_set_ and 0 otherwise.

* `size_t howManyIn (Set * a_set)` Returns the number of elements in the set pointed to by _a_set_.

* `_Bool isSubset (Set * a_subset, Set * a_set)` Returns 1 if the set pointed to by _a_subset_ is a subset of the set pointed to by _a_set_ and 0 otherwise.

* `Set * setsIntersection (Set * set_A, Set * set_B)` Returns a pointer to a set containing the elements that are in turn elements of the sets pointed to by _set_A_ and _set_B_.

* `Set * setsUnion (Set * set_A, Set * set_B)` Returns a pointer to a set containing the elements that are in turn elements of the sets pointed to by _set_A_ or _set_B_.

* `void listValues (double * a_list, Set * a_set)` Rrites into _a_list_ values of all elements contained in the set pointed to by _a_set_. It is user's responsibility to allocate the right amount of memory to the array pointed to by _a_list_. See `size_t howManyIn (Set * a_set)`.


#### Example:

**Note: This example is only a heads-up on the facilities these functions provide. No programming style is encouraged here.**

Use `gcc -std=c11 -pedantic -pedantic-errors -Wall main.c implementation.c interface.c` to compile it.

```
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	size_t qty = 0;

/***************** Create, initialise and print values in setA ********************/

	Set * setA = createSet ();		// Creates setA.
	for (size_t j = 0; j < 10; ++j)		// Adds on some elements into it.
		valueIn (2 * j, setA);

	qty = howManyIn (setA);		    // Count number of elements in setA.
  
	double * listA = (double *) malloc (qty * sizeof (double));
  
	listValues (listA, setA);     // Copy values in setA into listA.
  
	printf ("\'setA\' contains the following values: ");
	for (size_t i = 0; i < qty; ++i)
		printf ("%d, ", (int) listA[i]);
	puts ("\b\b.");
  
	free (listA);

/********************** Same as before but with setB instead ************************/

	Set * setB = createSet ();
	for (size_t j = 0; j < 10; ++j)
		valueIn (3 * j, setB);

	qty = howManyIn (setB);
	double * listB = (double *) malloc (qty * sizeof (double));
	listValues (listB, setB);
	printf ("\'setB\' contains the following values: ");
	for (size_t i = 0; i < qty; ++i)
		printf ("%d, ", (int) listB[i]);
	puts ("\b\b.");
	free (listB);


/*** Creates intersection set, counts elements, print them and tests for subset ***/

    // Creates a set and makes it the intersection set between setA and setB.
	Set * interAB = setsIntersection (setA, setB);
  
	qty = howManyIn (interAB);
  
	puts ("\'interAB\' is the intersection set between setA and setB");
	printf ("\'interAB\' has %zd elements\n", qty);
  
	double * listAB = (double *) malloc (qty * sizeof (double));
	listValues (listAB, interAB);
  
	printf ("\'interAB\' contains the following values: ");
	for (size_t i = 0; i < qty; ++i)
		printf ("%d, ", (int) listAB[i]);
	puts ("\b\b.");
  
    // Checks if setA intersection setB is subset of setA union setB.
	printf ("\'interAB\' %s a subset of setA union setB\n",
			isSubset (interAB, setsUnion (setA, setB))? "is": "is not");
      
	free (listAB);

	eraseSet (setA);
	eraseSet (setB);
	eraseSet (interAB);

	return 0;
}
```

### Implementation:
The set is implemented as a linked list containing two types of objects. Each node in the list is a structure object tagged **Element**, which contains two members: _data_ and _next_. The former containing a value and the latter a pointer to the next node, if there were any. The other type is the structure object tagged **Set**. Whose only member is _first_; used to point to the beginning of the list or set to NULL if the set were empty. (See **data_defs.h**).

As per the functions in the implementation, it follows a list containing all functions, which are not meant to be called directly. See **implementation.h** for a brief explanation on them.

#### Functions:


* `Element * newElement (double value)` 
* `void delElement (Element * an_element)` 
* `Set * newSet (void)` 
* `void delSet (Set * a_set)`
* `_Bool isEmptySet (Set * a_set)`
* `void elementIntoSet (Element * an_element, Set * a_set)`
* `Element * isValueInSet (double value, Set * a_set)`
* `size_t howManyInSet (Set * a_set)`
* `void elementOutSet (Element * an_element, Set * a_set)`
* `_Bool isItSubset (Set * a_subset, Set * a_set)`
* `Set * setsInter (Set * set_A, Set * set_B)`
* `Set * setsUni (Set * set_A, Set * set_B)`
* `void emptySet (Set * a_set)`
* `void getAllValues (double * a_list, Set * a_set)`
