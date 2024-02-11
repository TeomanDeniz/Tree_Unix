#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h> /*
# strcut stat;
#    int stat(char *, struct stat *);
#*/

#include <stdbool.h> /*
#typedef bool;
# define true;
# define false;
#*/
#ifdef __APPLE__ /* MACOS */
# include <sys/syslimits.h> /*
#  define PATH_MAX
#*/
#else
# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif /* PATH_MAX */
#endif /* __APPLE__ */

struct s_tree
{
	bool			next_folder_exist[PATH_MAX];
	bool			*folders_splitted;
	bool			show_all_files;
	char			*path;
	int				folder_index;
	struct dirent	*entry;
	DIR				*dir;
	DIR				*check_dir;
};

static void	directory_work(struct s_tree tree, char *new_path);

static bool
	at_the_last_folder(DIR *check_dir)
{
	struct dirent	*entry;

	entry = readdir(check_dir);
	if (!entry)
		return (false);
	return (true);
}

static void
	path_overwrite(char new_path[PATH_MAX], char *path, char *d_name)
{
	register int	index;
	register int	path_index;

	index = -1;
	path_index = -1;
	while (++index, ++path_index, path[index])
		new_path[path_index] = path[index];
	new_path[path_index] = '/';
	index = -1;
	while (++index, ++path_index, d_name[index])
		new_path[path_index] = d_name[index];
	new_path[path_index] = 0;
}

static struct stat
	loop_work(struct s_tree *tree, char new_path[PATH_MAX])
{
	register int	ecx;
	struct stat		file_stat;

	path_overwrite(new_path, tree->path, tree->entry->d_name);
	stat(new_path, &file_stat);
	ecx = -1;
	tree->next_folder_exist[tree->folder_index] = \
		at_the_last_folder(tree->check_dir);
	while (++ecx, (ecx < tree->folder_index))
	{
		if (tree->next_folder_exist[ecx])
			printf(":  ");
		else
			printf("   ");
	}
	return (file_stat);
}

static bool
	check_dot_dir(struct s_tree *tree)
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

void
	recursive_tree(struct s_tree tree)
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
		if (check_dot_dir(&tree))
			continue ;
		file_stat = loop_work(&tree, new_path);
		if ((tree.folder_index + 1) > 0)
			printf(":..");
		if (S_ISDIR(file_stat.st_mode))
			directory_work(tree, new_path);
		else
			printf("[%s]\n", tree.entry->d_name);
		tree.entry = readdir(tree.dir);
	}
	(closedir(tree.dir), closedir(tree.check_dir));
}

static void
	directory_work(struct s_tree tree, char *new_path)
{
	char			*old_path;
	register int	ecx;

	printf(",{%s}\n", tree.entry->d_name);
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
				printf("%s%s", ":", "  ");
			else
				printf("%s", "   ");
		}
		printf("\n");
		*(tree.folders_splitted) = true;
	}
}

static void
	check_argument(int argc, char **argv, struct s_tree *tree)
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

int
	main(int argc, char **argv)
{
	bool			folders_splitted;
	struct s_tree	tree;

	printf(",\n");
	tree.path = ".";
	folders_splitted = false;
	tree.show_all_files = false;
	tree.folder_index = 0;
	tree.folders_splitted = &folders_splitted;
	check_argument(argc, argv, &tree);
	recursive_tree(tree);
	return (0);
}

