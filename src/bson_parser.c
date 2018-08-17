#include "bson_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "bplustree.h"
#include "types.h"

lx_collection_t* lx_bson_collection_init(char* name, char* filepaths) {
    int fd;
    char* map;

    lx_collection_t* collection = (lx_collection_t*) malloc(sizeof(lx_collection_t));
    char* filepath;
    size_t num_docs = sizeof(filepaths);
    collection->name = name;
    lx_bt_node_t* root;
    for(int i = 0; i < num_docs; i++) {
        filpath = &filepaths[i];
        fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
        if (fd == -1) {
            perror("Error opening file for writing");
            exit(EXIT_FAILURE);
        }
        
        int result = lseek(fd, FILESIZE-1, SEEK_SET);
        result = write(fd, "", 1);
        if (i == 0) {
            root = lx_bt_new(i,mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        }
        else {
            lx_bt_insert(root, lx_bson_get_index(filepath), mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // use string binary as key value
        }
    }

    collection->root = root;
    collection->num_docs = num_docs;
    free(filepaths);
    return collection;
}

    

    


}

int lx_bson_find(lx_collection_t* collection, char* index, char* key) {
    uint32_t* bson_index = index;

    lx_bt_find(collection->root, )
}

char* lx_bson_encode_to_document(char* buf, char* index, size_t size) {
    // make a new file
    // get the filepath
    char* begin, end, c;
    buf_end = buf + size;
    char* traverse;
    char* str;
    begin = end = buf;
    while (1) {
        if (! (*end == '\r' || *end == '\n')) {
            if (++end < buf_end) continue;
        } else if (1 + end < buf_end) {
        c = *(1 + end);
        if ( (c == '\r' || c == '\n') && c != *end)
            ++end;
        }
        traverse = begin;
        while (traverse != end) {
            strcpy(str, traverse);
            traverse++;
        }
 
        if ((begin = ++end) >= buf_end)
            break;
        }    
}

void parse_string(char* data, char* bson_array) {
    char* c = traverse = data;
    char* key, value, traverse;
    while (c != NULL) {
        if (*c == ':') {
            while (traverse != c) {
                strcpy(key, traverse);
                traverse++;
            }
            traverse = &c[1];

            while (traverse != '\0') {
                strcpy(value, traverse);
                traverse++;
            }
        }

        int size_key = ((int) sizeof(key));
        int size_val = ((int) sizeof(value));
        bson_array[0] = hex_converter(size_key + size_val + 5);
         
        c++;
    }
}

char* hex_converter(int val) [

]