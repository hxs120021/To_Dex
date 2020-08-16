#include "dex_other_item.h"


u4 type_idx(DexHeader *header, u4 index){
    return ((DexTypeId*)(header->typeIdsOff + (u8)header) + index)->descriptorIdx;
}

DexFieldId* field_idx(DexHeader* header, u4 index){
    return ((DexFieldId*)(header->fieldIdsOff + (u8)header) + index);
}

DexMethodId* method_idx(DexHeader* header, u4 index){
    return ((DexMethodId*)(header->methodIdsOff + (u8)header) + index);
}

DexProtoId* proto_idx(DexHeader* header, u4 index){
    return ((DexProtoId*)(header->protoIdsOff + (u8)header) + index);
}

char* proto_shorty(DexHeader* header, u4 index){
    u4 shorty_idx = proto_idx(header, index)->shortyIdx;
    return (char*)getString(header, shorty_idx);
}

char* proto_return_type(DexHeader* header, u4 index){
    u4 descriptor_idx = proto_idx(header, index)->returnTypeIdx;
    u4 string_data_idx = type_idx(header, descriptor_idx);
    return (char*)getString(header, string_data_idx);
}

char** parameters_list(DexHeader* header, u4 index){
    
    DexTypeList* type_list = (DexTypeList*)((u8)header + (proto_idx(header, index))->parametersOff);
    return get_type_list(header, type_list);
}

char** get_type_list(DexHeader* header, DexTypeList* type_list){

    char* _types[type_list->size];
    for(int i = 0; i < type_list->size; i++){
        u2 tmp_type_idx = type_idx(header, type_list->list[i].typeIdx);
        _types[i] = getString(header, tmp_type_idx);
    }

    return _types;
}