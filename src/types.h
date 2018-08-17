#include "msgpack.h"

typedef msgpack_sbuffer buffer;

typedef struct {
    size_t num_docs;
    char* name;
    lx_bt_node_t* root;
} lx_collection_t;


typedef struct {
    char* data;
} lx_document_t;

typedef struct {
    char* key;
    void* value;
    lx_document_t* document;
} lx_cursor_t;

typedef struct {
    lx_cursor_t* cursor;
    lx_collection_t* collection;
} lx_session_t;

typedef struct {
    char* key,
    void* value;
} lx_dict_node_t;

typedef struct {
    lx_dict_node_t* head;
    lx_dict_node_t* next;
} lx_dict_t;

typedef struct {
    void* values;
} lx_list_t;
#define LX_PACK_BUFFER(pk, buf) msgpack_packer_init((pk), (buf), msgpack_sbuffer_write)
#define LX_ARRAY(packer, size) msgpack_pack_array((packer), (size))
