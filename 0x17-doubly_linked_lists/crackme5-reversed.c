#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * segf - Make a segmentation fault
 *
 * Return: Exit with status 1
 */
int segf(void)
{
	int *ptr = NULL;

	*ptr = 0xffffffff;
	exit(1);
}

/**
 * f1 - This function perform a specific operation on len
 * @len: The length of the username
 *
 * Return: The result of calculation
 */
int f1(int len)
{
	return ((len ^ 59) & 63);
}

/**
 * f2 - This function perform a specific operation based on the name passed
 * @name: The username
 * @len: The length of the username
 *
 * Return: The result of calculation
 */
int f2(char *name, int len)
{
	int sum = 0, i = 0;
	while (i < len)
	{
		sum += name[i];
		i++;
	}
	return ((sum ^ 79) & 63);		
}


/**
 * f3 - This function perform a specific operation based on the name passed
 * @name: The username
 * @len: The length of the username
 *
 * Return: The result of calculation
 */
int f3(char *name, int len)
{
	int i= 0, mul= 1;

	while (i < len)
	{
		mul *= *(name + i);
		i++;
	}

	return ((mul ^ 85) & 63);
}

/**
 * f4 - This function perform a specific operation based on the name passed
 * @name: The username
 * @len: The length of the username
 *
 * Return: The result of calculation
 */
int f4(char *name, int len)
{
	int i= 0, max = name[0];

	while (i < len)
	{
		if (name[i] > max)
			max = name[i];
		i++;
	}

	max ^= 14;
	srand(max);
	return (rand() & 63);
}


/**
 * f5 - This function perform a specific operation based on the name passed
 * @name: The username
 * @len: The length of the username
 *
 * Return: The result of calculation
 */
int f5(char *name, int len)
{
	int i= 0, pwr = 0;

	while (i < len)
	{
		pwr += name[i] * name[i];
		i++;
	}

	return ((pwr ^ 239) & 63);
}


/**
 * f6 - This function perform a specific operation based on the len
 * @l: The first letter from the user name
 *
 * Return: The result of calculation
 */
int f6(char l)
{
	int i= 0, rnd = 0;

	while (l > i)
	{
		rnd = rand();
		i++;
	}

	return ((rnd ^ 229) & 63);
}

/**
 * main - Check if the password is correct
 * @argc: The arguments count
 * @argv: The arguments array
 *
 * Return: On success - 1
 *	   On error - Exit with segmentation fault
 */
int main(int argc, char **argv)
{
	char *name, *pwd;
	char *arr = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int name_len, ret1, ret2, ret3, ret4, ret5, ret6;

	if (argc != 3)
		segf();
	name = argv[1];
	pwd = argv[2];

	if (strlen(pwd) != 6)
		segf();
	name_len = strlen(name);

	ret1 = f1(name_len);
	if (*(arr + ret1) != pwd[0])
		segf();

	ret2 = f2(name, name_len);
	if (*(arr + ret2) != pwd[1])
		segf();

	
	ret3 = f3(name, name_len);

	if (*(arr + ret3) != pwd[2])
		segf();

	ret4 = f4(name, name_len);

	if (*(arr + ret4) != pwd[3])
		segf();
	ret5 = f5(name, name_len);
	
	if (*(arr + ret5) != pwd[4])
		segf();

	ret6 = f6(name[0]);
	if (*(arr + ret6) != pwd[5])
		segf();

	puts("Congrats");

	return(1);
}
