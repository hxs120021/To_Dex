#include "dex_string.h"
#include "DexFile.h"
#include "uleb128.h"

/*
指定类型索引指定的类型对应的string索引
@return : u4
@header : 目标dex文件
@index  : 指定dex文件中DexTypeId数组索引
*/
u4 type_idx(DexHeader *header, u4 index);

/*
数组索引指定的DexFieldId数组元素(字段名称)
@return : DexFieldId*
@header : 目标dex文件
@index  : 指定dex文件中DexFieldId数组索引
*/
DexFieldId* field_idx(DexHeader* header, u4 index);


/*
数组索引指定的DexMethodId数组元素(函数名)
@return : DexMethodId*
@header : 目标dex文件
@index  : 指定dex文件中DexMethodId数组索引
*/
DexMethodId* method_idx(DexHeader* header, u4 index);


/*
数组索引指定的DexProtoId数组元素(函数参数信息&返回值信息)
@return : DexProtoId*
@header : 目标dex文件
@index  : 指定dex文件中DexProtoId数组索引
*/
DexProtoId* proto_idx(DexHeader* header, u4 index);

/*
简述用于指定的DexProtoId数组元素函数参数类型信息，单通常只有'L'等简要信息
@return : char*
@header : 目标dex文件
@index  : 指定dex文件中DexProtoId数组索引
*/
char* proto_shorty(DexHeader* header, u4 index);

/*
详细描述指定DexProtoId数组元素对应的函数的返回信息
@return : char*
@header : 目标dex文件
@index  : 指定dex文件中DexProtoId数组索引
*/
char* proto_return_type(DexHeader* header, u4 index);

/*
详细描述指定DexProtoId数组元素对应的函数的参数列表类型详细信息
@return : char**
@header : 目标dex文件
@index  : 指定dex文件中DexProtoId数组索引
*/
char** parameters_list(DexHeader* header, u4 index);

/*
从指定的DexTypeList中获取参数列表详细信息
@return : char**
@header : 目标dex文件
@type_list  : 指定DexTypeList
*/
char** get_type_list(DexHeader* header, DexTypeList* type_list);