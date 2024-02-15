/******************************************************************************\
# C - TREE                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/14 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2024/02/16 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "tree.h" /*
#typedef t_tree;
#   void recursive_tree(t_tree);
#*/
#include <stdio.h> /*
#    int printf(char *, ...);
#*/
#include <stdbool.h> /*
# define bool;
# define false;
# define true;
#*/
#include <dirent.h> /*
# struct DIR;
#    DIR *opendir(char *);
#    int closedir(DIR *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	check_argument(int argc, char **argv, t_tree *tree);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	tree(int argc, char **argv)
{
	bool	folders_splitted;
	t_tree	tree;

	printf(",\n");
	tree.path = ".";
	folders_splitted = false;
	tree.show_all_files = false;
	tree.folder_index = 0;
	tree.folders_splitted = &folders_splitted;
	check_argument(argc, argv, &tree);
	recursive_tree(tree);
}

static void
	check_argument(int argc, char **argv, t_tree *tree)
{
	DIR	*dir;

	if (argc >= 2)
		dir = opendir(argv[1]);
	if (argc >= 2 && !dir)
	{
		if ((argv[1][0] == '-' && argv[1][1] == 'a' && !argv[1][2]) || \
			(argv[1][0] == '-' && argv[1][1] == 'A' && !argv[1][2]))
			tree->show_all_files = true;
	}
	else if (argc >= 2)
	{
		tree->path = argv[1];
		closedir(dir);
	}
	if (argc >= 3)
	{
		if ((argv[2][0] == '-' && argv[2][1] == 'a' && !argv[2][2]) || \
			(argv[2][0] == '-' && argv[2][1] == 'A' && !argv[2][2]))
			tree->show_all_files = true;
	}
}
