#include "main.h"

/**
* append_text_to_file - Appends a text to the end of a file.
* @filename: A pointer to the name of the file to be created.
* @text_content: A pointer to a string that will be written to the file.
*
* Return: If the function fails, it returns -1.
*         Otherwise, it returns 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int p, x, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

p = open(filename, O_WRONLY | O_APPEND);
x = write(p, text_content, len);

if (p == -1 || x == -1)
return (-1);

close(p);

return (1);
}
