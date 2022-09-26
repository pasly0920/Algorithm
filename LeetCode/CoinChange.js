/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
  coins.sort((a, b) => a - b);
  const coinMap = [...new Set(coins)];

  const minAmount = [0];
  coinMap.forEach((cur) => (minAmount[cur] = 1));

  let now = 1;
  while (true) {
    if (now > amount) break;
    if (!minAmount[now]) {
      now++;
      continue;
    }
    coinMap.forEach((cur) => {
      if (!minAmount[now + cur]) minAmount[now + cur] = minAmount[now] + 1;
      else
        minAmount[now + cur] = Math.min(
          minAmount[now + cur],
          minAmount[now] + 1
        );
    });
    now++;
  }

  if (minAmount[amount] === undefined) return -1;
  return minAmount[amount];
};
