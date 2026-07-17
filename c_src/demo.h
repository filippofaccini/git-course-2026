#ifndef DEMO_H
#define DEMO_H

#include <stddef.h>
#include <stdint.h>

#define DEMO_VERSION_MAJOR 1
#define DEMO_VERSION_MINOR 0
#define DEMO_MAX_NAME 64
#define DEMO_MAX_VALUES 128

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  char name[DEMO_MAX_NAME];
  int values[DEMO_MAX_VALUES];
  size_t count;
} Dataset;

typedef enum {
  STATUS_OK = 0,
  STATUS_ERROR = -1,
  STATUS_INVALID = -2,
  STATUS_FULL = -3
} Status;

void dataset_init(Dataset *ds);
Status dataset_add(Dataset *ds, int value);
void dataset_clear(Dataset *ds);

int dataset_sum(const Dataset *ds);
double dataset_average(const Dataset *ds);

int point_distance_squared(Point a, Point b);

int clamp_int(int value, int min, int max);
int max_int(int a, int b);
int min_int(int a, int b);

void print_dataset(const Dataset *ds);

uint32_t checksum32(const uint8_t *buffer, size_t length);

void fill_sequence(int *buffer, size_t length);
void reverse_sequence(int *buffer, size_t length);

int find_value(const int *buffer, size_t length, int target);

void swap_int(int *a, int *b);

void sort_simple(int *buffer, size_t length);

int is_sorted(const int *buffer, size_t length);

double compute_variance(const Dataset *ds);

double compute_stddev(const Dataset *ds);

void normalize_dataset(Dataset *ds);

void scale_dataset(Dataset *ds, int factor);

#endif
