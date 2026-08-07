# Tests

This project ships a small, dependency-free test suite for its calculator
math and dispatch logic.

## Running

From the repository root:

```
make test
```

This compiles `src/calc.c`, `src/input.c` and `src/logic.c` into objects,
links `tests/test_calc.c` against them, and runs the resulting binary. The
process exits non-zero if any assertion fails, so this target works well as
a check inside CI.

## What is covered

- `add`, `subtract`, `multiply`, `divide` basic correctness with positive,
  negative and decimal operands.
- `divide` returning `0` on a zero divisor instead of crashing.
- `calculate` dispatching each supported operator (`+`, `-`, `*`, `/`, `%`)
  and falling back to the documented `-1` sentinel for an unknown operator.

`src/main.c` is intentionally not linked, so the tests run without prompting
for interactive input.

## Notes

The test runner has no external dependencies. To add a new test, write a
`static void test_x(void)` function and call it from `main`, using the
`check(name, condition)` helper to record the result.
