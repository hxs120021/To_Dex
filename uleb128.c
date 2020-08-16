#include "uleb128.h"

u4 getLEB128Lenght(char* str)
{
    //初始化长度为1
    u4 index = 1;
  //如果值为0，返回长度
    if (*str)
    {
      // 如果值不为0，查看最高位是否为1
        while (*str++ & 0x80)
        {
        //长度++
            ++index;
        }
    }
    return index;
}

//返回值，此处比之前改进了一下，因为我发现进位时会因为宽度问题导致数值错误
u4 LEB128toInt(char* str)
{
    u8 value = 0;
    u4 index = 0;
    if (*str)
    {
        do {
        //*str & 0X7F是吧最高位设置为0
            u8 m = (*str & 0X7F) << (index * 7);
            value += m;
            ++index;

        } while (*str++ & 0x80);
    }
    return value;
}

int readUnsignedLeb128(const u1** pStream) {
    const u1* ptr = *pStream;
    int result = *(ptr++);
 
    if (result > 0x7f) {
        int cur = *(ptr++);
        result = (result & 0x7f) | ((cur & 0x7f) << 7);
        if (cur > 0x7f) {
            cur = *(ptr++);
            result |= (cur & 0x7f) << 14;
            if (cur > 0x7f) {
                cur = *(ptr++);
                result |= (cur & 0x7f) << 21;
                if (cur > 0x7f) {
                    cur = *(ptr++);
                    result |= cur << 28;
                }
            }
        }
    }
 
    *pStream = ptr;
    return result;
}

//此处我选择写一个函数，因为后面用到的地方太多了。
//第一个参数是dex_header结构体  之前有说怎么获取，这里不提
//第二个参数是指向string_id_item地址的指针  文件开始的地址加上string_ids_off中的偏移 DexStringId* virtualAddress_string,
//第三个参数是找的是第几个string_data_item  取值范围1到string_ids_size直接
char* getString(DexHeader* header, u8 index)
{
//通过取值得到地址的偏移 *(virtualAddress_string + index)，再加上文件开始的地址，

    //char* str = (char*)((u8)IpParameter + *(virtualAddress_string + index));
    char* str = (char*)(string_data_item(header, index));
    //计算字符串长度所占的字节数
    u4 len = LEB128toInt(str);
    //返回正确的字符串首地址
    // return str + n;
    if(len < 0xFF)
        return str + 1;
    else if(len < 0xFFFF)
        return str + 2;
    else if(len < 0xFFFFFF)
        return str + 3;
    else if(len < 0xFFFFFFFF)
        return str + 4;
}