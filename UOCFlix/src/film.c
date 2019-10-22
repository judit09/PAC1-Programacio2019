#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "series.h"
#include "film.h"


//Extra Film Method

tError film_cpy(tFilm* dest, tFilm* src){
    // Verify pre conditions
    assert(dest != NULL);
    assert(src != NULL);
    
    //set free the pointer
    film_free(dest);
    //Reserve memory
    dest->title = (char*)malloc((strlen(src->title) + 1) * sizeof(char));

    if (dest->title == NULL) {
        return ERR_MEMORY_ERROR;
    }
    // Initialize object
    strcpy(dest->title, src->title);
    dest->lengthInMin = src->lengthInMin;
    dest->series = src->series;
    return OK;
}

// Initialize the film structure
tError film_init(tFilm* object, const char* title, const unsigned int lengthInMin, tSeries *series){

    // Verify pre conditions
    assert(object != NULL);
    assert(series != NULL);

    // Reserve memory
    object->title = (char*)malloc((strlen(title) + 1) * sizeof(char));

    if (object->title == NULL) {
        return ERR_MEMORY_ERROR;
    }

    // Initialize object
    strcpy(object->title, title);
    object->lengthInMin = lengthInMin;
    object->series = series;

    return OK;
}


// Releases memory allocated within a tFilm object
void film_free(tFilm* object) {

    // Verify pre conditions
    assert(object != NULL);

    // All memory allocated with malloc and realloc needs to be freed 
    // using the free command. In this case, as we use malloc to 
    // allocate the fields, we have to free them
    if (object->title != NULL) {
        free(object->title);
        object->title = NULL;
    }
}

// Compare two tFilm objects by their title
bool film_equals(tFilm* film1, tFilm* film2) {

    // Verify pre conditions
    assert(film1 != NULL);
    assert(film2 != NULL);

    if (strcmp(film1->title, film2->title) != 0) {
        // Titles are different
        return false;
    }

    return true;
}

// Get ptr to series to which this film belongs
tSeries* film_getSeries(tFilm* object) {
    // Verify pre conditions
    assert(object != NULL);
    
    return object->series;
}

// **** Functions related to management of tFilmTable objects
// Initializes a table of films
void filmTable_init(tFilmTable* table) {
    // Verify pre conditions
    assert(table != NULL);

    // Initialize object
    table->size = 0;
    table->elements = NULL;
}

// Free resources stored by an existing tFilmTable data type.
void filmTable_free(tFilmTable* object) {
// Verify pre conditions
    assert(object != NULL);

    // All memory allocated with malloc and realloc 
    // needs to be freed using the free command. 
    // In this case, as we use malloc/realloc to 
    // allocate the elements, and need to free them.
    if (object->elements != NULL) {
        free(object->elements);
        object->elements = NULL;
    }
    // As the table is now empty, assign the size to 0.
    object->size = 0;
}

// Add a new film in the table. In case the film already exists (same title), 
// it will return an error value ERR_DUPLICATED.
tError filmTable_add(tFilmTable* table, tFilm* film) {
      // Verify pre conditions
    assert(table != NULL);
    assert(film != NULL);

    if (filmTable_find(table, film->title))
        return ERR_DUPLICATED;
   
    if (table->size == 0) {
        // Empty table
        table->size = 1;
        table->elements = (tFilm*)malloc(table->size * sizeof(tFilm));
    }
    else {
        // table with elements
        // Increase the number of elements of the table
        table->size = table->size + 1;
        table->elements = (tFilm*)realloc(table->elements, table->size * sizeof(tFilm));
    }

    if (table->elements == NULL) {
        return ERR_MEMORY_ERROR;
    }
    
    // Initialize object
    film_init(&(table->elements[table->size - 1]), film->title, film->lengthInMin, film->series);

    return OK;
}

 /* Searches for an film in the table received as a parameter, by its title. 
  * It will return a pointer to the tFilm type data if found, or NULL otherwise.
  */
tFilm* filmTable_find(tFilmTable* table, const char* title) {
   int i;

    // Verify pre conditions
    assert(table != NULL);
    assert(title != NULL);

    // Search over the table and return once we found the element.
    for (i = 0; i < table->size; i++) {
        if (strcmp(table->elements[i].title, title) == 0) {
            // We return the ADDRESS (&) of the element, which is a pointer to the element
            return &(table->elements[i]);
        }
    }

    // The element has not been found. Return NULL (empty pointer).
    return NULL;
}

/* Removes a film received as a parameter from the table, based on its title. 
 * If an attempt is made to delete a device that 
 * does not exist in the table, the error value ERR_NOT_FOUND will be returned. 
 * Otherwise, it will return the OK value. If there is a problem managing memory, 
 * this function will return an error value ERR_MEMORY_ERROR.
 */
tError filmTable_remove(tFilmTable* table, tFilm* film){
    int i;
    bool found;

    // Verify pre conditions
    assert(table != NULL);
    assert(film != NULL);

    found = false;
    for (i = 0; i < table->size; i++) {
        if (found) {
            //When film is found, drag the rest of the elements to the left (removing the film inside the table)
            if (film_cpy(&(table->elements[i - 1]), &(table->elements[i])) == ERR_MEMORY_ERROR) {
                return ERR_MEMORY_ERROR;
            }
        }
        else if (strcmp(table->elements[i].title, film->title) == 0) {
            found = true;
        }
    }

    if (found) {
        //the new size
        table->size = table->size - 1;
        if (table->size == 0) {
            table->elements = NULL;
        }
        else {
            //Realocate the memory with the new size
            table->elements = (tFilm*)realloc(table->elements, table->size * sizeof(tFilm));
            if (table->elements == NULL) {
                return ERR_MEMORY_ERROR;
            }
        }
    }
    else {
        return ERR_NOT_FOUND;
    }

    return OK;
}

// Returns the number of films in the tFilmTable table received as a parameter.
unsigned int filmTable_size(tFilmTable* table){
    // Verify pre conditions
    assert(table != NULL);
    
    return table->size;
}