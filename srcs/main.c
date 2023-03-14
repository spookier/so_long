#include "../incs/so_long.h"

int main(int argc, char **argv)
{
	t_pall all;
	printf("----- MAIN @ PROGRAM START ------\n");
	printf("----- starting parsing ------\n");
	
	if (parsing_main(&all, argc, argv) == 1)
		return(1);

	printf("----- starting drawing ------\n");
	
	exec_main(&all);
	
	//free_map();

	return (0);
}