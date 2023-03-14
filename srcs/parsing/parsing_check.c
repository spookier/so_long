#include "parsing.h"

static int is_valid_position(t_pall *all, char visited[all->vars.rows_map][all->vars.chars_map], int x, int y) 
{
    if (x >= 0 && x < all->vars.rows_map && y >= 0 && y < all->vars.chars_map && (visited[x][y] == '0' || visited[x][y] == 'C')) 
		return (1);
	if(visited[x][y] == 'E')
		return(1);
    return (0);
}

int flood_fill(t_pall *all, char visited[all->vars.rows_map][all->vars.chars_map], int x, int y) 
{
    if (visited[x][y] == 'E') 
	{
        return (1);
    }
    visited[x][y] = 'x';

    if (is_valid_position(all, visited, x-1, y) && flood_fill(all, visited, x-1, y)) {
        return 1;
    }
    if (is_valid_position(all, visited, x+1, y) && flood_fill(all, visited,  x+1, y)) {
        return 1;
    }
    if (is_valid_position(all, visited, x, y-1) && flood_fill(all, visited, x, y-1)) {
        return 1;
    }
    if (is_valid_position(all, visited, x, y+1) && flood_fill(all, visited, x, y+1)) {
        return 1;
    }

    return (0);
}

static void find_exit(t_pall *all)
{
	int i;
	int j;

	i =0;
	while(i < all->vars.rows_map)
	{
		j = 0;
		while(j < all->vars.chars_map)
		{
			if(all->vars.map[i][j] == 'E')
			{
				all->items.pos_start_x = j;
				all->items.pos_start_y = i;
			}
			j++;
		}
		i++;
	}
	return;
}

static void copy_map(t_pall *all, char visited[all->vars.rows_map][all->vars.chars_map])
{
	int i;
	int j;

	i = 0;
	while(i < all->vars.rows_map)
	{
		j = 0;
		while(j < all->vars.chars_map)
		{
			visited[i][j] = all->vars.map[i][j];
			j++;
		}
		i++;
	}
	return;
}

static int check_map_validity(t_pall *all)
{
    int i;
	int j;
	
	i = 0;
    while (i < all->vars.rows_map) 
	{
        j = 0;
        while (j < all->vars.chars_map) 
		{
            if (all->vars.map[i][j] == 'E')
				all->items.exit++;
            else if (all->vars.map[i][j] == 'C') 
               all->items.collectibles++;
            else if (all->vars.map[i][j] == 'P') 
				all->items.start++;
			else if (all->vars.map[i][j] != '0' && all->vars.map[i][j]  != '1') 
            {
                all->error = "Error\nInvalid character in map\n";
                return(1);
            }
            j++;
        }
        i++;
    }
	return(0);
}


static int init_items(t_pall *all)
{
	all->items.start = 0;
	all->items.exit = 0;
	all->items.collectibles = 0;

	if(check_map_validity(all) == 1)
		return(1);
	if (all->items.start != 1 || all->items.exit != 1 || all->items.collectibles < 1) 
	{
		all->error = "Error\nNot enough map components\n";
		return(1);
	}
	return(0);
}


static int check_rectangle(t_pall *all)
{
  	int expected_cols;
	int i;

    i = 0;
	expected_cols = all->vars.chars_map;
    while (i < all->vars.rows_map) 
	{
        if ((int)ft_strlen(all->vars.map[i]) != expected_cols) 
		{
			all->error = "Error\nMap is not rectangular\n";
            return (1);
        }
        expected_cols = ft_strlen(all->vars.map[i]);
        i++;
    }
    return 0;
}

static int check_walls_surround(t_pvars *v)
{
	int i;

	i = 0;
	while(v->map[0][i])
	{
		if(v->map[0][i] == '1')
			i++;
		else
			return(1);
	}
	i = 0;
	while(v->map[v->rows_map - 1][i])
	{
		if(v->map[v->rows_map - 1][i] == '1')
			i++;
		else
			return(1);
	}
	i = 0;
	while (i < v->rows_map)
	{
		if (v->map[i][0] == '1' && v->map[i][v->chars_map - 1] == '1')
			i++;
		else
			return (1);
	}
	return(0);
}


int init_check_map(t_pall *all)
{
	char visited[all->vars.rows_map][all->vars.chars_map];

	if(all->vars.rows_map < 3 || all->vars.chars_map < 2)
	{
		all->error = "Error\nInvalid map\n";
		return(1);
	}
	if(check_rectangle(all) == 1 || init_items(all) == 1)
		return(1);
	if(check_walls_surround(&all->vars) == 1)
	{
		all->error = "Error\nMap not surrounded by walls\n";
		return(1);
	}

	copy_map(all, visited);

	find_exit(all);

	if (flood_fill(all, visited, all->items.pos_start_x, all->items.pos_start_y))
        return(0);
    else
	{
		all->error = "Error\nPath not found\n";
		return(1);
	}

	printf("map checked\n");
	return(0);
}