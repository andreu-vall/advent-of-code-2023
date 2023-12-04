# Advent of Code 2023

Fourth year doing [Advent of Code](https://adventofcode.com/2023), the journey of Competitive Programming and projects has been quite fun. I'm not sure if this year I'll stick with the 25 different programming languages challenges because it takes so much time, but at the very least I'll repeat the most relevant and fun Programming Languages from last year, and maybe try some new ones. I'll also rank the languages based on their usability and beauty.

Day Solution            | Language                         | Year | Score | Comment
------------------------|----------------------------------|------|-------|----------------------------------------------------
[01.js](src/01.js)      | [Javascript](#01-javascript)     | 1995 |   7   | Too permissive and weird, but it's ok
[02.java](src/02.java)  | [Java](#02-java)                 | 1995 |   7   | Useful as a language, but why the ; ?
[03.c](src/03.c)        | [C](#03-c)                       | 1972 |   5   | Doesn't have built-in essentials: classes and hashes
[04.sh](src/04.sh)      | [Bash](#04-bash)                 | 1989 |   6   | Useful for doing some simple things

Done: Javascript, Java, C, Bash
Relevant: SQL, Scala?, Perl?, Swift, Ruby, Julia, PHP..., R, Rust, Go, Kotlin, C#, Typescript, C++, Python (that makes 19)
New ones: ???


## 01. Javascript
```
Get-Content inputs/01.txt | node src/01.js
```

## 02. Java
```
Get-Content inputs/02.txt | java -ea src/02.java
```

## 03. C
```
gcc src/03.c
Get-Content inputs/03.txt | ./a.exe
```

## 04. Bash
```
wsl
cat inputs/04.txt | bash src/04.sh
```