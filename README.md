# posix-file-io

A small collection of low-level file I/O utilities written in C using POSIX system calls.

This repository focuses on practicing low-level Unix/Linux programming without using high-level stdio functions such as `fopen()`, `fread()`, or `fprintf()`.

Instead, the programs use direct POSIX system calls like:

- `open()`
- `read()`
- `write()`
- `close()`

---

## Programs

### writer.c

Writes a user-provided string into a file using low-level POSIX file operations.

#### Compilation

```bash
gcc writer.c -o writer
```

#### Usage

```bash
./writer output.txt "hello world"
```

Example:

```bash
./writer notes.txt "low level programming"
```

---

### mini_cat.c

A simple `cat`-like utility that reads a file in fixed-size chunks and writes its contents to stdout using `read()` and `write()`.

#### Compilation

```bash
gcc mini_cat.c -o mini_cat
```

#### Usage

```bash
./mini_cat file.txt
```

---

## Concepts Practiced

- File descriptors
- POSIX system calls
- Chunk-based file reading
- Low-level file operations
- Command-line arguments
- Error handling with `errno` and `perror`
- Unix/Linux systems programming
- Buffered vs unbuffered I/O concepts

---

## Goals

This repository is intended as a learning project for:

- low-level C programming
- systems programming
- Unix/Linux internals
- POSIX APIs

Future utilities and experiments may be added over time.

---

## License

MIT License
