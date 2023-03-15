#include "../incs/so_long.h"

int main(int argc, char **argv)
{
	t_pall all;
	printf("----- MAIN @ PROGRAM START ------\n");
	printf("----- starting parsing ------\n");
	
	if (parsing_main(&all, argc, argv) == 1)
		return(1);

	exec_main(&all);

	//free this shit
	//free_map();

	return (0);
}	 