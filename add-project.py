import sys
from pathlib import Path
import os
import errno

"""
Make a directory with these included

|-- project
|   |-- bootloader
|   |-- docs
|   |-- drivers
|   |-- dsp
|   |-- hardware_design
|   |-- libs
|   |-- resources
|   |-- test
|   |-- Makefile
|   |-- project.cc

Run like python3 add-project.py ProjectName
"""

prj_name = sys.argv[1]

MAKEFILE_CONTENT = '# makefile for ' + prj_name + '\n' + \
    '\n' + \
    'TARGET = ' + prj_name + '\n' + \
    '\n' + \
    'include ../my-lib/makefile.inc' + '\n'

DRIVER_H = 'int driver();'

DRIVER_CC = '#include "driver.h"' + '\n' + \
    '\n' + \
    'int driver()' + '\n' + \
    '{' + '\n' + \
    '    return 7;' + '\n' + \
    '}' + '\n'

PROJECT_CPP_CONTENT = '#include <cstdio>' + '\n' + \
    '#include "drivers/driver.h"' + '\n' + \
    '\n' + \
    'int main()' + '\n' + \
    '{' + '\n' + \
    '    int var = driver();' + '\n' + \
    '    printf(\"Hello World %d \\n\", var);' + '\n' + \
    '    return 0;' + '\n' + \
    '}' + '\n'

try:
    os.makedirs(sys.argv[1], exist_ok=False)
    os.makedirs(os.path.join(prj_name, "bootloader"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "docs"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "drivers"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "dsp"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "hardware_design"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "libs"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "resources"), exist_ok=False)
    os.makedirs(os.path.join(prj_name, "test"), exist_ok=False)

    f = open(prj_name + "/Makefile", "w")
    f.write(MAKEFILE_CONTENT)
    f.close()

    f = open(prj_name + "/drivers/driver" + ".h", "w")
    f.write(DRIVER_H)
    f.close()

    f = open(prj_name + "/drivers/driver" + ".cc", "w")
    f.write(DRIVER_CC)
    f.close()

    f = open(prj_name + "/" + prj_name + ".cc", "w")
    f.write(PROJECT_CPP_CONTENT)
    f.close()

    print(prj_name + " was created because you are awesome.")
except FileExistsError as error:
    print(error)
    pass
except OSError as error:
    print(error)
    pass
