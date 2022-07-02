const numberOfSteps = (number) => {
  let i = 0;
  let num = number;

  while (num !== 0) {
    if (num % 2 === 0) num /= 2;
    else num -= 1;
    i++;
  }

  return i;
};
