// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int end = len - 1;
  while (end > 0) {
    if (arr[end] > value) {
      end--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = end; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int binarySearch(int* arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      while (mid > left && arr[mid - 1] == target) mid--;
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int pos = binarySearch(arr, i + 1, len - 1, target);
    if (pos != -1) {
      count++;
      while (pos + 1 < len && arr[pos] == arr[pos + 1]) {
        count++;
        pos++;
      }
    }
  }
  return count;
}
