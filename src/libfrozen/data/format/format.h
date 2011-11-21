/* Autogenerated file. Don't edit */
#ifndef FORMAT_H
#define FORMAT_H

typedef struct keypair_t {
    char *        key_str;
    uintmax_t     key_val;
} keypair_t;

extern keypair_t formats[];
extern size_t formats_size;
extern size_t formats_nelements;

#define FORMAT(value)         FORMAT_##value
typedef uintmax_t format_t;

#define FORMAT_binary 1
#define FORMAT_clean 2
#define FORMAT_human 3
#define FORMAT_value 4
#endif
#ifdef FORMAT_C
keypair_t formats[] = {
{ "binary", 1 }, 
{ "clean", 2 }, 
{ "human", 3 }, 
{ "value", 4 }, 
};
size_t formats_size       = sizeof(formats[0]);
size_t formats_nelements  = (sizeof(formats)/sizeof(formats[0]));
#endif