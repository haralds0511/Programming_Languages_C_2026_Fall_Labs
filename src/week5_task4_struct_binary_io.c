// week5_task4_struct_binary_io.c   (BONUS)
// Name: _Haralds_  Surname: _Roskošs__  Student ID: __251RDC034_
//
// Task 4: Save and load a struct in binary format with fwrite()/fread()
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task4_struct_binary_io

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

int save_student_binary(const Student* s, const char* filename);
int load_student_binary(const char* filename, Student* out);
long file_size(const char* filename);

int main(void) {
  Student s1 = {0};  // zero-initialized so unused name bytes are not garbage on
                     // disk[cite: 9]
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  Student loaded = {0};
  const char* bin_file = "student.bin";
  const char* txt_file = "student.txt";

  printf("Saving student in binary format...\n");
  if (save_student_binary(&s1, bin_file) != 0) {
    fprintf(stderr, "Error saving binary file.\n");
    return EXIT_FAILURE;
  }

  // Save the same record as text for comparison
  FILE* txt_fp = fopen(txt_file, "w");
  if (txt_fp != NULL) {
    fprintf(txt_fp, "%s %d %.2f\n", s1.name, s1.age, s1.gpa);
    fclose(txt_fp);
  }

  printf("Loading student from binary file...\n");
  if (load_student_binary(bin_file, &loaded) != 0) {
    fprintf(stderr, "Error loading binary file.\n");
    return EXIT_FAILURE;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);
  printf("Text file size: %ld bytes\n", file_size(txt_file));
  printf("Binary file size: %ld bytes\n", file_size(bin_file));

  return EXIT_SUCCESS;
}

int save_student_binary(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    return -1;
  }
  if (fwrite(s, sizeof(Student), 1, fp) != 1) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

int load_student_binary(const char* filename, Student* out) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }
  if (fread(out, sizeof(Student), 1, fp) != 1) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

long file_size(const char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }
  if (fseek(fp, 0, SEEK_END) != 0) {
    fclose(fp);
    return -1;
  }
  long size = ftell(fp);
  fclose(fp);
  return size;
}