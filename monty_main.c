/*
 * File: monty_main.c
 * Auth: Nnaemeka Nwodo
 */

#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * main - the entry point for monty interpreter
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
  FILE *ptr_script_file = NULL;
  int exit_code = EXIT_SUCCESS;

  if (argc != 2)
    return (usage_error());
  ptr_script_file = fopen(argv[1], "r");
  if (ptr_script_file == NULL)
    return (f_open_error(argv[1]));
  exit_code = run_monty(ptr_script_file);
  fclose(ptr_script_file);
  return (exit_code);
}
