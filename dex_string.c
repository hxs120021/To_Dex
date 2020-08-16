#include "dex_string.h"

u4 string_ids_size(DexHeader* header){
    return header->stringIdsSize;
}

u4 string_ids_off(DexHeader* header){
    return header->stringIdsOff;
}

DexStringId* string_ids_start(DexHeader* header){
    return (DexStringId*)((u8)header + string_ids_off(header));
}


u8 string_data_item(DexHeader* header, u8 index){
    DexStringId* temp = string_ids_start(header) + index;
    return (u8)header + temp->stringDataOff;
}