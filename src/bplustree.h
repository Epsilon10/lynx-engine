
typedef struct  {
    char* data;
} lx_bt_record_t;
typedef struct lx_bt_node_t {
    void** pointers;
    int* keys;
    struct lx_bt_node_t* parent;
    bool is_leaf;
    int num_keys;
    struct node* next;
} lx_bt_node_t;
