# push_swap

A C implementation of the 42 `push_swap` project. The program receives a list
of integers and prints a sequence of stack operations that sorts the values in
ascending order using two stacks and a restricted instruction set.

## How It Works

The program starts with all values in stack **A** and an empty stack **B**. It
must sort stack A while using only the allowed operations. Every operation is
printed to standard output, one per line.

The implementation:

- Validates and parses arguments passed as separate values or a single quoted
  string.
- Rejects duplicates and values outside the signed 32-bit integer range.
- Assigns normalized indexes to values before sorting.
- Uses specialized algorithms for small stacks.
- Uses an indexed range strategy for larger stacks.
- Cleans up allocated stacks and parsing data before exiting.

## Allowed Operations

| Operation | Effect |
| --- | --- |
| `sa` / `sb` | Swap the first two values of stack A or B |
| `ss` | Apply `sa` and `sb` together |
| `pa` | Push the top value from B to A |
| `pb` | Push the top value from A to B |
| `ra` / `rb` | Rotate a stack upward |
| `rr` | Apply `ra` and `rb` together |
| `rra` / `rrb` | Reverse-rotate a stack |
| `rrr` | Apply `rra` and `rrb` together |

## Requirements

- GCC or another C compiler
- GNU Make
- A Unix-like environment

The project is compiled with:

```text
gcc -Wall -Wextra -Werror
```

The repository includes a local `libft` dependency, which is built
automatically by the root Makefile.

## Build

From the repository root:

```bash
make
```

This creates the `push_swap` executable and the local `libft/libft.a` archive.

Available Make targets:

```bash
make          # Build push_swap and libft
make clean    # Remove object files
make fclean   # Remove object files, push_swap, and libft/libft.a
make re       # Rebuild everything
```

## Usage

Pass numbers as separate arguments:

```bash
./push_swap 2 1 3 6 5 8
```

Or pass them as one quoted argument:

```bash
./push_swap "2 1 3 6 5 8"
```

The program prints the operations needed to sort the input. An already sorted
sequence produces no output.

### Checking the Result

The standard workflow uses the 42 `checker` program to apply the generated
operations and verify that the final stack is sorted:

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker $ARG
```

Expected result:

```text
OK
```

`checker` is not included in this repository, so provide it separately when
using this validation command.

## Input Validation

The program prints `Error` and exits without sorting when the input contains:

- A non-numeric token
- An invalid sign or malformed number
- A duplicate value
- A value smaller than `INT_MIN`
- A value larger than `INT_MAX`

Examples:

```bash
./push_swap 1 2 2
# Error

./push_swap 2147483648
# Error

./push_swap 1 hello 3
# Error
```

Running the program without arguments exits silently:

```bash
./push_swap
```

## Sorting Strategy

- **2 values:** swap when necessary.
- **3 values:** use a minimal combination of swap, rotate, and reverse-rotate
  operations.
- **4 and 5 values:** move the smallest values to stack B, sort the remaining
  values, and push them back to A.
- **More than 5 values:** normalize values to indexes, move values through B in
  ranges, then rebuild A from the highest indexes downward.

For large inputs, the range size is adapted to the stack size to balance the
number of pushes and rotations.

## Project Structure

```text
.
├── includes/
│   └── push_swap.h             # Shared types and function declarations
├── instructions/
│   ├── push.c                  # pa and pb
│   ├── rotate.c                # ra, rb, and rr
│   ├── rrotate.c               # rra, rrb, and rrr
│   └── swap.c                  # sa, sb, and ss
├── libft/                      # Local support library
├── sort/
│   ├── big_sort.c              # Sorting strategy for larger inputs
│   ├── index.c                 # Value indexing
│   ├── short_sort.c            # Sorting for small stacks
│   └── sorting_utils.c         # Sorting helpers
├── src/
│   ├── main.c                  # Argument handling and program entry point
│   ├── parse_utils.c           # Input validation
│   └── stack_op.c              # Stack management
├── Makefile
└── README.md
```

## Project Scope

This project practices linked-list data structures, argument parsing, sorting
strategies, operation minimization, and memory management under the 42 C coding
constraints. It does not modify the input values directly; all sorting is
performed through the permitted stack operations.
