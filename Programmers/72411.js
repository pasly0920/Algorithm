const getCombinations = (arr, selectNumber) => {
  const results = [];
  if (selectNumber === 1) return arr.map((el) => [el]);
  // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1);
    // 해당하는 fixed를 제외한 나머지 뒤
    const combinations = getCombinations(rest, selectNumber - 1);
    // 나머지에 대해서 조합을 구한다.
    const attached = combinations.map((el) => [fixed, ...el]);
    //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    results.push(...attached);
    // 배열 spread syntax 로 모두다 push
  });

  return results; // 결과 담긴 results return
};

const solution = (orders, course) => {
  let result = [];
  course.forEach((cur, idx, origin) => {
    const allPermutation = [];
    const tempArr = [];
    orders.forEach((curArr) => {
      tempArr.push(
        getCombinations(curArr.split(""), cur)
          .map((cur) => cur.sort().join(""))
          .forEach((now) => allPermutation.push(now))
      );
    });
    allPermutation.sort();

    const resSec = allPermutation.reduce((acc, cur) => {
      acc.set(cur, (acc.get(cur) | 0) + 1);
      return acc;
    }, new Map());

    const resSecArray = [...resSec];
    resSecArray.sort((a, b) => b[1] - a[1]);

    if (resSecArray.length === 0) return;

    const maxVal = resSecArray[0][1];
    if (maxVal < 2) return;
    const maxArray = resSecArray.reduce((acc, cur) => {
      if (cur[1] === maxVal) acc.push(cur[0]);
      return acc;
    }, []);
    result = [...result, ...maxArray];
  });
  result.sort();
  return result;
};
