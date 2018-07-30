#define _GNU_SOURCE 
#include <endian.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define BITMASK_LEN(type,bf_len) (type)((1ull << (bf_len)) - 1)

#define BITMASK_LEN_OFF(type,bf_off,bf_len) (type)(BITMASK_LEN(type, (bf_len)) << (bf_off))

#define STORE_BY_BITMASK(type,addr,val,bf_off,bf_len) if ((bf_off) == 0 && (bf_len) == 0) { *(type*)(addr) = (type)(val); } else { type new_val = *(type*)(addr); new_val &= ~BITMASK_LEN_OFF(type, (bf_off), (bf_len)); new_val |= ((type)(val)&BITMASK_LEN(type, (bf_len))) << (bf_off); *(type*)(addr) = new_val; }

uint64_t r[1] = {0xffffffffffffffff};
void loop()
{
	long res = 0;
*(uint32_t*)0x200001c0 = 2;
*(uint32_t*)0x200001c4 = 0x70;
*(uint8_t*)0x200001c8 = 0xfd;
*(uint8_t*)0x200001c9 = 0;
*(uint8_t*)0x200001ca = 0;
*(uint8_t*)0x200001cb = 0;
*(uint32_t*)0x200001cc = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, 0x200001e8, 0, 29, 35);
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f4 = 0;
*(uint64_t*)0x200001f8 = 0;
*(uint64_t*)0x20000200 = 0;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0;
*(uint32_t*)0x20000218 = 0;
*(uint32_t*)0x2000021c = 0;
*(uint64_t*)0x20000220 = 0;
*(uint32_t*)0x20000228 = 0;
*(uint16_t*)0x2000022c = 0;
*(uint16_t*)0x2000022e = 0;
	res = syscall(__NR_perf_event_open, 0x200001c0, 0, 0, -1, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "!", 2);
	syscall(__NR_ioctl, r[0], 0x40082406, 0x20000000);
}

int main()
{
	syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
	loop();
	return 0;
}