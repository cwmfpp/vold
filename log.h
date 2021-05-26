#ifndef LOG_H
#define LOG_H

#include <stdio.h>

//#define SLOGE(fmt, args...) printf("%s:"fmt, __FUNCTION__, ##args)
#ifndef SLOGW
#define SLOGW(fmt, x...)  printf("%s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##x);
#endif

#ifndef SLOGE
#define SLOGE(fmt, x...)  printf("%s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##x);
#endif

#ifndef SLOGV
#define SLOGV(fmt, x...)  printf("%s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##x);
#endif

#ifndef SLOGD
#define SLOGD(fmt, x...)  printf("%s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##x);
#endif

#ifndef LOG
#define LOG //
#endif

#endif // LOG_H
