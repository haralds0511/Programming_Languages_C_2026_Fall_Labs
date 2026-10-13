// week5_task1_file_io.c
// Name: _Haralds_  Surname: _Roskošs__  Student ID: __251RDC034_
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char* argv[]) {
  FILE* fp = NULL;
  const char* filename = DEFAULT_FILENAME;
  char line[LINE_LEN];
  int line_count = 0;

  // Use command-line argument if provided[cite: 6]
  if (argc > 1) {
    filename = argv[1];
  }

  // 1. Print writing message and open file for writing[cite: 6]
  printf("Writing lines to %s...\n", filename);
  fp = fopen(filename, "w");

  // 2. Check that fp is not NULL[cite: 6]
  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  // 3. Write 2-3 lines of text using fprintf()[cite: 6]
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");

  // 4. Close the file[cite: 6]
  fclose(fp);

  // 5. Open the file again for reading[cite: 6]
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  // 6. Print reading contents and use fgets() in a loop[cite: 6]
  printf("Reading contents:\n");
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }

  // 7. Close the file[cite: 6]
  fclose(fp);

  // Print total lines read[cite: 6]
  printf("Lines read: %d\n", line_count);

  return EXIT_SUCCESS;
}