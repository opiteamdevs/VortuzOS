#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

// Tipos primitivos próprios do IoKeyupy (evitando a libc do hospedeiro)
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef char               i8;
typedef short              i16;
typedef int                i32;
typedef long long          i64;

typedef u32                size_t;

// Funções da nossa biblioteca kernel_utils
void safe_print(const char* str);
i32 osExecute(const char* process_name);
void blockProcess(u32 process_id);

#endif
