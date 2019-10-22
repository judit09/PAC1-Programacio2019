#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"
#include "user.h"
#include "film.h"
#include "view.h"

// **** Functions related to management of tView objects

// Initialize a tView object
tError view_init(tView* object, tDateTime *timestamp, short score, tUser *user, tFilm *film) {
    // Verify pre conditions
    assert(object != NULL);
    assert(timestamp != NULL);
    assert(user != NULL);
    assert(film != NULL);

    object->timestamp = *timestamp;
    object->score = score;
    object->user = user;
    object->film = film;
    return OK;
}
    
// Free the resources stored by an existing tView object
tError view_free(tView* object) {
    // Verify pre conditions
    assert(object != NULL);
    return OK;
}

// **** Functions related to management of tViewLog objects

// Initializes a visualization table.
void viewLog_init(tViewLog* table) {
    assert(table != NULL);
    table->size = 0;
    table->elements = NULL;
}

// Release memory stored by an existing tViewLog object
void viewLog_free(tViewLog* table) {
    // Verify pre conditions
    assert(table != NULL);
    if(table->elements != NULL){
        free(table->elements);
        table->elements = NULL;
    }
    table->size = 0;
}

// Add a new visualization in the table, received as a parameter.
tError viewLog_add(tViewLog* table, tView* view) {
    // Verify pre conditions
    assert(table != NULL);
    assert(view != NULL);

    if (table->size == 0) {
        // Empty table
        table->size = 1;
        table->elements = (tView*)malloc(table->size * sizeof(tView));
    }
    else {
        // table with elements
        // Increase the number of elements of the table
        table->size = table->size + 1;
        table->elements = (tView*)realloc(table->elements, table->size * sizeof(tView));
    }

    if (table->elements == NULL) {
        return ERR_MEMORY_ERROR;
    }

    view_init(&(table->elements[table->size - 1]), &view->timestamp, view->score, view->user, view->film);

    return OK;
}

// Given a username and a table of type tViewLog, it performs a search 
// of the episode with the highest score (not negative) displayed by the 
// user, offering us a pointer to it. In case of a tie, offer among the 
// winning genres the episode that is first on the list. 
// If the user can't be found in the list, return NULL.
tFilm* viewLog_getFavFilm(tViewLog* table, tUser* user) {
    int i, max, index;
    bool found;
    // Verify pre conditions
    assert(table != NULL);
    assert(user != NULL);
    index = 0;
    max = 0;
    // Search over the table and return once we found the element.
    found = false;
    for (i = 0; i < table->size; i++) {
        if ((table->elements[i].user == user)&&(table->elements[i].score > max)) {
            found = true;
            max = table->elements[i].score;
            index = i;
        }
    }
    if(found){
        return table->elements[index].film;
    }
    return NULL;
}

// Given a username and a table of type tViewLog, it returns the 
// genre for which a user has made more visualizations. In case of a tie, 
// offer the first one on the list. In case the user does not have 
// visualizations, return ERR_NOT_FOUND.
tGenre viewLog_getFavGenre(tViewLog* table, tUser* user) {
    int i, max, index;
    bool found;
    tGenre genre;
    tFilm* film;
    // Verify pre conditions
    assert(table != NULL);
    assert(user != NULL);
    //the index of this array will be equivalent to the index of genre's type
    int counters[8] = {0,0,0,0,0,0,0,0};
    found = false;
    index = 0;
    // Search over the table and return once we found the element.
    for (i = 0; i < table->size; i++) {
        if (user_equals(table->elements[i].user, user)) {
            found = true;
            //get genre of the film element with index i
            genre = series_getGenre(film_getSeries(table->elements[i].film));
            index = (int) genre;
            counters[index]++;
        }
    }
    max = 0;
    index = 0;
    if(found){
        //If the user was found, get the genre with more views of the user 
        for(i = 0; i<8; i++){
                if(counters[i] > max){
                    max = counters[i];
                    index = i;
                }
        }
        genre = index;
        return genre;
    }
    return GENRE_NOT_FOUND;
}

// helper func to get tDateTime for a given timestamp in year, month...
tDateTime* setDateTime(unsigned char day, unsigned char month, unsigned short year, unsigned char hour, unsigned char minute){
	
	// Verify pre conditions
    assert(day <= 31);
	assert(month <= 12);
	assert(hour <= 24);
	assert(minute <= 60);
	
    tDateTime *timestamp;
    timestamp = (tDateTime*)malloc(sizeof(tDateTime));

    timestamp->day = day;
    timestamp->month = month;
    timestamp->year = year;
    timestamp->hour = hour;
    timestamp->minute = minute;

    return timestamp;
}
