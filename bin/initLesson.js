// node bin/initLesson.js DS1/Stack

const process = require("process");
const fs = require("fs");
const path = require("path");

const lessonPath = process.argv[2];

const lessonName = lessonPath.split("/")[1];

fs.mkdirSync(lessonPath, { recursive: true });

fs.promises.mkdir(path.join(lessonPath, "Problems"));

fs.promises.appendFile(path.join(lessonPath, `${lessonName}.h`), `#pragma once
#ifndef ${lessonName.toUpperCase()}_IMPLEMENTATION
#define ${lessonName.toUpperCase()}_IMPLEMENTATION

#endif
`);