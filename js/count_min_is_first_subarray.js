function count_min_is_first_subarray(nums) {
  Array.prototype.back = function () { return this[this.length - 1]; }
  var stack = [0];
  var count = 0;
  for (var i = 1; i < nums.length; ++i) {
    while (stack.length && nums[stack.back()] > nums[i]) {
      count += i - stack.back();
      stack.pop();
    }
    stack.push(i);
  }
  while (stack.length) {
    count += nums.length - stack.back();
    stack.pop();
  }
  return count;
}
console.log(count_min_is_first_subarray([1, 3, 5]));
console.log(count_min_is_first_subarray([1, 3, 2, 4]));
console.log(count_min_is_first_subarray([1, 3, 5, 4, 0, 2, 4]));
