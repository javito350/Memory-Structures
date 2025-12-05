![Vector art of 200 in hex, subtitle of course: Bare Metal in pale green and printer's black](https://raw.githubusercontent.com/allegheny-college-cmpsc-200-fall-2024/course-materials/media/images/CMPSC%20-%200xC8%20Banner.png)

# CMPSC 200: Memory Structures in C

| Date              |           |
|:------------------|:----------|
| 5 December 2024   | Assigned  |
| 11 December 2024  | Due       |
| Status            | [![Fundamentals](../../actions/workflows/main.yml/badge.svg?branch=main)](../../actions/workflows/main.yml) |
|                   | [![Hack](../../actions/workflows/main.yml/badge.svg?branch=hack)](../../actions/workflows/hack.yml)         |

## Introduction

This week, we explored the implications of several assembly-level assumptions carried forward to `C`, including memory locations and sizes. In addition, we learned about pointers, a feature of `C` similar to `indirect addressing`. All of these assumptions and features form around the concepts of `array`s and `struct`s, two memory structures that feature an interplay between the `stack` and the `heap`.

In this assignment, you'll create a `struct` from a list of numbers and explore some features of the data type. You're also tasked with removing a value and re-knitting a cohesive `linked list` (a sequential group of `struct`s) so that the list keeps its integrity.

### `tl;dr`

Your task is the following:

* create a `linked list` from a global array called `data`
  * this should use a `struct` with _one_ field (`value`) which also points to the next "node"
* the program should report the memory size and length of the `linked list`
* the program should allow us to remove any node from the `linked list` by value
  * in this example, we should remove any values that are _greater than or equal to_ an arbitrary
  * removal must be done by completing the function `remove_node`, and cannot be achieved by ignoring the values when creating the `linked list`

## Instructions

To recieve credit for this assignment:

* write:
  * the main loop of the program in [main.c](src/main.c) file in the `src` folder
* complete the documentation in [docs/report.md](docs/report.md)

> Note: You may work in pairs, but you should submit _your own assignment_.

## Debugging the program

* Assignments contain configuration meant to automate the `Pico Debug` button under the `Run and Debug` menu in VSCode.
* Recall that, to see your output,  you'll need to use the `Serial Monitor` to communicate with your test device setup.

## Assignment "Hack"

> Your instructor encourages you to talk this section over with the instructor themselves, a TL, or a friend!

So, two complications:

* in this `Hack`, you have to remove every node containing a number _below_ any arbitrary value, reconnecting the list into one continuous `linked list`, _and_
* reassemble the list as a _circular_ linked list
  * this means that the end of the list points to the node at the beginning, thus forming a "circle"
