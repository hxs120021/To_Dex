#include "DexFile.h"
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "uleb128.h"
#include "dex_other_item.h"

int mmap_dex(u8** dex_file, struct stat *st){
    int fd = open("classes.dex", O_RDONLY);
    fstat(fd, st);

    *dex_file = mmap(NULL,
        st->st_size,
        PROT_READ,
        MAP_PRIVATE,
        fd,
        0);
    if(*dex_file == MAP_FAILED)
        return -1;
    else return fd;
}

int main(){
    int fd;
    u8 *dex_file;
    struct stat st;
    fd = mmap_dex(&dex_file, &st);

    DexHeader *header = (DexHeader*)dex_file;
    //printf("%ld", header->endianTag);
    for(int i = 100; i < 110; i++){
        printf("%d: %s\n",i, getString(header, i));
        //string_ids_off(header);
        proto_idx(header, i);
    }
    return 0;
}

