/******************************************************************************\
# C - RECURSIVE_TREE                             #       Maximum Tension       #
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
# define PATH_MAX
#typedef t_tree;
#   void path_overwrite(char [], char *, char *);
#*/
#include <stdio.h> /*
#    int printf(char *, ...);
#*/
#include <stdbool.h> /*
# define bool;
# define false;
# define true;
#*/
#include <errno.h> /*
#   void perror(char *);
#*/
#include <dirent.h> /*
# define S_ISDIR;
# struct DIR;
# struct dirent;
# dirent *readdir(DIR *);
#    DIR *opendir(char *);
#    int closedir(DIR *);
#*/
#include <sys/stat.h> /*
# define S_ISDIR;
# struct stat;
#    int stat(char *, struct stat *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void			directory_work(t_tree tree, char *new_path);
static bool			check_dot_in_dir(t_tree *tree);
static struct stat	loop_work(t_tree *tree, char new_path[PATH_MAX]);
static bool			check_if_last_folder(DIR *check_dir);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	recursive_tree(t_tree tree)
{
	struct stat		file_stat;
	char			new_path[PATH_MAX];

	tree.dir = opendir(tree.path);
	if (!tree.dir)
	{
		perror("opendir");
		return ;
	}
	tree.check_dir = opendir(tree.path);
	tree.entry = (readdir(tree.check_dir), readdir(tree.dir));
	while (!!tree.entry)
	{
		if (check_dot_in_dir(&tree))
			continue ;
		file_stat = loop_work(&tree, new_path);
		if ((tree.folder_index + 1) > 0)
			printf(TREE_DRAW_BRANCH);
		if (S_ISDIR(file_stat.st_mode))
			directory_work(tree, new_path);
		else
			printf(TREE_PRINT_FILE, tree.entry->d_name);
		tree.entry = readdir(tree.dir);
	}
	(closedir(tree.dir), closedir(tree.check_dir));
}

static void
	directory_work(t_tree tree, char *new_path)
{
	char			*old_path;
	register int	ecx;

	printf(TREE_PRINT_FOLDER, tree.entry->d_name);
	tree.folder_index++;
	old_path = tree.path;
	tree.path = new_path;
	recursive_tree(tree);
	tree.path = old_path;
	tree.folder_index--;
	ecx = -1;
	if (!*(tree.folders_splitted))
	{
		while (++ecx, (ecx <= tree.folder_index))
		{
			if (tree.next_folder_exist[ecx])
				printf(TREE_DRAW_LINE);
			else
				printf(TREE_DRAW_IDLE);
		}
		printf("\n");
		*(tree.folders_splitted) = true;
	}
}

static bool
	check_dot_in_dir(t_tree *tree)
{
	*(tree->folders_splitted) = false;
	if (((((tree->entry->d_name[0] == '.' && \
		tree->entry->d_name[1] == 0) || (tree->entry->d_name[0] == '.' && \
		tree->entry->d_name[1] == '.' && tree->entry->d_name[2] == 0))) || \
		(tree->entry->d_name[0] == '.' && !tree->show_all_files)))
	{
		tree->entry = (readdir(tree->check_dir), readdir(tree->dir));
		return (true);
	}
	return (false);
}

static struct stat
	loop_work(t_tree *tree, char new_path[PATH_MAX])
{
	register int	ecx;
	struct stat		file_stat;

	path_overwrite(new_path, tree->path, tree->entry->d_name);
	stat(new_path, &file_stat);
	tree->next_folder_exist[tree->folder_index] = \
		check_if_last_folder(tree->check_dir);
	ecx = -1;
	while (++ecx, (ecx < tree->folder_index))
	{
		if (tree->next_folder_exist[ecx])
			printf(TREE_DRAW_LINE);
		else
			printf(TREE_DRAW_IDLE);
	}
	return (file_stat);
}

static bool
	check_if_last_folder(DIR *check_dir)
{
	struct dirent	*entry;

	entry = readdir(check_dir);
	if (!entry)
		return (false);
	return (true);
}
