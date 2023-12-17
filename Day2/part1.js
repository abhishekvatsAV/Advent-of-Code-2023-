const fs = require("fs");

let ans = 0;

fs.readFile("input.txt", "utf-8", (err, data) => {
  const lines = data.split("\n").filter((n) => n);
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    const gameNum = line.split(": ")[0].split(" ")[1];
    const sets = line.split(": ")[1].split("; ");
    let flag = 1;

    for (let i = 0; i < sets.length; i++) {
      const set = sets[i].split(", ");
      for (let j = 0; j < set.length; j++) {
        const color = set[j].split(" ")[1];
        const count = set[j].split(" ")[0];

        if (color === "red") {
          if (count > 12) flag = 0;
        } else if (color === "blue") {
          if (count > 14) flag = 0;
        } else {
          if (count > 13) flag = 0;
        }
      }
    }

    if (flag === 1) {
      ans += parseInt(gameNum);
    }
  }
  console.log("ans : ", ans);
  
});
