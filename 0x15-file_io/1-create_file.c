#include "main.h"

/**
 * create_file - Creates a file.
 *
 * @filename: The name of the file to create.
 * @text_content: The text to write to the file.
 *
 * Return: On success, 1. On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
int fd, len = 0, bytes_written;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len])
len++;
}

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (len > 0)
{
bytes_written = write(fd, text_content, len);
if (bytes_written != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
