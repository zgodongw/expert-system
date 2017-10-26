# Expert-System
How to do simple logic... Or not so simple

# What It Is
This is an expert system for propositional calculus.

This program implements a backward-chaining inference engine. Rules and facts will be given
as a text file

A fact can be any uppercase alphabetical character.

The program accepts one parameter, which is the input file. It will contain a list
of rules, then a list of initial facts, then a list of queries.
For each of these queries, the program , given the facts and rules given, tells
if the query is true, false.

By default, all facts are false, and can only be made true by the initial facts statement,
or by application of a rule.
A fact can only be undetermined if the ruleset is ambiguous,
for example if I say "A is true, also if A then B or C", then B and C are undetermined.

# Features
Here’s a list of the features the engine to supports.

• "AND" conditions. For example, "If A and B and [...] then X"

• "OR" conditions. For example, "If C or D then Z"

• "XOR" conditions. For example, "If A xor E then V". Remember that this
means "exclusive OR". It is only true if one and only one of the operands is true.

• Negation. For example, "If A and not B then Y"

• Multiple rules can have the same fact as a conclusion

• "AND" in conclusions. For example, "If A then B and C"

• Parentheses in expressions. Interpreted in much the same way as an arithmetic
expression.

• An interactive colorful UI.

# How to install

git clone https://github.com/zgodongw/expert-system.git

cd ./expert-system && make re

# Run the program

with make [1 - 9] to run given test cases.

or ./system

and insert rules.
