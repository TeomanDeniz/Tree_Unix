/******************************************************************************\
# C - PATH_OVERWRITE                             #       Maximum Tension       #
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
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
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