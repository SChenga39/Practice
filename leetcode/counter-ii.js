/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let count = init;
  function increment() {
    return ++count;
  }
  function reset() {
    return (count = init);
  }
  function decrement() {
    return --count;
  }
  return { increment, reset, decrement };
};

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let count = init;

  return {
    increment: () => ++count,
    decrement: () => --count,
    reset: () => (count = init),
  };
};
