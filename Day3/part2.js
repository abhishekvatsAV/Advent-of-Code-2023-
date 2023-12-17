const fs = require("fs");

const mp = new Map();

function check(str, idxi, idxj, number) {
  if (!str) return;
  for (let i = 0; i < str.length; i++) {
    if (str[i] === "*") {
      let key = `${idxi}-${idxj + i}`;
      if (mp.has(key)) {
        mp.get(key).push(number);
      } else {
        mp.set(key, [number]);
      }
    }
  }
}

fs.readFile("./input.txt", "utf-8", (err, data) => {
  const matrix = data.split("\n").filter((n) => n);
  const n = matrix.length;
  const m = matrix[0].length;
  let ans = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (matrix[i][j] === ".") continue;
      if (isNaN(Number(matrix[i][j]))) continue;
      let number = matrix[i][j];
      while (++j < m) {
        if (isNaN(matrix[i][j])) break;
        number += matrix[i][j];
      }

      const top = i === 0 ? "" : matrix[i - 1].substring(j - number.length - 1, j + 1 || j);
      const bottom = i === n - 1 ? "" : matrix[i + 1].substring(j - number.length - 1, j + 1 || j);
      const left = matrix[i][j - number.length - 1] || "";
      const right = matrix[i][j];

      const startj = j - number.length - 1;

      if (i > 0) {
        check(top, i - 1, startj > 0 ? startj : 0, parseInt(number));
      }

      if (i < n - 1) {
        check(bottom, i + 1, startj > 0 ? startj : 0, parseInt(number));
      }

      if (j > 0) {
        check(left, i, startj > 0 ? startj : 0, parseInt(number));
      }

      if (j < m - 1) {
        check(right, i, j, parseInt(number));
      }
    }
  }

  for (const [key, value] of mp) {
    let temp = 1;
    if (value.length === 2 || value.length === 4) {
      for (let i = 0; i < value.length; i++) {
        temp *= value[i];
      }
      ans += temp;
    }
  }

  console.log("ans : ", ans);
});
/*
    17 Dec 2023 at 4:46 PM

    {
      'i-j' : [num1, num2],
    }

*/
