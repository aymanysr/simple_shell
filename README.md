Simple Shell
This is a basic UNIX command line interpreter, a simple shell, developed as part of a project. The shell supports basic functionality such as displaying a prompt, executing commands, handling errors, and more.

Features

Display a prompt and wait for the user to type a command.
Commands are single words, and a command line always ends with a new line.
Prompt is displayed again after each command execution.
Handles errors and displays an error message if an executable cannot be found.
Handles "end of file" condition (Ctrl+D).
Extends functionality to handle command lines with arguments.
Further extends functionality to handle the PATH.
fork is not called if the command doesn't exist.

Usage
To use the simple shell, follow these steps:

Compile the program: gcc -o simple_shell *.c
Run the shell: ./simple_shell
Example
bash
Copy code
$ ./simple_shell
$ ls
file1 file2 file3
$ echo Hello, World!
Hello, World!
$ exit
$
Notes
The shell does not implement built-ins or handle special characters.
The cursor cannot be moved, and commands with arguments are not supported.
The execve function is used as the core part of the shell, passing the environ variable.
