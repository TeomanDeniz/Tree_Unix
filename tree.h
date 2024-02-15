/******************************************************************************\
# H - TREE                                       #       Maximum Tension       #
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

#ifndef TREE_H
#	define TREE_H 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <stdbool.h> /*
#	typedef bool;
#	*/
#	include <dirent.h> /*
#	 struct dirent;
#	 struct DIR;
#	*/
#	ifdef __APPLE__ /* MACOS */
#		include <sys/syslimits.h> /*
#		 define PATH_MAX
#	*/
#	else
#		ifndef PATH_MAX
#			define PATH_MAX 1024
#		endif /* PATH_MAX */
#	endif /* __APPLE__ */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] OUTPUT SYNTAX [v] ************************** */
#	define TREE_DRAW_BRANCH ":.."
#	define TREE_PRINT_FILE " %s\n"
#	define TREE_PRINT_FOLDER "[%s]\n"
#	define TREE_DRAW_LINE ":  "
#	define TREE_DRAW_IDLE "   "
/* ************************* [^] OUTPUT SYNTAX [^] ************************** */

typedef struct s_tree
{
	bool			next_folder_exist[PATH_MAX];
	bool			*folders_splitted;
	bool			show_all_files;
	char			*path;
	int				folder_index;
	struct dirent	*entry;
	DIR				*dir;
	DIR				*check_dir;
}	t_tree;

/* *************************** [v] FUNCTIONS [v] **************************** */
extern void	recursive_tree(t_tree tree);
extern void	path_overwrite(char new_path[PATH_MAX], char *path, char *d_name);
/* *************************** [^] FUNCTIONS [^] **************************** */

#endif /* TREE_H */