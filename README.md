# tally
![tally logo](tally.svg) <br>
[![CI](https://github.com/GenericRikka/tally/actions/workflows/ci.yml/badge.svg?cache=1)](https://github.com/GenericRikka/tally/actions/workflows/ci.yml)
[![Latest Release](https://img.shields.io/github/v/release/GenericRikka/tally?cache=1)](https://github.com/GenericRikka/tally/releases/latest)
[![License](https://img.shields.io/github/license/GenericRikka/tally?cache=1)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux%20%7C%20windows%20%7C%20freebsd-blue)](https://github.com/GenericRikka/tally/releases/latest)


`tally` is a minimal command-line tool that counts lines in a file.

```
$ tally README.md
42
```

It is intentionally small. The goal is to be a learning project — both for
the people contributing to it and for anyone reading the source.

---

## Building

### Prerequisites

| Platform | What you need |
|---|---|
| **Windows** | [MSYS2](https://www.msys2.org/) (provides GCC, CMake, Ninja) |
| **Linux** | `gcc`, `cmake`, `ninja-build` via your package manager |
| **FreeBSD** | `devel/cmake`, `devel/ninja` from ports; base `cc` is fine |

### Windows (MSYS2)

1. Install [MSYS2](https://www.msys2.org/) and open the **MINGW64** shell.
2. Install the build tools (one-time):
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
   ```
3. Clone and build:
   ```bash
   git clone https://github.com/GenericRikka/tally.git
   cd tally
   cmake -B build -G Ninja
   cmake --build build
   ./build/tally.exe README.md
   ```

### Linux / BSD

```bash
git clone https://github.com/GenericRikka/tally.git
cd tally
cmake -B build -G Ninja
cmake --build build
./build/tally README.md
```

---

## Usage

```
tally <file>
```

Prints the number of lines in `<file>` and exits.  
Exits with a non-zero status if the file cannot be opened.

---

## Running the tests

```bash
bash tests/run_tests.sh ./build/tally        # Linux / BSD
bash tests/run_tests.sh ./build/tally.exe    # Windows (MSYS2)
```

---

## Contributing

Contributions are very welcome — see [CONTRIBUTING.md](CONTRIBUTING.md) for
everything you need to know, including how to format your commits and open a PR.
