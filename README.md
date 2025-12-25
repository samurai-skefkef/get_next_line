*This project has been created as part of the 42 curriculum by soamraou*
# get_next_line
## Description

get_next_line is a C function that reads a line from a file descriptor, returning it each time the function is called. A line is defined as a sequence of characters ending with a newline character (\n) or the end of file (EOF).
This project helps grasping the meaning of a static variable, especially here that we used a static buffer rather than a simple variable. Also how to manage memory leaks.

## Instructions

This project does not include a Makefile.
To compile and use get_next_line, you must compile the source files manually.

Example compilation:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
!!! Make sure you included the get_next_line.h header in your main.c file. !!!

You can change the value of BUFFER_SIZE at compile time to test different behaviors:
```
-D BUFFER_SIZE=1
-D BUFFER_SIZE=42
-D BUFFER_SIZE=1000000
```
If BUFFER_SIZE was not defined at copilation time the default value is BUFFER_SIZE = 1

## Ressources

* 42 subject PDF

* Youtube

* Geeksforgeeks: https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

* Linux man pages

**ChatGPT was used for detecting a few memory leaks, understanding static variable behavior and optimizing lines for norminette check.**
  
## Algorithm and Data Structure Choices
**get_next_line:**

get_next_line is the main function of the project.
It reads from a given file descriptor and returns a single line each time it is called.


  * A static buffer (stach in this code) is used to store leftover data between calls

  * Data is read from the file descriptor in chunks of BUFFER_SIZE

  * Reading continues until a newline (\n) is found or EOF is reached

  * The line to return is extracted from the stash

  * Any remaining data after the newline is kept for the next call

  * The function returns NULL if there is nothing more to read or if an error occurs

  ### Buffer / Stash Handling

  * A dynamically allocated string (often called stash) is used to:

  * Append newly read data

  * Search for newline characters

  * Split the content into:

  * The line to return

  * The remaining content to keep for the next call

  **This design ensures:**

  * No loss of data between calls

  * Correct handling of lines larger than BUFFER_SIZE

  ### Bonus part:
  The bonus version allows reading from multiple file descriptors simultaneously.

  Each file descriptor has its own static stash, ensuring that reading from one file does not interfere with another. This was done by declaring a static list of "static stashes", each stash belongs to a fd.
  
