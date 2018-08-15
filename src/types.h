#include "msgpack.h"

typedef msgpack_sbuffer buffer;

typedef struct {
    size_t num_collections;
    char* name;
    lx_document_t* documents;
    lx_bt_node_t* root;
} lx_collection_t;


typedef struct {
    void* id;
    char* data;
} lx_document_t;

typedef struct {
    char* key;
    void* value;
} lx_cursor_t;

typedef struct {
    lx_cursor_t* cursor;
} lx_session_t;

#define LX_PACK_BUFFER(pk, buf) msgpack_packer_init((pk), (buf), msgpack_sbuffer_write)
#define LX_ARRAY(packer, size) msgpack_pack_array((packer), (size))
