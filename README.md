<h1>Simple Shell</h1>
<p>This is a basic UNIX command line interpreter, a simple shell, developed as part of a project. The shell supports basic functionality such as displaying a prompt, executing commands, handling errors, and more.</p>
  
<h2>Features</h2>
<ul>
  <li>Display a prompt and wait for the user to type a command.</li>
  <li>Commands are single words, and a command line always ends with a new line.</li>
  <li>Prompt is displayed again after each command execution.</li>
  <li>Handles errors and displays an error message if an executable cannot be found.</li>
  <li>Handles "end of file" condition (Ctrl+D).</li>
  <li>Extends functionality to handle command lines with arguments.</li>
  <li>Further extends functionality to handle the PATH.</li>
  <li>fork is not called if the command doesn't exist.</li>
</ul>

<h2>Usage</h2>
<p>To use the simple shell, follow these steps:</p>
<p>Compile the program: gcc -o simple_shell *.c</p>
<p>Run the shell: ./simple_shell</p>
<h2>Example</h2>
<p>$ ./simple_shell</p>
<p>$ ls</p>
<p>file1 file2 file3</p>
<p>$ echo Hello, World!</p>
<p>Hello, World!</p>
<p>$ exit</p> 
<p>$</p> 

<h2>Notes</h2>
<p>The shell does not implement built-ins or handle special characters.</p>
<p>The cursor cannot be moved, and commands with arguments are not supported.</p>
<p>The execve function is used as the core part of the shell, passing the environ variable.</p> 

