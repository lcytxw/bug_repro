#define _GNU_SOURCE 
#include <endian.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
void loop()
{
	long res = 0;
	res = syscall(__NR_inotify_init);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_dup2, r[0], r[0]);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_dup2, r[0], r[1]);
	if (res != -1)
		r[2] = res;
	syscall(__NR_close, r[1]);
	res = syscall(__NR_socket, 2, 2, 0);
	if (res != -1)
		r[3] = res;
*(uint8_t*)0x200013c0 = 0;
*(uint8_t*)0x200013c1 = 0;
*(uint8_t*)0x200013c2 = 0;
*(uint8_t*)0x200013c3 = 0;
*(uint8_t*)0x200013c4 = 0;
*(uint8_t*)0x200013c5 = 0;
*(uint8_t*)0x200013c6 = 0;
*(uint8_t*)0x200013c7 = 0;
*(uint8_t*)0x200013c8 = 0;
*(uint8_t*)0x200013c9 = 0;
*(uint8_t*)0x200013ca = -1;
*(uint8_t*)0x200013cb = -1;
*(uint32_t*)0x200013cc = htobe32(0);
*(uint8_t*)0x200013d0 = -1;
*(uint8_t*)0x200013d1 = 2;
*(uint8_t*)0x200013d2 = 0;
*(uint8_t*)0x200013d3 = 0;
*(uint8_t*)0x200013d4 = 0;
*(uint8_t*)0x200013d5 = 0;
*(uint8_t*)0x200013d6 = 0;
*(uint8_t*)0x200013d7 = 0;
*(uint8_t*)0x200013d8 = 0;
*(uint8_t*)0x200013d9 = 0;
*(uint8_t*)0x200013da = 0;
*(uint8_t*)0x200013db = 0;
*(uint8_t*)0x200013dc = 0;
*(uint8_t*)0x200013dd = 0;
*(uint8_t*)0x200013de = 0;
*(uint8_t*)0x200013df = 1;
*(uint16_t*)0x200013e0 = htobe16(0);
*(uint16_t*)0x200013e2 = htobe16(0);
*(uint16_t*)0x200013e4 = htobe16(0);
*(uint16_t*)0x200013e6 = htobe16(0);
*(uint16_t*)0x200013e8 = 2;
*(uint8_t*)0x200013ea = 0;
*(uint8_t*)0x200013eb = 0xa0;
*(uint8_t*)0x200013ec = 0;
*(uint32_t*)0x200013f0 = 0;
*(uint32_t*)0x200013f4 = 0;
*(uint64_t*)0x200013f8 = 0;
*(uint64_t*)0x20001400 = 0;
*(uint64_t*)0x20001408 = 0;
*(uint64_t*)0x20001410 = 0;
*(uint64_t*)0x20001418 = 0;
*(uint64_t*)0x20001420 = 0;
*(uint64_t*)0x20001428 = 0;
*(uint64_t*)0x20001430 = 0;
*(uint64_t*)0x20001438 = 0;
*(uint64_t*)0x20001440 = 0;
*(uint64_t*)0x20001448 = 0;
*(uint64_t*)0x20001450 = 0;
*(uint32_t*)0x20001458 = 0;
*(uint32_t*)0x2000145c = 0;
*(uint8_t*)0x20001460 = 1;
*(uint8_t*)0x20001461 = 0;
*(uint8_t*)0x20001462 = 0;
*(uint8_t*)0x20001463 = 0;
*(uint8_t*)0x20001468 = 0xfe;
*(uint8_t*)0x20001469 = 0x80;
*(uint8_t*)0x2000146a = 0;
*(uint8_t*)0x2000146b = 0;
*(uint8_t*)0x2000146c = 0;
*(uint8_t*)0x2000146d = 0;
*(uint8_t*)0x2000146e = 0;
*(uint8_t*)0x2000146f = 0;
*(uint8_t*)0x20001470 = 0;
*(uint8_t*)0x20001471 = 0;
*(uint8_t*)0x20001472 = 0;
*(uint8_t*)0x20001473 = 0;
*(uint8_t*)0x20001474 = 0;
*(uint8_t*)0x20001475 = 0;
*(uint8_t*)0x20001476 = 0;
*(uint8_t*)0x20001477 = 0xbb;
*(uint32_t*)0x20001478 = htobe32(0);
*(uint8_t*)0x2000147c = 0x33;
*(uint16_t*)0x20001480 = 0;
*(uint8_t*)0x20001484 = 0;
*(uint8_t*)0x20001485 = 0;
*(uint8_t*)0x20001486 = 0;
*(uint8_t*)0x20001487 = 0;
*(uint8_t*)0x20001488 = 0;
*(uint8_t*)0x20001489 = 0;
*(uint8_t*)0x2000148a = 0;
*(uint8_t*)0x2000148b = 0;
*(uint8_t*)0x2000148c = 0;
*(uint8_t*)0x2000148d = 0;
*(uint8_t*)0x2000148e = 0;
*(uint8_t*)0x2000148f = 0;
*(uint8_t*)0x20001490 = 0;
*(uint8_t*)0x20001491 = 0;
*(uint8_t*)0x20001492 = 0;
*(uint8_t*)0x20001493 = 0;
*(uint32_t*)0x20001494 = 0;
*(uint8_t*)0x20001498 = 0;
*(uint8_t*)0x20001499 = 0;
*(uint8_t*)0x2000149a = 0;
*(uint32_t*)0x2000149c = 0;
*(uint32_t*)0x200014a0 = 0;
*(uint32_t*)0x200014a4 = 0;
	syscall(__NR_setsockopt, r[2], 0, 0x11, 0x200013c0, 0xe8);
*(uint16_t*)0x20001540 = 2;
*(uint16_t*)0x20001542 = htobe16(0x4e24);
*(uint32_t*)0x20001544 = htobe32(0);
*(uint8_t*)0x20001548 = 0;
*(uint8_t*)0x20001549 = 0;
*(uint8_t*)0x2000154a = 0;
*(uint8_t*)0x2000154b = 0;
*(uint8_t*)0x2000154c = 0;
*(uint8_t*)0x2000154d = 0;
*(uint8_t*)0x2000154e = 0;
*(uint8_t*)0x2000154f = 0;
	syscall(__NR_sendto, r[3], 0x200014c0, 0, 0, 0x20001540, 0x10);
}

int main()
{
	syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
	loop();
	return 0;
}