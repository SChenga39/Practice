/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
  let hasBeenCalled = false;
  let res;

  return function (...args) {
    if (!hasBeenCalled) {
      res = fn(...args);
      hasBeenCalled = true;
      return res;
    } else {
      return undefined;
    }
  };
};
