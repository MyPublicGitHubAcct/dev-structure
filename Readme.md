# dev-structure

dev-env is used to test folder strutures, etc.

## Directory Structure

<img src='img/project-structure.png' width='170' alt="project-structure">

## Scripted New Project Generation

To start a new project, run the following command.

``` zsh
python3 add-project.py <ProjectName>
```

After the project has been generated, _cd_ into it and run _make_.

The executable files are in the 'bin' folder.

## Language Servers for Sublime Text

__LSP-clangd__ for C/C++ and __LSP-pyright__ for Python.

## Unit Tests

The [Criterion Framework](https://github.com/Snaipe/Criterion) is used for unit testing. The wiki can be found [here](https://criterion.readthedocs.io/en/master/intro.html).

Note that the path in _.zshrc_ will need to be updated each time this framework is updated, or a compilation error like the one shown below will happen.

```zsh
...
g++ -std=c++11 -Wall  -c tests/drivertest.cc -o build/tests/drivertest.o
tests/drivertest.cc:1:10: fatal error: 'criterion/criterion.h' file not found
#include <criterion/criterion.h>
         ^~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make: *** [build/tests/drivertest.o] Error 1
```

To update _.zshrc_, open it from $HOME and update __LIBRARY_PATH__ and __CPATH__. To do this in Sublime Text, use the command ```subl .zshrc```.

A change to the path in the files generated may also be needed.  In the example above, the #include was reduced to only include the header.

## GNU make manual

[the manual](https://www.gnu.org/software/make/manual/)

## TODO

- update script to make blink
- Redo repo
