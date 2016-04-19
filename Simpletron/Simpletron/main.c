#include "header.h"

extern void dump_memory(void);

int load_instructions()
{
	static int instructs = -1, instruction = -1;
	printf("How many instructions do you want to load?\n");
	scanf("%d", &instructs);

	for (int i = 0; i < instructs; i++)
	{
		printf("Load instruction %d\t", i+1);
		scanf("%d", &instruction);
		write_word_to_mem((location_t)i, instruction);
	}
	return instructs;
}

int main(void)
{
	static int opcode, operand, num_instruct;
	int instruction = 0;
	num_instruct = load_instructions();
	system("cls");

	do
	{
		dump_memory();
		read_and_parse_sml(instruction, &opcode, &operand);
		handle_instruction(&instruction, opcode, operand);
		system("cls");
	} while ((HALT != opcode) &&
			(instruction < num_instruct));

	if (HALT == opcode)
		printf("HALTED\n");
	else
		printf("No more instructions\n");

	system("pause");
	return 0;
}