#define ORDER 4
#include <stdlib.h>
#include <string.h>

#include "bplustree.h"

lx_bt_node_t* find_leaf(lx_bt_node_t* root, int key) {
    int i = 0;
    lx_bt_node_t* c = root;
    while(!c->is_leaf) {
        i = 0;
        while (i < c->num_keys) {
            if (key >= c->keys[i]) {
                i++;
            }
            else {
                break;
            }
        }
        c=(lx_bt_node_t*) c->keys[i];
    }
    return c;
}

lx_bt_record_t* find(lx_bt_node_t* root, int key, lx_bt_node_t** leaf_out) {
    if (root == NULL) {
        if (leaf_out != NULL) {
            *leaf_out = NULL;
        }

        return NULL;
    }

    int i = 0;
    lx_bt_node_t* leaf = find_leaf(root, key);
    for (; i<leaf->num_keys; i++) {
        if (leaf->keys[i] == key) {
            break;
        }
    }

    if (leaf_out != NULL) {
        *leaf_out = leaf;
    }
    if (i == leaf->num_keys) {
        return NULL;
    }

    return (lx_bt_record_t*)leaf->pointers[i];

}

lx_bt_record_t* create_record(char* data) {
    lx_bt_record_t* record = (lx_bt_record_t*) malloc(sizeof(lx_bt_record_t));
    record->data = data;
    return record;
}

lx_bt_node_t* lx_bt_new(int key, lx_bt_record_t* ptr) {
    lx_bt_node_t* root = lx_bt_make_leaf();
    root->keys[0] = key;
    root->pointers[0] = ptr;
    root->pointers[ORDER - 1] = NULL;
    root->parent = NULL;
    root->num_keys++;
    return root;
}

lx_bt_node_t* insert_into_parent(lx_bt_node_t* root, lx_bt_node_t* left, int key, lx_bt_node_t* right) {
    int left_index;
    lx_bt_node_t* parent;
    parent = left->parent;

    left_index = get_left_index()
}

lx_bt_node_t* lx_bt_insert_after_splitting(lx_bt_node_t* root, lx_bt_node_t* leaf, int key, lx_document_t* document) {
    lx_bt_node_t* new_leaf;
    int* temp_keys;
    void** temp_ptrs;
    int insertion_index, split, new_key, i, j;
	insertion_index = 0;
	while (insertion_index < ORDER - 1 && leaf->keys[insertion_index] < key)
		insertion_index++;

	for (i = 0, j = 0; i < leaf->num_keys; i++, j++) {
		if (j == insertion_index) j++;
		temp_keys[j] = leaf->keys[i];
		temp_ptrs[j] = leaf->pointers[i];
	}

	temp_keys[insertion_index] = key;
	temp_ptrs[insertion_index] = document;

	leaf->num_keys = 0;

	split = cut(ORDER - 1);

	for (i = 0; i < split; i++) {
		leaf->pointers[i] = temp_ptrs[i];
		leaf->keys[i] = temp_keys[i];
		leaf->num_keys++;
	}

	for (i = split, j = 0; i < ORDER; i++, j++) {
		new_leaf->pointers[j] = temp_ptrs[i];
		new_leaf->keys[j] = temp_keys[i];
		new_leaf->num_keys++;
	}

	free(temp_ptrs);
	free(temp_keys);

	new_leaf->pointers[ORDER - 1] = leaf->pointers[ORDER - 1];
	leaf->pointers[ORDER - 1] = new_leaf;

	for (i = leaf->num_keys; i < ORDER - 1; i++)
		leaf->pointers[i] = NULL;
	for (i = new_leaf->num_keys; i < ORDER - 1; i++)
		new_leaf->pointers[i] = NULL;

	new_leaf->parent = leaf->parent;
	new_key = new_leaf->keys[0];

	return insert_into_parent(root, leaf, new_key, new_leaf);
    
}