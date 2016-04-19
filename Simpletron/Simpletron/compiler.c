#include "header.h"

static int accumulator;

static void write_accum(int value)
{
	accumulator = value;
}

static int read_accum(void)
{
	return accumulator;
}

static void write_to_terminal(int data)
{
	printf("WRITE\t%d\n", data);
	system("pause");
}

static int read_from_terminal(void)
{
	static int input = -1;
	printf("Value: ");
	scanf("%d", &input);
	return input;
}

char* code_to_string(int code)
{
	switch (code)
	{
	case READ:
		return "READ";
		break;
	case WRITE:
		return "WRITE";
		break;
	case LOAD:
		return "LOAD";
		break;
	case STORE:
		return "STORE";
		break;
	case ADD:
		return "ADD";
		break;
	case SUBTRACT:
		return "SUBTRACT";
		break;
	case DIVIDE:
		return "DIVIDE";
		break;
	case MULTIPLY:
		return "MULTIPLY";
		break;
	case BRANCH:
		return "BRANCH";
		break;
	case BRANCHNEG:
		return "BRANCHNEG";
		break;
	case BRANCHZERO:
		return "BRANCHZERO";
		break;
	default:
		return "INVALID";
	}
}

void read_and_parse_sml(location_t loc, int* code, int* data)
{
	static int sml = -1;
	printf("\n\nAccumulator\t%d\n", read_accum());

	sml = read_word_from_mem(loc);
	*data = sml % 100;
	*code = sml / 100;
	printf("Instruction\t%s %d\n", code_to_string(*code), sml);
}

bool handle_instruction(int* instruction, int opcode, int operand)
{
	static bool result = true;
	static int value = -1;
	*instruction = *instruction + 1;

	switch (opcode)
	{
		case READ:
			value = read_from_terminal();
			write_word_to_mem((location_t)operand, value);
			break;
		case WRITE:
			value = read_word_from_mem((location_t)operand);
			write_to_terminal(value);
			break;
		case LOAD:
			value = read_word_from_mem((location_t)operand);
			write_accum(value);
			break;
		case STORE:
			value = read_accum();
			write_word_to_mem((location_t)operand, value);
			break;
		case ADD:
			write_accum(read_accum() + read_word_from_mem((location_t)operand));
			break;
		case SUBTRACT:
			write_accum(read_accum() - read_word_from_mem((location_t)operand));
			break;
		case DIVIDE:
			write_accum(read_accum() / read_word_from_mem((location_t)operand));
			break;
		case MULTIPLY:
			write_accum(read_accum() * read_word_from_mem((location_t)operand));
			break;
		case BRANCH:
			*instruction = operand;
			break;
		case BRANCHNEG:
			if (read_accum() < 0)
				*instruction = operand;
			break;
		case BRANCHZERO:
			if (read_accum() == 0)
				*instruction = operand;
			break;
		default:
			result = false;
			break;
	}
	return result;
}