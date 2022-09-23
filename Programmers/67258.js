const solution = (gems) => {
  const cnt = new Set(gems).size;
  const gemMap = new Map();
  let answer = [1, gems.length];
  gems.forEach((gem, idx) => {
    gemMap.delete(gem);
    gemMap.set(gem, idx);
    if (gemMap.size === cnt) {
      const cand = [gemMap.values().next().value + 1, idx + 1];
      answer = answer[1] - answer[0] > cand[1] - cand[0] ? cand : answer;
    }
  });
  return answer;
};
