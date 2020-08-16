#include "dex_string.h"
#include "DexFile.h"
#include "uleb128.h"
#include "dex_other_item.h"

/*
获取指定class的class名称
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
char* class_type(DexHeader* header, u4 index);

/*
获取指定class的访问权限
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
u4 access_flags(DexHeader* header, u4 index);

/*
获取指定class的父类名称
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
char* class_super(DexHeader* header, u4 index);

/*
获取指定class的源文件名称
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
char* class_source_file(DexHeader* header, u4 index);

/*
获取指定class的实现的全部接口的名称列表
@return : char**
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
char** class_interface(DexHeader* header, u4 index);

/*
获取指定class的注解信息，尚未定义注解的结构无法解析
@return : u8
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
u8 class_annotations(DexHeader* header, u4 index);

/*
获取指定class的静态变量信息，书中未明确，尚未解析
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
DexEncodedArray* get_static_value(DexHeader* header, u4 index);

/*
获取指定class的详细成员变量与成员函数的信息，未定义结构，尚未解析
@return : char*
@header : 目标dex文件
@index  : 指定DexClassDef索引
*/
u8 get_class_data(DexHeader* header, u4 index);