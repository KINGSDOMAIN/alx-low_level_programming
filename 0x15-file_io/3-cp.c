#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates a buffer of 1024 bytes.
 * @file: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *create_buffer(char *file)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", file);
        exit(99);
    }

    return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    int c;

    c = close(fd);

    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 97 if the argument count is incorrect.
 * Exits with code 98 if the source file does not exist or cannot be read.
 * Exits with code 99 if the destination file cannot be created or written to.
 * Exits with code 100 if either the source or destination file cannot be closed.
 */
int main(int argc, char *argv[])
{
    int from, to, s, x;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer(argv[2]);
    from = open(argv[1], O_RDONLY);
    s = read(from, buffer, 1024);
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        if (from == -1 || s == -1)
        {
            dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        x = write(to, buffer, s);
        if (to == -1 || x == -1)
        {
            dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        s = read(from, buffer, 1024);
        to = open(argv[2], O_WRONLY | O_APPEND);

    } while (s > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (0);
}
