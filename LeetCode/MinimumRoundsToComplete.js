/**
 * @param {number[]} tasks
 * @return {number}
 */

const getMin = (task) => {
  if (task < 2) return -1;
  if (task === 2 || task === 3) return 1;
  if (task === 4) return 2;

  let [before3, before2, before1, now] = [1, 1, 2, 5];
  while (now !== task + 1)
    [before3, before2, before1, now] = [
      before2,
      before1,
      Math.min(before3 + 1, before2 + 1),
      now + 1,
    ];

  return before1;
};

var minimumRounds = function (tasks) {
  const taskGroup = new Map();
  for (const task of tasks)
    if (taskGroup.get(task)) taskGroup.set(task, taskGroup.get(task) + 1);
    else taskGroup.set(task, 1);

  let answer = 0;
  for (const [task, taskCount] of taskGroup) {
    if (getMin(taskCount) === -1) return -1;
    else answer += getMin(taskCount);
  }

  return answer;
};
