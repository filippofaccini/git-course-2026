#include "demo.h"

#include <stdio.h>

void dataset_init(Dataset *ds) { ds->count = 0; }

Status dataset_add(Dataset *ds, int value) {
  if (ds->count >= DEMO_MAX_VALUES) {
    return STATUS_FULL;
  }

  ds->values[ds->count++] = value;
  return STATUS_OK;
}

void dataset_clear(Dataset *ds) { ds->count = 0; }

int dataset_sum(const Dataset *ds) {
  int sum = 0;

  for (size_t i = 0; i < ds->count; ++i) {
    sum += ds->values[i];
  }

  return sum;
}

double dataset_average(const Dataset *ds) {
  if (ds->count == 0) {
    return 0.0;
  }

  return (double)dataset_sum(ds) / (double)ds->count;
}

int point_distance_squared(Point a, Point b) {
  int dx = b.x - a.x;
  int dy = b.y - a.y;

  return dx * dx + dy * dy;
}

int clamp_int(int value, int min, int max) {
  if (value < min) {
    return min;
  }

  if (value > max) {
    return max;
  }

  return value;
}

int max_int(int a, int b) { return (a > b) ? a : b; }

int min_int(int a, int b) { return (a < b) ? a : b; }

void print_dataset(const Dataset *ds) {
  printf("Dataset (%zu values):\n", ds->count);

  for (size_t i = 0; i < ds->count; ++i) {
    printf("  [%zu] = %d\n", i, ds->values[i]);
  }
}

uint32_t checksum32(const uint8_t *buffer, size_t length) {
  uint32_t sum = 0;

  for (size_t i = 0; i < length; ++i) {
    sum += buffer[i];
  }

  return sum;
}

void fill_sequence(int *buffer, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    buffer[i] = (int)i;
  }
}

void reverse_sequence(int *buffer, size_t length) {
  for (size_t i = 0; i < length / 2; ++i) {
    int temp = buffer[i];
    buffer[i] = buffer[length - 1 - i];
    buffer[length - 1 - i] = temp;
  }
}
