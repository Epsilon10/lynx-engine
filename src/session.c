#include "types.h"

lx_cursor_t* create_cursor(lx_session_t* session, char* key, void* value) {
    session->cursor = (lx_cursor_t*) malloc(sizeof(lx_cursor_t));
    session->cursor.key = key;
    session->cursor.value = value;
    session->cursor.document = NULL;
    return session->cursor;
}

int search(lx_session_t* session, lx_cursor_t* cursor, char* key, void* id) {
    lx_document_t* docs = session->collection.documents;
    for (int i = 0; i < session->collection.num_docs; i++) {
        if (docs[i].id == id) {
            // parse the file
            
        }
    }
} // returns document index where match was found


