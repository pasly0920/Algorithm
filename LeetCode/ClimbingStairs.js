const climbStairs = (n) => {
  let [before2, before1, now] = [1, 2, 2];
  let nowStep;

  if (n === 1) return 1;
  else if (n === 2) return 2;

  while (now !== n) {
    nowStep = before2 + before1;
    [before2, before1] = [before1, nowStep];
    now++;
  }
  return before1;
};
