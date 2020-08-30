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

You may need to add this path to the `$LD_LIBRARY_PATH` variable:
```
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/your/path
```
Add this line to your `~/.bashrc` if you want the variable definition to be permanent across sessions.
```
$ echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/your/path/' >> ~/.bashrc
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

## License

### MIT License
Copyright (c) 2020 Aditya Nebhrajani

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contact

Feel free to submit any ideas, questions, or problems by reporting an issue. Alternatively, you can reach out to me at <aditya.v.nebhrajani@gmail.com>.
