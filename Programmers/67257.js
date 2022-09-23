function solution(expression) {
  const mathExp = ["*", "+", "-"];
  const priorityArr = [
    ["*", "+", "-"],
    ["*", "-", "+"],
    ["+", "*", "-"],
    ["+", "-", "*"],
    ["-", "*", "+"],
    ["-", "+", "*"],
  ];
  let maxVal = 0;
  for (const priority of priorityArr) {
    const expressionArr = expression.split(/(\D)/);
    for (const exp of priority) {
      while (expressionArr.includes(exp)) {
        const index = expressionArr.indexOf(exp);
        expressionArr.splice(
          index - 1,
          3,
          eval(expressionArr.slice(index - 1, index + 2).join(""))
        );
      }
    }
    maxVal = Math.max(maxVal, Math.abs(expressionArr[0]));
  }

  return maxVal;
}
