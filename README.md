# Unix Tree

This project is a Unix command-line tool written in C language, inspired by the functionality of the "tree" command in Windows. It provides a visual representation of the directory structure starting from the current directory or a specified directory.

## Usage

### Display Directory Tree

To display the directory tree of the current directory:

```bash
./tree
```

To display the directory tree of a specific folder:
```bash
./tree ./test_folder
./tree test_folder
```

### Display All Files

To include all files, including hidden files (such as .git, .DS_STORE), use the -a or -A option:

```bash
./tree -a
```

You can combine the options with directory paths:

```bash
./tree -a test_folder
./tree test_folder -a
```

## Example Output:

```
./tree
.
:.. LICENSE
:.. main.c
:.. Makefile
:.. path_overwrite.c
:.. path_overwrite.o
:.. recursive_tree.c
:.. recursive_tree.o
:.. tree
:.. tree.a
:.. tree.c
:..[tree.dSYM]
:  :..[Contents]
:     :.. Info.plist
:     :..[Resources]
:        :..[DWARF]
:           :.. tree
:
:.. tree.h
:.. tree.o
```
