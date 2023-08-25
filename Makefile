# Makefile
#
# Written in 2016 by Maxime Schmitt <max.schmitt@unistra.fr>
#
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain
# worldwide. This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain
# Dedication along with this software. If not, see
# <http://creativecommons.org/publicdomain/zero/1.0/>.

CC = gcc
CCFLAGS = -Wall -std=c99 -Wextra

tp2: tp2.o
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ $<

%.o: %.c
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	@rm -f *.o tp2
