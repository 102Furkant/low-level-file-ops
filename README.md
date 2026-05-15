# posix-file-io

A small low-level file writing utility written in C using POSIX system calls.

This project avoids high-level stdio functions such as `fopen()` and `fprintf()` and instead uses low-level Unix file APIs like:

- `open()`
- `write()`
- `close()`

## Current Program

### writer.c

Writes a user-provided string into a file.

### Compilation

```bash
gcc writer.c -o writer
```

### Usage

```bash
./writer output.txt "hello world"
```

Example:

```bash
./writer notes.txt "low level programming"
```

## Concepts Practiced

- File descriptors
- POSIX file operations
- Command-line arguments
- Error handling with `errno` and `perror`
- Low-level Linux/Unix programming

## Future Plans

Additional low-level file operation utilities may be added later.

## License

MIT License
