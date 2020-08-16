#include "DexFile.h"
#include <string.h>
/*
获取string 数组查长度
@header : 目标dex文件
*/
u4 string_ids_size(DexHeader* header);

/*string 数组位于文件的偏移
@header : 目标dex文件
*/
u4 string_ids_off(DexHeader* header);

/*string 数组的起始位置
@header : 目标dex文件
*/
DexStringId* string_ids_start(DexHeader* header);

/*string 数组的第 index 个元素
@header : 目标dex文件
@index  : 指定索引
*/
u8 string_data_item(DexHeader* header, u8 index);