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

void lx_bson_collection_init(char* name, char* filepaths) {
    int fd;
    char* map;

    lx_collection_t* collection = (lx_collection_t*) malloc(sizeof(lx_collection_t));
    char* filepath;
    size_t num_docs = sizeof(filepaths);
    collection->name = name;
    lx_bt_node_t* root;
    for(int i = 0; i < num_docs; i++) {
        collection->key = i;
        filpath = &filepaths[i];
        fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
        if (fd == -1) {
            perror("Error opening file for writing");
            exit(EXIT_FAILURE);
        }
        
        int result = lseek(fd, FILESIZE-1, SEEK_SET);
        result = write(fd, "", 1);
        collection->documents[i].value = mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        char* c = map;
        while (c != NULL) {
            if (c == '\n') {
                c++;
            // find the id somehow
                collection->documents[i].id = 
        }

        if (i == 0) {
            root = lx_bt_new(i, collection->documents[i]);
        }
        else {
            
        }
    }

}

    

    


}

void* lx_bson_find(char* collection_name,  key, void* id) {

}

