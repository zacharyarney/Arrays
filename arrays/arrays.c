#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Array {
    int capacity;  // How many elements can this array hold?
    int count;  // How many states does the array currently hold?
    // char **elements is an array of pointers, each pointing to an array of
    // chars (string)
    // the fact that it's char * implies that there is an array
    char **elements;  // The string elements contained in the array
} Array;


/************************************
 *
 *   CREATE, DESTROY, RESIZE FUNCTIONS
 *
 ************************************/

/*****
 * Allocate memory for a new array
 *****/
Array *create_array (int capacity) {
    // Allocate memory for the Array struct
    Array *arr = malloc(sizeof(Array));
    // Set initial values for capacity and count
    arr->capacity = capacity;
    arr->count = 0;
    // Allocate memory for elements
    arr->elements = malloc(sizeof(char *) * capacity);
    return arr;
}


/*****
 * Free memory for an array and all of its stored elements
 *****/
// pass in pointer to array (Array *arr) because passing in the array would
// create a copy and we wouldn't be clearing the space of the original array
void destroy_array(Array *arr) {

    // Free all elements
    // frees each element inside elements
    // make constraint count because we only need to free the spaces that have
    // individual elements
    for (int i = 0; i < arr->count; i++) {
        free(arr->elements[i]);
    }
    // frees the array of pointers (elements) that point to the individual
    // elements
    free(arr->elements);

    // Free array
    free(arr);

}

/*****
 * Create a new elements array with double capacity and copy elements
 * from old to new
 *****/
void resize_array(Array *arr) {

    // Create a new element storage with double capacity

    // Copy elements into the new storage

    // Free the old elements array (but NOT the strings they point to)

    // Update the elements and capacity to new values

}



/************************************
 *
 *   ARRAY FUNCTIONS
 *
 ************************************/

/*****
 * Return the element in the array at the given index.
 *
 * Throw an error if the index is out of range.
 *****/
char *arr_read(Array *arr, int index) {

    // Throw an error if the index is greater or equal to than the current count
    if (index >= arr->count) {
        printf("Index exceeds the size of the array.");
        return NULL;
    }

    // Otherwise, return the element at the given index
    else {
        printf("%p\n", arr->elements[index]);
        return arr->elements[index];
    }
}


/*****
 * Insert an element to the array at the given index
 *****/
void arr_insert(Array *arr, char *element, int index) {

    // Throw an error if the index is greater than the current count
    if (index >= arr->count) {
        printf("Index exceeds the size of the array.");
        return;
    }

    // Resize the array if the number of elements is over capacity
    if (arr->count >= arr->capacity) {
        // resize goes here
        printf("time to resize yo");
    }

    // Move every element after the insert index to the right one position
    for (int i = arr->count; i > index; i--) {
        arr->elements[i] = arr->elements[i - 1];
    }

    // Copy the element and add it to the array
    arr->elements[index] = strdup(element);

    // Increment count by 1
    arr->count++;

}

/*****
 * Append an element to the end of the array
 *****/
void arr_append(Array *arr, char *element) {

    // Resize the array if the number of elements is over capacity
    // or throw an error if resize isn't implemented yet.
    if (arr->count >= arr->capacity) {
        printf("Not enough memory allocated to append to this array\n");
        return;
    }

    // Copy the element and add it to the end of the array
    char *new_element = strdup(element);
    arr->elements[arr->count] = new_element; // strdup uses malloc under the hood

    // Increment count by 1
    arr->count++;

}

/*****
 * Remove the first occurence of the given element from the array,
 * then shift every element after that occurence to the left one slot.
 *
 * Throw an error if the value is not found.
 *****/
void arr_remove(Array *arr, char *element) {

    // Search for the first occurence of the element and remove it.
    // Don't forget to free its memory!

    // Shift over every element after the removed element to the left one position

    // Decrement count by 1

}


/*****
 * Utility function to print an array.
 *****/
void arr_print(Array *arr) {
    printf("[");
    for (int i = 0 ; i < arr->count ; i++) {
        printf("%s", arr->elements[i]);
        if (i != arr->count - 1) {
            printf(",");
        }
    }
    printf("]\n");
}


#ifndef TESTING
int main(void)
{

    Array *arr = create_array(1);

    arr_insert(arr, "STRING1", 0);
    arr_append(arr, "STRING4");
    arr_insert(arr, "STRING2", 0);
    arr_insert(arr, "STRING3", 1);
    arr_print(arr);
    arr_remove(arr, "STRING3");
    arr_print(arr);
    arr_read(arr, 2);
    arr_read(arr, 12);

    destroy_array(arr);
    arr_print(arr);

    return 0;
}
#endif
