# My Process
Some terminology needs to be determined. Cells will refer to the smaller squares that contain a number when solved for. The cells are organized into 9 groups of 9 that are 3-by-3 squares; I'll be calling these, "3x3 group" or just "group". Often times a function will focus on a specific cell and check other cells relative to that cell. And due to the need to use the word "cell" so often, I'll need a separate word to differentiate the focus cell from other cells when describing functions. I'll call the cell that is the focus of the function, the "focal cell".

I need to decide how to organize my data. The first thing that comes to mind is using an array to save known cells (where each element is an unsigned integer 1 through 9 corresponding to the number that belongs in the cell) and an array of unsigned integers to save possible answers using bitpacking (101 means 1 and 3 are possible). Cell column and rows will be numbered 1 through 9. And individual cells will be indexed as one through 81. The 9 3x3 groups will be referenced by one of three group columns and one of three group rows.

If I'm organizing data this way, I'm going to need functions to convert an index to a row & column and a row & column to an index. It may also be a good idea to have functions that convert a row & column into a 3x3 group and index to 3x3 group.

After all of the conversion functions have been written, the functions to actually solve the puzzles must be created. I'll start with the operations that I believe to be simpler to describe with logical operations. The first two being a process of elimination in each row and column on the board by checking for known or given numbers in the column or row. Eventually I may choose to combine these functions, but for simplicity of organization, I'm going to write them out as separate functions first (they should essentially be the same function with a few words replaced). Then the more complex operations, such as the case wherein a number is only possible in a particular group in one of its rows. In that case, all other cells in that row (outside of that group) will have that number eliminated as a possibility.

-------

I'm going to change my approach a bit. I want to start off with as simple an implementation as possible. Meaning, data structures and algorithms that are fairly easy to follow.

Converting between indexes, row/column pairs, and groups, etc. was just too tedious.

The 'board' data structure will be a 2D array of 'cell' structures. Each 'cell' structure will have some properties. For example, one property will be the boolean value for whether or not the cell's true value has been solved or given. Another one of the properties of each 'cell structure' will be a set of possible values (if its true value hasn't been found yet).

# Program Flow Pseudocode
```
record all possible answers for each cell
while unsolved
  eliminate possibilities according to known values
  if there is a group where a number can only exist in one of the columns or rows, then
    remove that number as a possibility for every cell outside of the group and in the same row/column
  if there is a column, row, or group where a number can only exist in one of it's cells, then
    write that number as the answer for that cell
```
