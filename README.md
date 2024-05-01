# Linear ordering problem
Implementation of various SLS algorithms for the linear ordering problem (LOP). This project was undertaken as part of the course Heuristic Optimization (INFO-H413).

## Compilation

To compile the project, simply run:

```bash
make lop
```

## Usage

```bash
Usage: ./lop [options]
Options:
  -a, --algorithm [options]
      - ii
      - vnd
      - ils
      - ma

  -i, --initial-solution [options]
      - random (only for ii, ils, ma)
      - cw (only for ii, vnd)
      - bi (only for ils, ma)

  -p, --pivoting [options]
      - first (only for ii, vnd)
      - best (only for ii)

  -n, --neighborhood [options]
      - transpose (only for ii)
      - exchange (only for ii)
      - insert (only for ii)
      - transpose-exchange-insert (only for vnd)
      - transpose-insert-exchange (only for vnd)

  -ls, --local-search [options]
      - insert (only for ils and ma)

  -pb, --perturbation [options]
      - exchange (only for ils)

  -r, --recombination [options]
      - cx (only for ma)
      - dpx (only for ma)
      - ob (only for ma)
      - op (only for ma)
      - ox (only for ma)
      - pmx (only for ma)
      - po (only for ma)
      - rank (only for ma)

  -m, --mutation [options]
      - exchange (only for ma)
      - insert (only for ma)
      - inversion (only for ma)
      - scramble (only for ma)
      - swap (only for ma)

  -s, --selection [options]
      - rank (only for ma)
      - roulette (only for ma)
      - tournament (only for ma)
      - uniform (only for ma)

  -f, --file [instance file]

  --help [Display this help message]

```

Example:

```bash
./lop -a ma -i random -ls insert -r cx -m exchange -s rank -f ./instances/N-tiw56r72_150
```

## Implementation exercise 1

To run the first implementation exercise, you can use this command:

```bash
make ie1
```

The results would be in ./statistics/ie1/

## Implementation exercise 2

To run the first implementation exercise, you can use this command:

```bash
make ie2
```

The results would be in ./statistics/ie2/