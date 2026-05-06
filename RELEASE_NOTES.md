## v0.1.0 — Initial Release

The first release of `tally`, a minimal command-line line counter.

### What it does

Counts the number of lines in a file and prints the result:

```sh
$ tally file.txt
42
```

Exits with a non-zero status if no file is given or the file cannot be opened.

### Installation

Download the binary for your platform from the assets below, or build from
source — see the [README](README.md) for instructions.

### Notes

This is a foundation release. The tool is intentionally minimal — future
releases will add word counting (`-w`), character counting (`-c`), multiple
file support, and stdin fallback.
