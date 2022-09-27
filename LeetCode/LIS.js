/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
  const minLen = [];

  for (let i = 0; i < nums.length; i++) {
    minLen[i] = 1;
    for (let j = 0; j < i; j++)
      if (nums[j] < nums[i]) minLen[i] = Math.max(minLen[i], minLen[j] + 1);
  }
  return Math.max(...minLen);
};
