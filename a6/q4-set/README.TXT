Set I/O Command Guide:
======================

SYNTAX:
------

<set id> - An integer between 0 and 1, which specifies a Set

<number> - A single integer number

<list of numbers> - A list of integer numbers

<capacity> - A single integer number


COMMANDS:
--------

n <set id> <capacity>
Calls set_create with the specified Set and capacity

d <set id>
Calls set_destroy with the specified Set

a <set id> <number>
Calls set_add on the specified Set with the <number>

A <set id> <list of numbers> end
Adds each number in a list of numbers into a set in any order

m <set id> <number>
Calls set_is_member on the specified Set with the <number>

r <set id> <number>
Removes the <number> from the specified Set with the set_remove function

l <set id>
Calls set_length on the specified Set

u <set id> <set id>
Calls set_union with the two specified Sets

i <set id> <set id>
Calls set_intersect with the two specified sets

s <set id> <set id>
Calls set_is_subset with the two specified sets

e <set id> <set id>
Calls set_difference with the two specified sets

p <set id>
Prints the specified set

q
quits the program
