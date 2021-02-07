# Sort Detective
The goal of this lab is to use a program which allows you to measure
the behavior of 7 different sorting algorithm implementations.
It runs the selected sort and displays
total number of comparisons,
total data movements, and
total execution time in milliseconds.
You must apply your understanding of the general properties of the algorithms
(and in some cases of the code used to implement them)
to determine which algorithm is associated with each button.

A secondary objective of this lab is for you to gain experience writing a concise,
but complete analysis of a system.

## Game Plan
As you alerady know,
if you double the size of the data set that you give to a quadratic algorithm,
it will do four times the work.
In contrast, an `O(n log n)` algorithm will do a bit more than twice as much.
A linear algorithm will do only twice as much work.
Also recall the characteristics of the input data set can affect the expected
performance of many of our sorting algorithms.
For example, some algorithms perform differently when the data sets is nearly
sorted, perfectly sorted, or very large or small.
Before you begin the lab,
you should review the expected performance of the algorithms on various data sets.

The sorting algorithms under study this week include (in alphabetical order):

- Bubble Sort,
- Heap Sort,
- Insertion Sort,
- Merge Sort,
- Quick Sort,
- Selection Sort, and
- Shell Sort.

| **Note** |
| :--------: |
| Read all of the following before beginning |

## Steps

### 1. Download sort program
Download `sort-lab.jar` found in this directory.
It is an executable GUI program, so don't run this program
by ssh'ing into the Mesa server.

You need to download this program and run it locally on a computer
with Java installed.

Make sure you can run this program and play with it a bit.

Notice that the button names do not give any indication which sort
they will execute.
Notice also, that if you create a small list,
then that list is shown to you in the console window.
In the unlikely event that a sort fails (oops!),
a message will appear there as well.



### 2. Make a plan
Devise a plan which will enable you to match an algorithm to a button name.

It may make sense to try to divide the sorts into initial groups and
then to work on each group separately.
Divide and conquer: it works for algorithms and it can work here, too.

### 3. Execute your plan
Execute your plan, taking careful notes as you go.

The SortLab does not store results from previous runs,
so it is up to you to record results as you go.

## 4. Document results
Describe the results of your experiment in a summary document.
Begin with a two column table listing each button by name and
the sort that goes with it.

**Ensure you justify your results!!**

Simply listing which buttons perform which sorts is not enough to
earn credit.

**Collecting data**

The program will provide the following data, as an example:

| Length (N) | Ordering | Sort  | Comparisons | Movements | Sort time(msec) |
| ---        |  ---     | ----  | ----------- | --------- | --------------- |
|32 | random | alpha | 496 | 687 | 0 |

**Writing Notes**

There is no coding in this lab.
Expect a significant portion of the lab grade will be determined by
the quality of the writing of the report.
This includes the completeness of the report,
the clarity (and grammar) of the writing, and general presentation.

Some of the sorts are very difficult to distinguish.
A carefully outlined experiment may compensate for an error in these cases
if the writing makes it clear that your conclusions/guesses are substantiated by the data.

Finally, remember that your report needn't detail every experiment you ran.
Provide sufficient information to justify your conclusions.
It is possible to write a very short report that is completely correct
if your experiments are well chosen.

**Reports are not graded on length**, 
rather they are graded on **quality & correctness**. 
In fact, an extremely long report is an excellent indication you
probably don’t know what you are doing.
Plus you open yourself up to more opportunities to lose points due to mistakes.
After you learn the matching,
you might consider whether there was a shorter way to arrive at your conclusion.

## Turnitin
Don't forget to commit your documents and notes when you are done.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit -m 'finish sort lab'`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/7Ju2oAxQsMHLuZTE6).

