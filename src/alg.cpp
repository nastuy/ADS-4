// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  while (left < len) {
    if (left == 0 || arr[left] != arr[left - 1]) {
      int right = len - 1;
      while (right > left && arr[left] + arr[right] > value) {
        right--;
      }
      while (right > left) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
          int current_right_val = arr[right];
          int right_count = 1;
          right--;
          while (right > left && arr[right] == current_right_val) {
            right_count++;
            right--;
          }
          count += right_count;
        } else if (sum < value) {
          right = left;
        } else {
          right--;
        }
      }
    }
    left++;
  }
  return count;
}
int binarySearch(int* arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target >= arr[i]) {
      int left = i + 1;
      int right = len - 1;
      while (left <= right && arr[right] > target) {
        right--;
      }
      if (left <= right) {
        int pos = binarySearch(arr, left, right, target);
        if (pos != -1) {
          count++;
          int j = pos + 1;
          while (j <= right && arr[j] == target) {
            count++;
            j++;
          }
        }
      }
    }
  }
  return count;
}
