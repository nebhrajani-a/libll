# libll
## Description

`libll` is a linked list library (API) for C. It provides creation, node addition/deletion, printing, searching, sorting, and destruction of a linked list.


## Prerequisites

To use `libll`, you should have the latest version of `gcc` or equivalent C compiler.

## Installation

To install `libll` using `gcc`, the recommended way is to use a shared library. First `cd` into the directory where you want to install. Then:
```
$ gcc -c -fpic /src/libll.c
$ gcc -shared -o libll.so libll.o
```

> Alternatively, you can use the `ldconfig` utility.

### Runtime libraries

If you haven't used `ldconfig`, you'll need to tell the linker explicitly where to look for `libll` at runtime using the `-L` option, like so:
```
$ gcc -L /your/path -o program.c -lll
```


## Documentation

The documentation for `libll` is available in PDF form in the `/docs` directory. 

---

## Contact

Feel free to submit any ideas, questions, or problems by reporting an issue. Alternatively, you can reach out to me at <aditya.v.nebhrajani@gmail.com>.
