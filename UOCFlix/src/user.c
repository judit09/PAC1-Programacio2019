#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "user.h"


//Extra methods to trim a string
char *ltrim(char *name)
{    
    while(isspace(*name)) name++;
    return name;
}

char *rtrim(char *name)
{
    char* back = name + strlen(name);
    while(isspace(*--back));
    *(back+1) = '\0';
    return name;
}

char *trim(char *name)
{
    assert(name != NULL);

    return rtrim(ltrim(name)); 
}

// Initialize the user structure
tError user_init(tUser* object, const char* username, const char* name, const char* mail) {

    // Verify pre conditions
    assert(object != NULL);
    assert(username != NULL);
    assert(name != NULL);
    assert(mail != NULL);

    // Allocate the memory for all the fields, using the length of the provided 
    // text plus 1 space for the "end of string" char '\0'. 
    // To allocate memory we use the malloc command.
    object->username = (char*)malloc((strlen(username) + 1) * sizeof(char));
    object->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    object->mail = (char*)malloc((strlen(mail) + 1) * sizeof(char));

    // Check that memory has been allocated for all fields. 
    // Pointer must be different from NULL.
    if (object->username == NULL || object->name == NULL || object->mail == NULL) {
        // Some of the fields have a NULL value, what means that we found 
        // some problem allocating the memory
        return ERR_MEMORY_ERROR;
    }

    // Once the memory is allocated, copy the data. As the fields are strings, 
    // we need to use the string copy function strcpy. 
    strcpy(object->username, username);
    strcpy(object->name, name);
    strcpy(object->mail, mail);

    return OK;
}

// Remove the memory used by user structure
void user_free(tUser* object) {

    // Verify pre conditions
    assert(object != NULL);

    // All memory allocated with malloc and realloc needs to be freed using the free command. 
    // In this case, as we use malloc to allocate the fields, we have to free them
    if (object->username != NULL) {
        free(object->username);
        object->username = NULL;
    }
    if (object->name != NULL) {
        free(object->name);
        object->name = NULL;
    }
    if (object->mail != NULL) {
        free(object->mail);
        object->mail = NULL;
    }
}

// Compare two users
bool user_equals(tUser* user1, tUser* user2) {

    // Verify pre conditions
    assert(user1 != NULL);
    assert(user2 != NULL);

    // To see if two users are equals, we need to see ALL the values for their fields are equals.    
    // Strings are pointers to a table of chars, therefore, cannot be compared  as  
    // " user1->username == user2->username ". We need to use a string comparison function    

    if (strcmp(user1->username, user2->username) != 0) {
        // Usernames are different
        return false;
    }

    if (strcmp(user1->name, user2->name) != 0) {
        // Names are different
        return false;
    }

    if (strcmp(user1->mail, user2->mail) != 0) {
        // Mails are different
        return false;
    }

    // All fields have the same value
    return true;
}

// Compare two Table of users. There are equals if they have the same number of user, 
// they have the same username. The order of users of two tables could be different
bool userTable_equals(tUserTable* userTable1, tUserTable* userTable2) {
    // Verify pre conditions
    assert(userTable1 != NULL);
    assert(userTable2 != NULL);

    int i;
    if (userTable1->size != userTable2->size) {
        return false;
    }

    for (i = 0; i < userTable1->size; i++)
    {
        // Uses "find" because the order of users could be different
        if (!userTable_find(userTable1, userTable2->elements[i].username)) {
            // Usernames are different
            return false;
        }
    }

    return true;
}

// Copy the data of a user to another user
tError user_cpy(tUser* dst, tUser* src) {

    // Verify pre conditions
    assert(dst != NULL);
    assert(src != NULL);

    // Just in case, free space used by destination object.
    user_free(dst);

    // Initialize the element with the new data
    user_init(dst, src->username, src->name, src->mail);

    return OK;
}

// Initialize the table of users
void userTable_init(tUserTable* table) {
    // Verify pre conditions
    assert(table != NULL);

    // The initialization of a table is to set it to the empty state. 
    // That is, with 0 elements. 
    table->size = 0;
    // Using dynamic memory, the pointer to the elements 
    // must be set to NULL (no memory allocated). 
    // This is the main difference with respect to the user of static memory, 
    // where data was always initialized (tUser elements[MAX_ELEMENTS])
    table->elements = NULL;
}

// Remove the memory used by userTable structure
void userTable_free(tUserTable* table) {
    // Verify pre conditions
    assert(table != NULL);

    // All memory allocated with malloc and realloc 
    // needs to be freed using the free command. 
    // In this case, as we use malloc/realloc to 
    // allocate the elements, and need to free them.
    if (table->elements != NULL) {
        free(table->elements);
        table->elements = NULL;
    }
    // As the table is now empty, assign the size to 0.
    table->size = 0;
}

