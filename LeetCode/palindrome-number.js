const isPalindrome = (x) => {
  const xArr = x.toString();
  const xArrReverse = xArr.split("").reverse().join("");

  return xArr === xArrReverse ? true : false;
};
