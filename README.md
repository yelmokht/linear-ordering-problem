# Linear ordering problem
Implemention of iterative improvement algorithms for the linear ordering problem (LOP) for the course Heuristic Optimization (INFO-H413)

## Compilation

~~~
make lop
~~~


## Usage

```bash
Usage: ./lop [algorithms or help] [initial_solutions] [neighbourhoods] [improvements] [-i <instance_file>]

Algorithms or help:
  --ii
  --vnd
  --help

Initial solutions:
  --random (only with --ii)
  --cw

Neighbourhoods:
  --transpose (only with --ii)
  --exchange (only with --ii)
  --insert (only with --ii)
  --transpose-exchange-insert (only with --vnd)
  --transpose-insert-exchange (only with --vnd)

Improvements:
  --first
  --best (only with --ii)

```

##Statistics

```bash
make statistics
```
