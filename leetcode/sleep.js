/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
  await new Promise((result) => setTimeout(result, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
