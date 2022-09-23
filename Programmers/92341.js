const getFee = (period, baseTime, baseFee, atomTime, atomFee) => {
  if (period.length % 2 === 1) period.push(1439);
  const timeSum = period.reduce((acc, cur, idx) => {
    if (idx % 2 === 0) acc -= cur;
    else acc += cur;
    return acc;
  }, 0);

  let fee = 0;
  if (timeSum < baseTime) fee = baseFee;
  else fee = baseFee + Math.ceil((timeSum - baseTime) / atomTime) * atomFee;

  return fee;
};

const solution = (fees, records) => {
  const [baseTime, baseFee, atomTime, atomFee] = fees;
  const carInOut = [];
  const carInOutTime = [];
  let maxIdx = -1;

  const carRecord = new Map();
  records.forEach((cur, idx, origin) => {
    const [time, carNumberStr, inOrOut] = cur.split(" ");
    const [timeHour, timeMinute] = time
      .split(":")
      .map((cur) => parseInt(cur, 10));
    const convertedTime = timeHour * 60 + timeMinute;

    if (carRecord.has(carNumberStr))
      carRecord.set(carNumberStr, [
        ...carRecord.get(carNumberStr),
        convertedTime,
      ]);
    else carRecord.set(carNumberStr, [convertedTime]);
  });

  const answer = [];
  for (let [carNum, period] of [...carRecord].sort())
    answer.push(getFee(period, baseTime, baseFee, atomTime, atomFee));

  return answer;
};
