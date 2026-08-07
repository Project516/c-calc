# c-calc
 
This is a basic C calculator!

It supports `+, -, *, /, %`.

A makefile has been provided, for convenience.

## Usage

Install GCC. On most Linux distributions this can be installed from your package manager. Windows? Use MSYS2. Mac? I heard brew is good.

Run `./run.sh` to build and run the project.

### Non interactive mode

You can pass in arguments from the command line. For example `./c-calc 1 + 1` returns `Result: 2.0000`.

### Tests

Run the test suite with `make test`. See `tests/README.md` for details on what is covered.
