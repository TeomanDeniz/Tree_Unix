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
```
.
:..[.git]
:  :.. config
:  :.. description
:  :.. HEAD
:  :..[hooks]
:  :  :.. applypatch-msg.sample
:  :  :.. commit-msg.sample
:  :  :.. fsmonitor-watchman.sample
:  :  :.. post-update.sample
:  :  :.. pre-applypatch.sample
:  :  :.. pre-commit.sample
:  :  :.. pre-merge-commit.sample
:  :  :.. pre-push.sample
:  :  :.. pre-rebase.sample
:  :  :.. pre-receive.sample
:  :  :.. prepare-commit-msg.sample
:  :  :.. update.sample
:  :
:  :.. index
:  :..[info]
:  :  :.. exclude
:  :
:  :..[logs]
:  :  :.. HEAD
:  :  :..[refs]
:  :     :..[heads]
:  :     :  :.. main
:  :     :
:  :     :..[remotes]
:  :        :..[origin]
:  :           :.. HEAD
:  :
:  :..[objects]
:  :  :..[19]
:  :  :  :.. 0e20f699268b886048a1f38406c8075f756887
:  :  :
:  :  :..[50]
:  :  :  :.. 08ddfcf53c02e82d7eee2e57c38e5672ef89f6
:  :  :
:  :  :..[6e]
:  :  :  :.. fe821b3e0ce42c41dc79cc3904769512fa2a61
:  :  :
:  :  :..[76]
:  :  :  :.. fb25c9e4ca990d3361801dfbc86520273f9c12
:  :  :
:  :  :..[79]
:  :  :  :.. 97a09412ad291ae9e6a0ffea586e7445961133
:  :  :
:  :  :..[ea]
:  :  :  :.. 3d270a7580832ac9b6d674c5575ca3ae853779
:  :  :
:  :  :..[fb]
:  :  :  :.. 77738811439a8d8d529bb693b7ee0abfc2fbb0
:  :  :
:  :  :..[info]
:  :  :
:  :  :..[pack]
:  :     :.. pack-326d33b51e7d0acd97b6b436117a4bbd05967c18.idx
:  :     :.. pack-326d33b51e7d0acd97b6b436117a4bbd05967c18.pack
:  :
:  :.. packed-refs
:  :..[refs]
:     :..[heads]
:     :  :.. main
:     :
:     :..[remotes]
:     :  :..[origin]
:     :     :.. HEAD
:     :
:     :..[tags]
:
:..[asd]
:
:.. Another test file
```
