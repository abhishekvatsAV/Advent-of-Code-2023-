const fs = require("fs");

fs.readFile("input.txt", "UTF-8", (err, data) => {
  let ans = 0;
  const allCards = data.split("\n").filter((n) => n);
  for (let i = 0; i < allCards.length; i++) {
    const cardDetails = allCards[i];
    const cardNum = parseInt(cardDetails.split(":")[0].split(" ")[1]);
    const wNums = cardDetails
      .split(":")[1]
      .split("|")[0]
      .split(" ")
      .map((n) => parseInt(n));
    const cNums = cardDetails
      .split(":")[1]
      .split("|")[1]
      .split(" ")
      .map((n) => parseInt(n));

    let cnt = 0;
    for (let i = 0; i < cNums.length; i++) {
      const idx = wNums.findIndex((x) => x === cNums[i]);
      if (idx !== -1) {
        cnt++;
      }
    }

    cnt--;
    if (cnt < 0) continue;
    const temp = Math.pow(2, cnt);
    ans += temp;
  }

  console.log("ans : ", ans);
});
