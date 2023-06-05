#include "quick_sort.h"
#include "GenericTraits.h"

void switch_array(GenericTraits **array[], int i, int j) {
  GenericTraits ** tmp = (array)[i];
  (array)[i] = (array)[j];
  (array)[j] = tmp;
}

int partition(GenericTraits **array[], int low, int high){
  GenericTraits ** pivot = (array)[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++){
    if((*array[j])->cmp((array[j]), (pivot)) >= 0){
      i++;
      switch_array(array, i, j);
    }
  }
  switch_array(array, i + 1, high);
  return i + 1;
}

void new_quick_sort(GenericTraits **array[], int low, int high) {
  if (low < high) {
    int pivot = partition(array, low, high);
    new_quick_sort(array, low, pivot - 1);
    new_quick_sort(array, pivot + 1, high);
  }
}

void quick_sort(GenericTraits **array[], int n) {
  new_quick_sort(array, 0, n - 1);
}
