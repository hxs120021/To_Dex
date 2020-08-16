#include "class_def.h"



char* class_type(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    u4 type_index = current_class->classIdx;
    u4 string_index = type_idx(header, type_index);
    return getString(header, string_index);
}

u4 access_flags(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    return current_class->accessFlags;
}

char* class_super(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    u4 type_index = current_class->superclassIdx;
    u4 string_index = type_idx(header, type_index);
    return getString(header, string_index);
}

char* class_source_file(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    return getString(header, current_class->sourceFileIdx);
}

char** class_interface(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;
    DexTypeList* type_list = (DexTypeList*)(current_class->interfacesOff + (u8)header);

    return get_type_list(header, type_list);
}

u8 class_annotations(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;
    return current_class->annotationsOff + (u8)header;
}

DexEncodedArray* get_static_value(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    return (DexEncodedArray*)(current_class->staticValuesOff + (u8)header);
}

u8 get_class_data(DexHeader* header, u4 index){
    DexClassDef* current_class = (DexClassDef*)(header->classDefsOff + (u8)header) + index;

    return current_class->classDataOff;
}