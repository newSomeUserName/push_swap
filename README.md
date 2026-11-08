_This project has been created as part of the 42 curriculum by jlucotte & tgerman._

# push_swap

> Sort data on a stack, with a limited set of instructions, using the lowest
> possible number of actions.

## Description

`push_swap` is a program that receives a list of integers as arguments and
prints, on the standard output, the **shortest list of instructions** it can
find that sorts those integers.

The program works with **two stacks**, named `a` and `b`:

- at the start, `a` holds all the numbers (the first argument is on top) and
  `b` is empty;
- at the end, `a` must be sorted in ascending order (smallest on top) and `b`
  must be empty.

The goal of the project is to learn about:

- **sorting algorithms** and their **complexity** (Big-O notation);
- choosing an algorithm based on the input (size, how sorted it already is);
- data structures (here a **doubly linked list** used as a stack);
- strict input validation and memory management (no leaks, no crash).

### Instructions available on the stacks

| Instruction | Effect                                                                 |
| ----------- | ---------------------------------------------------------------------- |
| `sa`        | swap the first 2 elements on top of `a` (nothing if fewer than 2)      |
| `sb`        | swap the first 2 elements on top of `b` (nothing if fewer than 2)      |
| `ss`        | `sa` and `sb` at the same time                                         |
| `pa`        | take the top of `b` and put it on top of `a` (nothing if `b` is empty) |
| `pb`        | take the top of `a` and put it on top of `b` (nothing if `a` is empty) |
| `ra`        | rotate `a` up: the first element becomes the last                      |
| `rb`        | rotate `b` up: the first element becomes the last                      |
| `rr`        | `ra` and `rb` at the same time                                         |
| `rra`       | reverse rotate `a`: the last element becomes the first                 |
| `rrb`       | reverse rotate `b`: the last element becomes the first                 |
| `rrr`       | `rra` and `rrb` at the same time                                       |

Example with `./push_swap 2 1 3 6 5 8`:

```
               a (top first)   b (top first)
init           2 1 3 6 5 8     (empty)
sa             1 2 3 6 5 8     (empty)
pb pb pb       6 5 8           3 2 1
rr (ra + rb)   5 8 6           2 1 3
```

### Rules of the program

- Arguments are integers (`int`), given as separate arguments or in one
  string (`./push_swap "3 2 1"`).
- With **no argument**, the program prints nothing and gives the prompt back.
- On **any error**, the program prints `Error` followed by `\n` on the
  **standard error**. Errors are:
  - an argument that is not an integer (`./push_swap 1 two 3`);
  - a number bigger than `INT_MAX` or smaller than `INT_MIN`;
  - a **duplicate** (`./push_swap 1 2 1`).
- Instructions are printed one per line, separated by `\n` only.
- If the list is already sorted, the program prints nothing.
- Global variables are forbidden; the project follows the 42 Norm.

### Strategies