// Add a new user to the table
tError userTable_add(tUserTable* table, tUser* user) {
    // Verify pre conditions
    assert(table != NULL);
    assert(user != NULL);

    // Check if users already is on the table
    if (userTable_find(table, user->username))
        return ERR_DUPLICATED;

    // The first step is to allocate the required space. 
    // There are two methods to manage the 
    // memory (malloc and realloc). Malloc allows 
    // to allocate a new memory block, while realloc 
    // allows to modify an existing memory block.    
    if (table->size == 0) {
        // Empty table

        // Increase the number of elements of the table
        table->size = 1;

        // Since the table is empty, and we do not have any previous memory block, 
        // we have to use malloc. The amount of memory we need is the number of 
        // elements (will be 1) times the size of one element, which is computed 
        // by sizeof(type). In this case the type is tUser.
        table->elements = (tUser*)malloc(table->size * sizeof(tUser));
    }
    else {
        // table with elements

        // Increase the number of elements of the table
        table->size = table->size + 1;

        // Since the table is not empty, we already have a memory block. 
        // We need to modify the size of this block, using the realloc command. 
        // The amount of memory we need is the number of elements times 
        // the size of one element, which is computed by sizeof(type). 
        // In this case the type is tUser. We provide the previous block of memory.
        table->elements = (tUser*)realloc(table->elements, table->size * sizeof(tUser));
    }

    // Check that the memory has been allocated
    if (table->elements == NULL) {
        // Error allocating or reallocating the memory
        return ERR_MEMORY_ERROR;
    }

    // Once we have the block of memory, which is an array of tUser elements, 
    // we initialize the new element (which is the last one). The last element 
    // is " table->elements[table->size - 1] " (we start counting at 0)
    user_init(&(table->elements[table->size - 1]), user->username, user->name, user->mail);

    return OK;
}

// Remove a user from the table
tError userTable_remove(tUserTable* table, tUser* user) {
    int i;
    bool found;

    // Verify pre conditions
    assert(table != NULL);
    assert(user != NULL);

    // To remove an element of a table, we will move all elements after this element 
    // one position, to fill the space of the removed element.
    found = false;
    for (i = 0; i < table->size; i++) {
        // If the element has been found. Displace this element to the previous element 
        // (will never happend for the first one). We use the ADDRESS of the previous 
        // element &(table->elements[i-1]) as destination, and ADDRESS of the current 
        // element &(table->elements[i]) as source.
        if (found) {
            // Check the return code to detect memory allocation errors
            if (user_cpy(&(table->elements[i - 1]), &(table->elements[i])) == ERR_MEMORY_ERROR) {
                // Error allocating memory. Just stop the process and return memory error.
                return ERR_MEMORY_ERROR;
            }
        }
        else if (strcmp(table->elements[i].username, user->username) == 0) {
            // The current element is the element we want to remove. 
            // Set found flag to true to start element movement.
            found = true;
        }
    }

    // Once removed the element, we need to modify the memory used by the table.
    if (found) {
        // Modify the number of elements
        table->size = table->size - 1;

        // If we are removing the last element, we will assign the pointer 
        // to NULL, since we cannot allocate zero bytes
        if (table->size == 0) {
            table->elements = NULL;
        }
        else {
            // Modify the used memory. As we are modifying a previously 
            // allocated block, we need to use the realloc command.
            table->elements = (tUser*)realloc(table->elements, table->size * sizeof(tUser));

            // Check that the memory has been allocated
            if (table->elements == NULL) {
                // Error allocating or reallocating the memory
                return ERR_MEMORY_ERROR;
            }
        }
    }
    else {
        // If the element was not in the table, return an error.
        return ERR_NOT_FOUND;
    }

    return OK;
}

// Get user by username
tUser* userTable_find(tUserTable* table, const char* username) {
    int i;

    // Verify pre conditions
    assert(table != NULL);
    assert(username != NULL);

    // Search over the table and return once we found the element.
    for (i = 0; i < table->size; i++) {
        if (strcmp(table->elements[i].username, username) == 0) {
            // We return the ADDRESS (&) of the element, which is a pointer to the element
            return &(table->elements[i]);
        }
    }

    // The element has not been found. Return NULL (empty pointer).
    return NULL;
}

// Get the size of a the table
unsigned int userTable_size(tUserTable* table) {
    // Verify pre conditions
    assert(table != NULL);

    // The size of the table is the number of elements. This value is stored in the "size" field.
    return table->size;
}

/* Remove the spaces at the beginning and end of the name (or name and surname).
 * Ensure that the first character of each name / surname has its first letter in uppercase, 
 * and the rest of the characters in lower case.
 */
tError user_trimCapitalizeName(tUser* object) {
 assert(object != NULL);
    
    int i;
    bool space;
    space = false;
    if(object->name != NULL){
        //We trim spaces at the start and the end of the name
        strcpy(object->name, trim(object->name));
        //First character after Trim must be uppercase
        object->name[0] = toupper(object->name[0]);
        for(i = 1; i < strlen(object->name); i++){
            if(space){
                //If the previous character was a space this character must be uppercase
                object->name[i] = toupper(object->name[i]);
                space = false;
            }else{
                //If the character is not a space, must be lowercase
                if(isspace(object->name[i])){
                    space = true;
                }else{
                    object->name[i] = tolower(object->name[i]);
                }
            }
        }
        return OK;
    }       
    return ERR_NOT_IMPLEMENTED;
}