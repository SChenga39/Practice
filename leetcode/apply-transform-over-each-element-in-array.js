/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

// 1. 使用 for 循环
var map = function (arr, fn) {
  for (let i = 0; i < arr.length; ++i) {
    arr[i] = fn(arr[i], i);
  }
  return arr;
};

// 2. 使用 forEach
var map = function (arr, fn) {
  arr.forEach((element, index) => {
    arr[index] = fn(element, index);
  });

  return arr;
};

// 3. 使用 reduce
var map = function (arr, fn) {
  return arr.reduce((res, element, index) => {
    res[index] = fn(element, index);
    return res;
  }, []);
};
