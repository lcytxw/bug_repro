#define _GNU_SOURCE 
#include <endian.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <string.h>

static uintptr_t syz_open_dev(uintptr_t a0, uintptr_t a1, uintptr_t a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

uint64_t r[1] = {0xffffffffffffffff};
void loop()
{
	long res = 0;
memcpy((void*)0x20000040, "/dev/snd/seq", 13);
	res = syz_open_dev(0x20000040, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 0x7fffffff;
*(uint32_t*)0x200001c4 = 1;
memcpy((void*)0x200001c8, "\x63\x6c\x69\x65\x6e\x74\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint32_t*)0x20000208 = 2;
memcpy((void*)0x2000020c, "\x08\xf5\x91\x0c\xf6\x9b\xfb\x4f", 8);
memcpy((void*)0x20000214, "\x98\x7d\xb3\xfd\xe3\xbe\xff\xe6\x8f\x00\xa7\x6f\xf4\xae\x65\x2d\xd6\x2f\x3d\x3e\x7b\x79\x37\x0c\x92\x74\x7f\xe0\x8d\x5d\x3f\x5e", 32);
*(uint32_t*)0x20000234 = 0x59b;
*(uint32_t*)0x20000238 = 5;
*(uint8_t*)0x2000023c = 0;
*(uint8_t*)0x2000023d = 0;
*(uint8_t*)0x2000023e = 0;
*(uint8_t*)0x2000023f = 0;
*(uint8_t*)0x20000240 = 0;
*(uint8_t*)0x20000241 = 0;
*(uint8_t*)0x20000242 = 0;
*(uint8_t*)0x20000243 = 0;
*(uint8_t*)0x20000244 = 0;
*(uint8_t*)0x20000245 = 0;
*(uint8_t*)0x20000246 = 0;
*(uint8_t*)0x20000247 = 0;
*(uint8_t*)0x20000248 = 0;
*(uint8_t*)0x20000249 = 0;
*(uint8_t*)0x2000024a = 0;
*(uint8_t*)0x2000024b = 0;
*(uint8_t*)0x2000024c = 0;
*(uint8_t*)0x2000024d = 0;
*(uint8_t*)0x2000024e = 0;
*(uint8_t*)0x2000024f = 0;
*(uint8_t*)0x20000250 = 0;
*(uint8_t*)0x20000251 = 0;
*(uint8_t*)0x20000252 = 0;
*(uint8_t*)0x20000253 = 0;
*(uint8_t*)0x20000254 = 0;
*(uint8_t*)0x20000255 = 0;
*(uint8_t*)0x20000256 = 0;
*(uint8_t*)0x20000257 = 0;
*(uint8_t*)0x20000258 = 0;
*(uint8_t*)0x20000259 = 0;
*(uint8_t*)0x2000025a = 0;
*(uint8_t*)0x2000025b = 0;
*(uint8_t*)0x2000025c = 0;
*(uint8_t*)0x2000025d = 0;
*(uint8_t*)0x2000025e = 0;
*(uint8_t*)0x2000025f = 0;
*(uint8_t*)0x20000260 = 0;
*(uint8_t*)0x20000261 = 0;
*(uint8_t*)0x20000262 = 0;
*(uint8_t*)0x20000263 = 0;
*(uint8_t*)0x20000264 = 0;
*(uint8_t*)0x20000265 = 0;
*(uint8_t*)0x20000266 = 0;
*(uint8_t*)0x20000267 = 0;
*(uint8_t*)0x20000268 = 0;
*(uint8_t*)0x20000269 = 0;
*(uint8_t*)0x2000026a = 0;
*(uint8_t*)0x2000026b = 0;
*(uint8_t*)0x2000026c = 0;
*(uint8_t*)0x2000026d = 0;
*(uint8_t*)0x2000026e = 0;
*(uint8_t*)0x2000026f = 0;
*(uint8_t*)0x20000270 = 0;
*(uint8_t*)0x20000271 = 0;
*(uint8_t*)0x20000272 = 0;
*(uint8_t*)0x20000273 = 0;
*(uint8_t*)0x20000274 = 0;
*(uint8_t*)0x20000275 = 0;
*(uint8_t*)0x20000276 = 0;
*(uint8_t*)0x20000277 = 0;
*(uint8_t*)0x20000278 = 0;
*(uint8_t*)0x20000279 = 0;
*(uint8_t*)0x2000027a = 0;
*(uint8_t*)0x2000027b = 0;
	syscall(__NR_ioctl, r[0], 0xc0bc5351, 0x200001c0);
}

int main()
{
	syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
	loop();
	return 0;
}
