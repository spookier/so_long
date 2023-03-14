#include "../incs/so_long.h"

int main(void)
{
	t_pall all;
	printf("----- MAIN @ PROGRAM START ------\n");
	
	// if (parsing_main(&all, argc, argv) == 1)
	// 	return(1);
	
	exec_main(&all);
	
	//free_map();

	return (0);
}