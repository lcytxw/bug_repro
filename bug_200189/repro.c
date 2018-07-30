#define _GNU_SOURCE 
#include <endian.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/futex.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct thread_t {
	int created, running, call;
	pthread_t th;
};

static struct thread_t threads[16];
static void execute_call(int call);
static int running;
static int collide;

static void* thr(void* arg)
{
	struct thread_t* th = (struct thread_t*)arg;
	for (;;) {
		while (!__atomic_load_n(&th->running, __ATOMIC_ACQUIRE))
			syscall(SYS_futex, &th->running, FUTEX_WAIT, 0, 0);
		execute_call(th->call);
		__atomic_fetch_sub(&running, 1, __ATOMIC_RELAXED);
		__atomic_store_n(&th->running, 0, __ATOMIC_RELEASE);
		syscall(SYS_futex, &th->running, FUTEX_WAKE);
	}
	return 0;
}

static void execute(int num_calls)
{
	int call, thread;
	running = 0;
	for (call = 0; call < num_calls; call++) {
		for (thread = 0; thread < sizeof(threads) / sizeof(threads[0]); thread++) {
			struct thread_t* th = &threads[thread];
			if (!th->created) {
				th->created = 1;
				pthread_attr_t attr;
				pthread_attr_init(&attr);
				pthread_attr_setstacksize(&attr, 128 << 10);
				pthread_create(&th->th, &attr, thr, th);
			}
			if (!__atomic_load_n(&th->running, __ATOMIC_ACQUIRE)) {
				th->call = call;
				__atomic_fetch_add(&running, 1, __ATOMIC_RELAXED);
				__atomic_store_n(&th->running, 1, __ATOMIC_RELEASE);
				syscall(SYS_futex, &th->running, FUTEX_WAKE);
				if (collide && call % 2)
					break;
				struct timespec ts;
				ts.tv_sec = 0;
				ts.tv_nsec = 20 * 1000 * 1000;
				syscall(SYS_futex, &th->running, FUTEX_WAIT, 1, &ts);
				if (running)
					usleep((call == num_calls - 1) ? 10000 : 1000);
				break;
			}
		}
	}
}

void execute_call(int call)
{
	switch (call) {
	case 0:
*(uint64_t*)0x20000300 = 0;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 1;
*(uint64_t*)0x20000310 = 0x20000140;
*(uint64_t*)0x20000318 = 0x20000200;
		syscall(__NR_timer_create, 0, 0x20000300, 0x20000340);
		break;
	case 1:
*(uint64_t*)0x200001c0 = 0;
*(uint64_t*)0x200001c8 = 0x989680;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0x1c9c380;
		syscall(__NR_timer_settime, 0, 0xfffffffffffffffd, 0x200001c0, 0x20000280);
		break;
	case 2:
*(uint64_t*)0x20000200 = 0;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0x77359400;
*(uint64_t*)0x20000218 = 0;
		syscall(__NR_timer_settime, 0, 0, 0x20000200, 0x20000240);
		break;
	}
}

void loop()
{
	execute(3);
	collide = 1;
	execute(3);
}

int main()
{
	syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
	loop();
	return 0;
}
