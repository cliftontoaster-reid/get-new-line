# Get new line

This project has to export a function, named get_next_line

The issue comes with the static variable that has to act as a buffer.

Here is an idea how it should work:

- 1st call
  - The function reads `BUFFER_SIZE` bytes from the file descriptor and stores them in a static buffer.
  -
