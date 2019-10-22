#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "series.h"

// Initialize a series object
tError series_init(tSeries* object, const char* title, tGenre genre) {
    // Verify pre conditions
    assert(object != NULL);
    assert(title != NULL);

    // Reserve memory
    object->title = (char*)malloc((strlen(title) + 1) * sizeof(char));

    if (object->title == NULL) {
        return ERR_MEMORY_ERROR;
    }

    // Initialize object
    strcpy(object->title, title);
    object->genre = genre;
    return OK;
}

// Releases memory allocated within a tSeries object
void series_free(tSeries* object) {
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

// Returns title string of a tSeries object
const char* series_getTitle(tSeries* object) {
    // Verify pre conditions
    assert(object != NULL);
    
    return object->title;
}

// Change the title field of a tSeries object
tError series_mdfyTitle(tSeries* object, const char* newTitle){
    // Verify pre conditions
    assert(object != NULL);
    assert(newTitle != NULL);
    
    // Realocate memory
    object->title = (char*) realloc(object->title, strlen(newTitle));
    
    //verify if relocate was succes
    if (object->title == NULL) {
         return ERR_MEMORY_ERROR;
    }
    //Change the title for the new one
    strcpy(object->title, newTitle);
    
    return OK;
}

// Returns genre in a tSeries object
tGenre series_getGenre(tSeries* object) {
    // Verify pre conditions
    assert(object != NULL);
    //Return genre
    return object->genre;
}

// Compare two tSeries objects for equality, by their title and genre
bool series_equals(tSeries* serie1, tSeries* serie2){
    // Verify pre conditions
    assert(serie1 != NULL);
    assert(serie2 != NULL);

    if (strcmp(serie1->title, serie2->title) != 0) {
        // Title are different
        return false;
    }
    if (serie1->genre != serie2->genre) {
        // Genre are different
        return false;
    }

    return true;
}

/*  
Copy the content of a source tSeries data, to another destination tSeries data.
Both origin and destination must be previously instantiated (calling
series_init () over your pointer)
*/
tError series_cpy(tSeries* dest, tSeries* src){
    // Verify pre conditions
    assert(dest != NULL);
    assert(src != NULL);
    
    //set free the pointer
    series_free(dest);
    //Reserve memory
    dest->title = (char*)malloc((strlen(src->title) + 1) * sizeof(char));
    
    if (dest->title == NULL) {
        return ERR_MEMORY_ERROR;
    }
    // Initialize object
    strcpy(dest->title, src->title);
    dest->genre = src->genre;
    return OK;
}
