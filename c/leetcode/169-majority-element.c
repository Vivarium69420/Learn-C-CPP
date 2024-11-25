/* Using Moore majority vote algorithm */
int majorityElement(int *arr, int n) {
  int res, candidate = -1, count = 0;

  // Find the candidate
  for (int i = 0; i < n; i++) {
    if (count == 0) {
      candidate = arr[i];
      count = 1;
    } else if (arr[i] == candidate)
      count++;
    else
      count--;
  }

  // Validate the candidate
  count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == candidate)
      count++;
  }

  // Check if the candidate is a possible majority element
  if (count > n / 2)
    return candidate;
  else
    return -1;

  return res;
}

int main(void) {
  int res;
  int nums[] = {3, 2, 3};
  int n = sizeof(nums) / sizeof(nums[0]);

  res = majorityElement(nums, n);
  return 1;
}
