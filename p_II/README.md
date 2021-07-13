## Our bison file 
| filename | Content |
| mini_l.y | Specifies the yacc command grammar file that defines the parsing rules, and calls the yylex subroutine created by the lex command to provide input. |
| mini_l.lex | Specifies the lex command specification file that defines the lexical analysis rules. |
| y.tab.h | A header file containing define statements for the tokens used by the parser |
| lex.yy.c | The C language source file that the lex command created for the lexical analyzer |







## The Yacc/Bison Input File

Yacc/Bison takes as input a context-free grammar specification and produces a C-language function that recognizes correct instances of the grammar. The input file for the Yacc/Bison utility is a Yacc/Bison grammar file. The Yacc/Bison grammar input file conventionally has a name ending in .y.

A Yacc/Bison grammar file has four main sections, shown here with the appropriate delimiters: 
```bison
    %{
    C declarations
    %}
    Yacc/Bison declarations
    %%
    Grammar rules
    %%
    Additional C code
```
### Some rules of input
* Comments enclosed in `/* ... */` may appear in any of the sections. The `%%`, `%{` and `%}` are punctuation that appears in every `Yacc`/`Bison` grammar file to separate the sections.
* The `C` declarations may define types and variables used in the actions. You can also use preprocessor commands to define macros used there, and use `\#include` to include header files that do any of these things.
* The `Yacc`/`Bison` declarations declare the names of the terminal and nonterminal symbols, and may also describe operator precedence and the data types of semantic values of various symbols.
* The grammar rules define how to construct each nonterminal symbol from its parts.
* The additional `C` code can contain any `C` code you want to use. Often the definition of the lexical analyzer `yylex` goes here, plus subroutines called by the actions in the grammar rules. In a simple program, all the rest of the program can go here. 
