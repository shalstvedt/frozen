/* Autogenerated file. Don't edit */
#ifndef FORMAT_H
#define FORMAT_H

extern keypair_t formats[];
extern size_t formats_size;
extern size_t formats_nelements;

#define FORMAT(value)         FORMAT_##value
typedef uintmax_t format_t;

#define FORMAT_binary 1
#define FORMAT_clean 2
#define FORMAT_config 3
#define FORMAT_debug 4
#define FORMAT_hash 5
#define FORMAT_human 6
#define FORMAT_ip_dothexint 7
#define FORMAT_ip_dotint 8
#define FORMAT_ip_dotoctint 9
#define FORMAT_ip_hexint 10
#define FORMAT_ip_int 11
#define FORMAT_netstring 12
#define FORMAT_time_dot_dmy 13
#define FORMAT_time_dot_dmyhm 14
#define FORMAT_time_dot_dmyhms 15
#define FORMAT_time_plain 16
#define FORMAT_time_rfc2822 17
#define FORMAT_time_rfc3339 18
#define FORMAT_time_slash_dmy 19
#define FORMAT_time_slash_dmyhm 20
#define FORMAT_time_slash_dmyhms 21
#define FORMAT_time_unix 22
#define FORMAT_value 23
#endif
#ifdef FORMAT_C
keypair_t formats[] = {
{ "binary", 1 }, 
{ "clean", 2 }, 
{ "config", 3 }, 
{ "debug", 4 }, 
{ "hash", 5 }, 
{ "human", 6 }, 
{ "ip_dothexint", 7 }, 
{ "ip_dotint", 8 }, 
{ "ip_dotoctint", 9 }, 
{ "ip_hexint", 10 }, 
{ "ip_int", 11 }, 
{ "netstring", 12 }, 
{ "time_dot_dmy", 13 }, 
{ "time_dot_dmyhm", 14 }, 
{ "time_dot_dmyhms", 15 }, 
{ "time_plain", 16 }, 
{ "time_rfc2822", 17 }, 
{ "time_rfc3339", 18 }, 
{ "time_slash_dmy", 19 }, 
{ "time_slash_dmyhm", 20 }, 
{ "time_slash_dmyhms", 21 }, 
{ "time_unix", 22 }, 
{ "value", 23 }, 
};
size_t formats_size       = sizeof(formats[0]);
size_t formats_nelements  = (sizeof(formats)/sizeof(formats[0]));
#endif
