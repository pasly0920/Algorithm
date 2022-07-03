const maximumWealth = (accounts) => {
  return accounts.reduce((acc, cur) => {
    const wealthSum = cur.reduce((tacc, tcur) => {
      return (tacc += tcur);
    }, 0);
    return acc > wealthSum ? acc : wealthSum;
  }, 0);
};
