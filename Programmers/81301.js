const solution = (s) => {
  const numToEn2 = ["ze", "on", "tw", "th", "fo", "fi", "si", "se", "ei", "ni"];
  const numEnLength = [4, 3, 3, 5, 4, 4, 3, 5, 4, 4];
  let resultString = "";
  const sArr = s.split("");
  sArr.forEach((cur, idx) => {
    if (isNaN(cur)) {
      const nowNumToEn2 = cur + s[idx + 1];
      numToEn2.forEach((cur, idx) => {
        if (cur === nowNumToEn2) {
          resultString += String(idx);
          idx += numEnLength[idx] - 1;
        }
      });
    } else resultString += cur;
  });

  const resultNumber = Number(resultString);
  return resultNumber;
};
