# Copyright (c) 2016, Codrin-Victor Poienaru <cvpoienaru@gmail.com>.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# This software is provided by the copyright holders and contributors "as is"
# and any express or implied warranties, including, but not limited to, the
# implied warranties of merchantability and fitness for a particular purpose are
# disclaimed. In no event shall the copyright holder or contributors be liable
# for any direct, indirect, incidental, special, exemplary, or consequential
# damages (including, but not limited to, procurement of substitute goods or
# services; loss of use, data, or profits; or business interruption) however
# caused and on any theory of liability, whether in contract, strict liability,
# or tort (including negligence or otherwise) arising in any way out of the use
# of this software, even if advised of the possibility of such damage.

# Library options
CDP_LIB_NAME = cdevpack
CDP_LIB_PREFIX = lib
CDP_LIB_EXTENSION = so
CDP_LIB_SRC = $(CDP_SRC)
CDP_LIB_OUT = $(CDP_LIB)/$(CDP_LIB_PREFIX)$(CDP_LIB_NAME).$(CDP_LIB_EXTENSION)

# Library source & object files
CDP_SOURCES = $(CDP_LIB_SRC)/logger/logger.c
CDP_OBJECTS = $(CDP_SOURCES:.c=.o)

# Compiler options
CC = gcc
CFLAGS = -Wall -O3 $(CDP_FLAGS)
LFLAGS =

all: $(CDP_SOURCES) $(CDP_LIB_OUT)

$(CDP_LIB_OUT): $(CDP_OBJECTS)
	$(CC) $^ -shared -o $@ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

.PHONY: clean
clean:
	find $(CDP_LIB_SRC) -iname *.o -delete
