#include "header.h"

typedef int mem_word_t;

static mem_word_t _memory_pool[MEM_SIZE];

mem_word_t read_word_from_mem(location_t location)
{
	assert(location < 100);
	assert(location >= 0);

	return _memory_pool[location];
}

void write_word_to_mem(location_t location, int data)
{
	assert(location < 100);
	assert(location >= 0);
	_memory_pool[location] = data;
}

void dump_memory(void)
{
	int i;

	printf("Memory Dump\n");
	for (i = 0; i < 100; i++)
	{
		if ((i % 10) == 0)
			putchar('\n');
		printf("%.4d  ", read_word_from_mem(i));
	}
}
