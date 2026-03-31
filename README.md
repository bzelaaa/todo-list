# To-Do List App

A command-line to-do list application written in C++.

## About
I built this project to learn how to manage data in C++ using structs
and vectors, and how to save and load data using files. Tasks persist
between sessions so nothing gets lost when you close the program.

## Features
- Add tasks with descriptions
- Mark tasks as complete
- Delete tasks
- Saves tasks to a file automatically when you quit
- Loads your tasks back when you reopen the program

## How to Run

### Requirements
- g++ compiler (GCC)

### Compile
g++ todo.cpp -o todo

### Run
./todo

## What I Learned
- Structs — creating custom data types
- Vectors — dynamic lists that grow and shrink
- Functions — splitting code into focused, reusable chunks
- File I/O — reading and writing data to files with fstream
- cin vs getline — handling different types of user input

## Future Plans
- Add due dates to tasks
- Sort tasks by complet