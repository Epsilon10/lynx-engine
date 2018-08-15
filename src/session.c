#include "types.h"

void create_cursor(lx_session_t* session, int key) {
    session->cursor = (lx_cursor_t*) malloc(sizeof(lx_cursor_t));
    
}