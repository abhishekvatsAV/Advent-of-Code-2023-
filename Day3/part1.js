const fs = require("fs");

function isContainSpecial(str) {
  if (!str) return false;
  for (let i = 0; i < str.length; i++) {
    if (str[i] !== ".") return true;
  }
  return false;
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

      // console.log(number, top, right, bottom, left);

      if (isContainSpecial(top) || isContainSpecial(bottom) || isContainSpecial(left) || isContainSpecial(right)) {
        ans += parseInt(number);
      }
    }
  }
  console.log("ans : ", ans);
});
