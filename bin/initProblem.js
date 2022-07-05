const process = require("process"); // node bin/initProblem.js DS1/Stack P1
const path = require("path");
const fs = require('fs');

const dest = path.join(process.argv[2], "Problems");
const problemName = process.argv[3];

fs.mkdirSync(path.join(dest, problemName));

fs.promises.appendFile(path.join(dest, problemName, ".in"), "");
fs.promises.appendFile(path.join(dest, problemName, "main.cpp"), `#include <iostream>
#include "../../${process.argv[2].split("/")[1]}.h"

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(".in", "r", stdin);
    std::freopen(".out", "w", stdout);
}

main() {
    setup();

    
    
    return 0;
}`);