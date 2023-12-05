# Advent of Code 2023

Fourth year doing [Advent of Code](https://adventofcode.com/2023), the journey of Competitive Programming and projects has been quite fun. I'm not sure if this year I'll stick with the 25 different programming languages challenges because it takes so much time, but at the very least I'll repeat the most relevant and fun Programming Languages from last year, and maybe try some new ones. I'll also rank the languages based on their usability and beauty.

Day Solution            | Language                         | Year | Score | Comment
------------------------|----------------------------------|------|-------|----------------------------------------------------
[01.js](src/01.js)      | [Javascript](#01-javascript)     | 1995 |   7   | Too permissive and weird, but it's ok
[02.java](src/02.java)  | [Java](#02-java)                 | 1995 |   7   | Useful as a language, but why the ; ?
[03.c](src/03.c)        | [C](#03-c)                       | 1972 |   5   | Doesn't have built-in essentials, and importing them is pain
[04.sh](src/04.sh)      | [Bash](#04-bash)                 | 1989 |   6   | Useful for doing some simple things but so slow

- Done: Javascript, Java, C, Bash
- Relevant: Scala?, Perl?, Swift, Ruby, Julia, PHP, Rust, Go, Kotlin, C#, C++, Python (that makes 19)
- Not general purpose programming languages: SQL, R?
- Domain Specificlanguages: HTML, VHDL, MATLAB, Mathematica, SQL, GameMakerLanguage
- Scripting Languages: AWK, Bash, Perl, Lisp, Power Shell, Ruby
- Typescript????
- New ones: Haskell, Prolog ???
- All years: https://github.com/andreu-vall/advent-of-code
- Our particular leaderboard: https://advent-of-code-leaderboard.herokuapp.com/


A scripting language or script language is a programming language that is used to manipulate, customize, and automate the facilities of an existing system. Scripting languages are usually interpreted at runtime rather than compiled.

A command language is a language for job control in computing. It is a domain-specific and interpreted language; common examples of a command language are shell or batch programming languages.

Bash is not a programming language, it is a command-line interpreter. Bash is a software replacement for the original Bourne shell.


## 00. System specs
- Microsoft Windows 10 Home 10.0.19045 N/A Build 19045
- Visual Studio Code 1.84.2
- GitHub Copilot v1.140.0 (included with GitHub Student Developer Pack, free for Universitat de Barcelona students)
- PowerShell 7.3.10 (C:\Program Files\PowerShell\7\pwsh.exe)
- git version 2.38.0.windows.1 (C:\Program Files\Git\cmd\git.exe)

## 01. Javascript
- C:\Program Files\nodejs\node.exe (node v16.14.2)
- Node's Javascript -> v8 9.4.146.24-node.20
- Chrome's Javascript -> V8 11.9.169.7 (for comparing purposes)
- npm global packages: C:\Users\$user\AppData\Roaming\npm\node_modules
```
Get-Content inputs/01.txt | node src/01.js
```

## 02. Java
- C:\Program Files\Common Files\Oracle\Java\javapath\java.exe (java 17.0.6 2023-01-17 LTS)
- Other Java versions in C:\Program Files\Java: jdk1.8.0_291, jdk-11.0.17 and jdk-17
- Also C:\Program Files\apache-maven-3.9.0 and C:\Gradle\gradle-7.6\bin
- "-ea" to use assertions
```
Get-Content inputs/02.txt | java -ea src/02.java
```

## 03. C
- C:\cygwin64\bin\gcc.exe (gcc version 11.2.0 (GCC))
- Put ; between instructions to only have 1 line for easy again execute
```
gcc src/03.c
Get-Content inputs/03.txt | ./a.exe
```

## 04. Bash
- C:\Windows\System32\wsl.exe
- Linux 5.10.102.1-microsoft-standard-WSL2
- Bash version 5.0.17(1)-release
```
wsl
cat inputs/04.txt | bash src/04.sh
```