The program contains several sorting strategies, of different complexity. The
strategy can be chosen with a flag; by default the program chooses by itself
(adaptive mode). All the strategies are explained in detail in the
[Sorting algorithms](#sorting-algorithms) section below.

| Flag         | Strategy                                       | Complexity |
| ------------ | ---------------------------------------------- | ---------- |
| `--simple`   | selection by minimum extraction                | O(n²)      |
| `--medium`   | chunk sort                                     | O(n√n)     |
| `--complex`  | radix sort (binary, LSD)                       | O(n log n) |
| `--adaptive` | chooses one of the above from the **disorder** | depends    |
| `--bench`    | prints statistics on the standard error        | —          |

`--bench` prints (on `stderr`, so it does not break the output read by the
checker): the disorder of the input, the strategy used and its complexity,
the total number of instructions and the count of each instruction.

### Files

| File             | Content                                                        |
| ---------------- | -------------------------------------------------------------- |
| `push_swap.c`    | `main()` and argument parsing                                  |
| `push_swap.h`    | `t_stack` structure and all prototypes                         |
| `list_utils.c`   | node creation, counting, moving to the head / last node        |
| `list_swap.c`    | `sa`, `sb`, `ss`                                               |
| `list_push.c`    | `pa`, `pb`                                                     |
| `list_r.c`       | `ra`, `rb`, `rr`                                               |
| `list_rr.c`      | `rra`, `rrb`, `rrr`                                            |
| `algo_utils.c`   | helpers shared by the algorithms (`is_sorted`, `find_min_pos`) |
| `algo_simple.c`  | O(n²) strategy                                                 |
| `algo_complex.c` | O(n log n) strategy                                            |
| `libft/`         | my libft                                                       |
| `ft_printf/`     | my ft_printf                                                   |

### Data structure

Each stack is a **doubly linked list**:

```c
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
```

The head of the list is the **top** of the stack. With `prev` and `next`, the
rotations (`ra`, `rra`) only change a few pointers and do not copy any data.

## Instructions

### Compilation

```sh
make        # builds libft, ft_printf, then push_swap
make clean  # removes the object files
make fclean # removes the object files and the binaries / libraries
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```sh
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
./push_swap --complex 5 4 3 2 1
./push_swap --bench 5 4 3 2 1
```

### Testing

Count the instructions:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Check the result with the checker given by 42 (`checker_Mac` / `checker_linux`).
It prints `OK` if the instructions sort the stack, `KO` otherwise:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

Random inputs (`shuf` on Linux, `gshuf` with coreutils on macOS):

```sh
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_Mac $ARG
```

Error cases to test:

```sh
./push_swap 1 2 two        # Error
./push_swap 1 2 2          # Error (duplicate)
./push_swap 2147483648     # Error (overflow)
./push_swap ""             # Error
./push_swap                # nothing
./push_swap 1 2 3          # nothing (already sorted)
```

Memory leaks:

```sh
valgrind --leak-check=full ./push_swap 3 2 1   # Linux
leaks -atExit -- ./push_swap 3 2 1             # macOS
```

## Sorting algorithms

### Complexity in a few words

The **complexity** of an algorithm tells how the amount of work grows when the
input grows. Here, the work we count is the **number of instructions printed**.

| Notation   | n = 100 | n = 500 | Example                        |
| ---------- | ------- | ------- | ------------------------------ |
| O(n)       | 100     | 500     | reading the list once          |
| O(n log n) | ~664    | ~4 483  | merge sort, quicksort, radix   |
| O(n√n)     | 1 000   | ~11 180 | chunk sort                     |
| O(n²)      | 10 000  | 250 000 | selection sort, insertion sort |

These are orders of magnitude, not exact counts: the constants are ignored.

### Step 0: normalise the values (index compression)

Before sorting, each value can be replaced by its **rank** in the sorted list:

```
values:  42  -7  1000  3
ranks:    2   0     3  1
```

The order is the same, but the numbers are now `0` to `n - 1`. This makes
chunk sort and radix sort much simpler (no negative numbers, no gaps), and
"is this element in the first 20 %?" becomes a simple comparison.

### Measuring the disorder

The **disorder** is the proportion of pairs that are in the wrong order (an
**inversion** is a pair `i < j` with `a[i] > a[j]`):

```
disorder = number of inversions / (n × (n − 1) / 2)
```

- `0` → already sorted;
- `1` → sorted in reverse order;
- about `0.5` → random list.

Counting it with two loops is O(n²) comparisons, but comparisons are free
here: only printed instructions are counted.

### Small inputs (2, 3, 5 numbers)

For very small inputs, special cases are better than any general algorithm.

- **2 numbers:** `sa` if they are not in order (max 1 instruction).
- **3 numbers:** there are only 6 possible orders, each one has a fixed
  answer of **at most 2 instructions**:

  | Order (top first) | Instructions |
  | ----------------- | ------------ |
  | 1 2 3             | —            |
  | 2 1 3             | `sa`         |
  | 3 2 1             | `sa` `rra`   |
  | 3 1 2             | `ra`         |
  | 1 3 2             | `sa` `ra`    |
  | 2 3 1             | `rra`        |

- **4–5 numbers:** push the 1 or 2 smallest to `b` (bring each one to the top
  with the shortest rotation), sort the 3 left in `a`, then `pa` back. A
  5-number input is sorted in **12 instructions or fewer**.

### Simple strategy, O(n²): selection by minimum extraction

This is the strategy in `algo_simple.c`. It is a
[selection sort](https://en.wikipedia.org/wiki/Selection_sort) adapted to
stacks:

1. find the position of the smallest value in `a` (`find_min_pos`);
2. bring it to the top with the **shortest rotation**: `ra` if it is in the
   first half, `rra` if it is in the second half (`bring_to_top`);
3. `pb` it to `b`;
4. repeat until `a` is empty: `b` now holds the values from biggest (top) to
   smallest;
5. `pa` everything back into `a`.

```
a: 3 1 2      find min (1, pos 1) → ra → a: 1 2 3 → pb → a: 2 3     b: 1
a: 2 3        min on top          → pb              → a: 3       b: 2 1
a: 3          min on top          → pb              → a:         b: 3 2 1
pa pa pa                                            → a: 1 2 3
```

**Cost:** each extraction needs up to `n / 2` rotations, for `n` elements:
about `n² / 4` rotations + `2n` pushes. Very good for small inputs, too slow
for 100 or 500 numbers.

Other O(n²) ideas: [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
(insert each element at its place in `b`), and
[bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) with `sa` + `ra`.

### Medium strategy, O(n√n): chunk sort

The idea: do not look for the exact minimum each time, look for **any element
of the current range** (a "chunk"). It is close to a
[bucket sort](https://en.wikipedia.org/wiki/Bucket_sort).

1. normalise the values to ranks `0 … n − 1`;
2. split the ranks into about **√n chunks** (for 100 numbers: ~5–8 chunks,
   for 500: ~11–15; the best size is found by testing);
3. **push phase:** while `a` is not empty, rotate `a` until the top belongs to
   the current chunk, then `pb`. If the element is in the lower half of the
   chunk, also do `rb`, so that `b` keeps a "valley" shape (big values in the
   middle, small at both ends). Go to the next chunk when the current one is
   empty;
4. **push-back phase:** while `b` is not empty, find the **biggest** value in
   `b`, bring it to the top with the shortest rotation (`rb` or `rrb`), then
   `pa`. `a` is built from the biggest to the smallest, so it ends sorted.

**Cost:** each chunk needs about `n` rotations to collect, and there are √n
chunks → about `n√n` instructions. In practice about 1 000–1 500 for 100
numbers and 8 000–12 000 for 500.

### Complex strategy, O(n log n): radix sort (binary, LSD)

[Radix sort](https://en.wikipedia.org/wiki/Radix_sort) sorts the numbers
**bit by bit**, starting from the least significant bit (LSD). It needs the
ranks `0 … n − 1` (no negative numbers).

For each bit `i`, from bit 0 to the highest bit of `n − 1`:

1. look at each of the `n` elements of `a` once:
   - bit `i` is `0` → `pb`;
   - bit `i` is `1` → `ra`;
2. `pa` everything back from `b`.

After the pass on bit `i`, the elements are sorted on their `i + 1` lowest
bits. After the last bit, `a` is sorted.

```
a: 2 (10)  0 (00)  3 (11)  1 (01)

bit 0:  2 → pb   0 → pb   3 → ra   1 → ra    a: 3 1      b: 0 2
        pa pa                                a: 2 0 3 1
bit 1:  2 → ra   0 → pb   3 → ra   1 → pb    a: 2 3      b: 1 0
        pa pa                                a: 0 1 2 3  sorted
```

**Cost:** `⌈log₂ n⌉` passes, each one `n` instructions + the pushes back:
about `n × log₂ n` to `2n × log₂ n`. For 100 numbers (7 bits): ~1 100
instructions; for 500 numbers (9 bits): ~6 800 instructions. It is simple,
stable and always works, but it does not use the order already present in the
input.

Other O(n log n) options:

- **Quicksort on two stacks:** choose a pivot (the median rank), push the
  half below the pivot to `b`, then sort each half recursively. Using two
  pivots (thirds) reduces the number of instructions.
- **Merge sort on two stacks:** split into runs, merge runs between `a` and
  `b`.

### A popular optimisation: the "Turk" / cost-based algorithm

Not one of the required strategies, but widely used to get the best scores:

1. `pb` all elements except 3, sort the 3 left in `a`;
2. for each element of `b`, compute the **cost** to put it at its place in
   `a` (rotations in `a` + rotations in `b`, using `rr` / `rrr` when both
   stacks rotate in the same direction);
3. move the **cheapest** element, repeat until `b` is empty;
4. rotate `a` until the minimum is on top.

It gives about 550–700 instructions for 100 numbers and 5 000–5 500 for 500.
Its comparisons are O(n²), but comparisons are not counted, only instructions.

A related trick: compute the
[longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)
(LIS) of `a`, keep it in `a`, and only push the other elements to `b`.

### Adaptive strategy

The adaptive mode measures the disorder first, then uses the strategy that
fits best:

| Disorder             | Strategy                                   |
| -------------------- | ------------------------------------------ |
| `0`                  | nothing to do                              |
| `n ≤ 5`              | small-input special cases                  |
| low (`< 0.2`)        | simple / near-linear: few elements to move |
| medium (`0.2 – 0.5`) | chunk sort, O(n√n)                         |
| high (`≥ 0.5`)       | complex strategy, O(n log n)               |

The thresholds above are the ones given by the subject; check them against
the current PDF.

### Benchmarks

Number of instructions expected for random inputs (the evaluation gives more
points for fewer instructions):

| Input size | Pass     | Good    | Excellent |
| ---------- | -------- | ------- | --------- |
| 100        | < 2 000  | < 1 500 | < 700     |
| 500        | < 12 000 | < 8 000 | < 5 500   |

To fill with my own results (`--bench`, average on 100 random inputs):

| Input size | `--simple` | `--medium` | `--complex` | `--adaptive` |
| ---------- | ---------- | ---------- | ----------- | ------------ |
| 3          |            |            |             |              |
| 5          |            |            |             |              |
| 100        |            |            |             |              |
| 500        |            |            |             |              |

## Bonus: checker

`checker` takes the same arguments as `push_swap`, then reads instructions on
the standard input (one per line), runs them on the stacks, and prints:

- `OK` if `a` is sorted and `b` is empty;
- `KO` otherwise;
- `Error` (on `stderr`) for invalid arguments or an unknown instruction.

```sh
./push_swap 3 2 1 | ./checker 3 2 1     # OK
printf "sa\n" | ./checker 3 2 1        # KO
```

## Resources

### Sorting algorithms and complexity

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) — overview and comparison table of the common algorithms.
- [Wikipedia — Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — complexity of the common sorting algorithms on one page.
- [Wikipedia — Selection sort](https://en.wikipedia.org/wiki/Selection_sort) — base of the simple strategy.
- [Wikipedia — Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
- [Wikipedia — Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort)
- [Wikipedia — Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) — idea behind chunk sort.
- [Wikipedia — Radix sort](https://en.wikipedia.org/wiki/Radix_sort) — base of the complex strategy (LSD version).
- [Wikipedia — Quicksort](https://en.wikipedia.org/wiki/Quicksort)
- [Wikipedia — Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [Wikipedia — Inversion (discrete mathematics)](<https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)>) — how the disorder is measured.
- [Wikipedia — Longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting) — animated sorting algorithms, step by step.
- [Toptal — Sorting Algorithms Animations](https://www.toptal.com/developers/sorting-algorithms) — compares algorithms on random, nearly sorted and reversed inputs (useful for the adaptive strategy).
- _Introduction to Algorithms_ (Cormen, Leiserson, Rivest, Stein) — chapters on sorting and linear-time sorting (radix sort).

### Data structures

- [Wikipedia — Stack (abstract data type)](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>)
- [Wikipedia — Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)

### push_swap articles

- [Jamie Dawson — Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — small cases and chunk-based approach.
- [A. Yigit Ogun — Push Swap (Turk algorithm)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — cost-based algorithm.

### C functions and tools

- [man 3 strtol / atoi (man7.org)](https://man7.org/linux/man-pages/man3/strtol.3.html) — converting strings to numbers, overflow detection.
- [man 2 write (man7.org)](https://man7.org/linux/man-pages/man2/write.2.html)
- [man 3 malloc / free (man7.org)](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [GNU make manual](https://www.gnu.org/software/make/manual/make.html)
- [42 Norminette](https://github.com/42School/norminette)
- [Valgrind — Quick Start](https://valgrind.org/docs/manual/quick-start.html)

### Testers and visualisers

- [push_swap_visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer) — shows the two stacks move instruction by instruction.
- [Push-Swap-Tester (gemartin99)](https://github.com/gemartin99/Push-Swap-Tester) — random tests, error cases and instruction counts.

### Use of AI

AI (Claude) was used to:

- summarise and explain the subject;
- explain the sorting algorithms and their complexity;
- gather the documentation links listed above;
- generate the skeleton of this README.

AI was **not** used to write the source code of the project.
