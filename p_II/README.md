## Our bison file's guts:
| **filename** |                                                                       **Content**                                                                      |
|:------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------:|
|  `mini_l.y`  | Specifies the yacc command grammar file that defines the parsing rules,<br>and calls the yylex subroutine created by the lex command to provide input. |
| `mini_l.lex` |                                  Specifies the lex command specification file that defines the lexical analysis rules.                                 |
|   `y.tab.h`  |                                      A header file containing define statements for the tokens used by the parser.                                     |
|  `lex.yy.c`  |                                    The C language source file that the lex command created for the lexical analyzer.                                   |

If I have time, I will also add the grammar in BNF format, as well as construct the First-Follow sets, and perhaps generate the LALR(1) grammar. 

## The Yacc/Bison Input File

`Yacc`/`Bison` takes as input a **context-free grammar** specification and produces a `C`-language function that recognizes correct instances of the grammar. The input file for the `Yacc`/`Bison` utility is a `Yacc`/`Bison` grammar file. The Yacc/Bison grammar input file conventionally has a name ending in `.y`.

A `Yacc`/`Bison` grammar file has four main sections, shown here with the appropriate delimiters: 
```yacc
    %{
    C declarations
    %}
    Yacc/Bison declarations
    %%
    Grammar rules
    %%
    Additional C code
```
### Tips on Writing a Parser File with Yacc/Bison
* Comments enclosed in `/* ... */` may appear in any of the sections. The `%%`, `%{` and `%}` are punctuation that appears in every `Yacc`/`Bison` grammar file to separate the sections.
* The `C` declarations may define types and variables used in the actions. You can also use preprocessor commands to define macros used there, and use `\#include` to include header files that do any of these things.
* The `Yacc`/`Bison` declarations declare the names of the terminal and nonterminal symbols, and may also describe operator precedence and the data types of semantic values of various symbols.
* The grammar rules define how to construct each nonterminal symbol from its parts.
* The additional `C` code can contain any `C` code you want to use. Often the definition of the lexical analyzer `yylex` goes here, plus subroutines called by the actions in the grammar rules. In a simple program, all the rest of the program can go here. 

# eBNF Grammar
> (AKA reverse engineering the grammar from the specification of the MINI-L language given as well as applicative `.min` files)

The following grammar is written in eBNF (extended Backus-Naur Form) to show the productions taken by a CFG (Context-Free Grammar) language. Building upon our previous work from the first phase to create a lexical analyzer with the specified language, we have already outlined the order of precedence. Now we can model the deterministic grammar of the language, boiling it down to the very essence of its syntax to apply semantic analysis to the tokens defined. This is required and I would have not completed the assignment had I not spent too much time re-studying my linguistics/automata notes.
### Table of Contents 
1. [Program](#)
2. [Function](#Function)
3. [Declaration](#Declaration)
4.   [declarations](#Declarations)
5. [Statement](#Statement)
6. [Statements](#Statements)
7. [Bool-Expr](#BooleanExpression)
8. [Relation-AND-Expr](#RelationAndExpression)
9. [Relation-Expr](#RelationExpression)
10. [Comp](#Comp)
11. [Expression](#Expression)
12. [Multiplicative-Expr](#MultiplicativeExpression)
13. [term](#Term)
14. [var](#var)

<style>
  .ebnf div
    {
      padding-left: 13ch;
      text-indent: -13ch;
    }
    .ebnf code, .grammar code, textarea, pre
    {
      font:12px SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace;
    }
</style>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      
      
<meta name="generator" content="Railroad Diagram Generator 1.63">

<p style="font-size: 14px; font-weight:bold"><a name="Program">Program:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/program.png" height="57" width="173" usemap="#Program.map"><map name="Program.map"><area shape="rect" coords="49,1,123,33" href="#Function" title="Function"></map><p>

<div class="ebnf"><code>
               
<div><a href="#Program" title="Program">Program</a>&nbsp;&nbsp;::= <a href="#Function" title="Function">Function</a>*</div></code></div>
<div><a href="#Program" title="Program">Program</a>&nbsp;&nbsp;::= <a href="#Function" title="Function">Function</a>*</div></code></div>
         </p>
      
<p>no references</p><br><p style="font-size: 14px; font-weight:bold"><a name="Function">Function:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/function.png" height="167" width="867" usemap="#Function.map"><map name="Function.map"><area shape="rect" coords="437,17,529,49" href="#Declaration" title="Declaration"><area shape="rect" coords="161,115,253,147" href="#Declaration" title="Declaration"><area shape="rect" coords="589,115,675,147" href="#Statement" title="Statement"></map><p>
    
<div class="ebnf"><code>
    
<div><a href="#Function" title="Function">Function</a>&nbsp;::= 'function' 'identifier' ';' 'beginparams' ( <a href="#Declaration" title="Declaration">Declaration</a> ';' )* 'endparams' 'beginlocals' ( <a href="#Declaration" title="Declaration">Declaration</a> ';' )* 'endlocals' 'beginbody' ( <a href="#Statement" title="Statement">Statement</a> ';' )+ 'endbody'</div></code></div>
</p>

<p>referenced by:
    
<ul>

<li><a href="#Program" title="Program">Program</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="Declaration">Declaration:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/declaration.png" height="53" width="669"><p>

<div class="ebnf"><code>
    
<div><a href="#Declaration" title="Declaration">Declaration</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= ( 'identifier' ';' )+ ':' 'array' '[' 'number' ']' 'of' 'integer'</div></code></div>
</p>

<p>referenced by:
    
<ul>

<li><a href="#Function" title="Function">Function</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="Statement">Statement:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/statement.png" height="449" width="917" usemap="#Statement.map"><map name="Statement.map"><area shape="rect" coords="69,1,109,33" href="#var" title="var"><area shape="rect" coords="203,1,293,33" href="#Expression" title="Expression"><area shape="rect" coords="97,111,237,143" href="#BooleanExpression" title="BooleanExpression"><area shape="rect" coords="367,111,453,143" href="#Statement" title="Statement"><area shape="rect" coords="643,111,729,143" href="#Statement" title="Statement"><area shape="rect" coords="125,193,265,225" href="#BooleanExpression" title="BooleanExpression"><area shape="rect" coords="411,193,497,225" href="#Statement" title="Statement"><area shape="rect" coords="231,259,317,291" href="#Statement" title="Statement"><area shape="rect" coords="571,259,711,291" href="#BooleanExpression" title="BooleanExpression"><area shape="rect" coords="185,325,225,357" href="#var" title="var"></map><p>

<div class="ebnf"><code>

<div><a href="#Statement" title="Statement">Statement</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= ( <a href="#var" title="var">var</a> ':=' | 'return' ) <a href="#Expression" title="Expression">Expression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'if' <a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a> 'then' ( <a href="#Statement" title="Statement">Statement</a> ';' )* 'else' ( <a href="#Statement" title="Statement">Statement</a> ';' )+ 'endif'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'while' <a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a> 'beginloop' ( <a href="#Statement" title="Statement">Statement</a> ';' )+ 'endloop'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'do' 'beginloop' ( <a href="#Statement" title="Statement">Statement</a> ';' )+ 'endloop' 'while' <a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a></div>
    
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| ( 'read' | 'write' ) ( <a href="#var" title="var">var</a> ',' )+</div>
               
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'continue'</div></code></div>
</p>
 <p>referenced by:
         
<ul>

<li><a href="#Function" title="Function">Function</a></li>

<li><a href="#Statement" title="Statement">Statement</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="BooleanExpression">BooleanExpression:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/bool-expr.png" height="103" width="391" usemap="#BooleanExpression.map"><map name="BooleanExpression.map"><area shape="rect" coords="49,1,241,33" href="#RelationshipAndExpression" title="RelationshipAndExpression"><area shape="rect" coords="129,67,321,99" href="#RelationshipAndExpression" title="RelationshipAndExpression"></map><p>

<div class="ebnf"><code>

<div><a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= <a href="#RelationshipAndExpression" title="RelationshipAndExpression">RelationshipAndExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| ( 'OR' <a href="#RelationshipAndExpression" title="RelationshipAndExpression">RelationshipAndExpression</a> )+</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a></li>

<li><a href="#Statement" title="Statement">Statement</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="RelationshipAndExpression">RelationshipAndExpression:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/relation-and-expr.png" height="103" width="375" usemap="#RelationshipAndExpression.map"><map name="RelationshipAndExpression.map"><area shape="rect" coords="49,1,217,33" href="#RelationshipExpression" title="RelationshipExpression"><area shape="rect" coords="137,67,305,99" href="#RelationshipExpression" title="RelationshipExpression"></map><p>

<div class="ebnf"><code>

<div><a href="#RelationshipAndExpression" title="RelationshipAndExpression">RelationshipAndExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= <a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| ( 'AND' <a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a> )+</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="RelationshipExpression">RelationshipExpression:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/relation-expr.png" height="203" width="483" usemap="#RelationshipExpression.map"><map name="RelationshipExpression.map"><area shape="rect" coords="157,35,247,67" href="#Expression" title="Expression"><area shape="rect" coords="267,35,323,67" href="#Comp" title="Comp"><area shape="rect" coords="343,35,433,67" href="#Expression" title="Expression"><area shape="rect" coords="203,167,343,199" href="#BooleanExpression" title="BooleanExpression"></map><p>

<div class="ebnf"><code>

<div><a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= 'NOT'* ( <a href="#Expression" title="Expression">Expression</a> <a href="#Comp" title="Comp">Comp</a> <a href="#Expression" title="Expression">Expression</a> | 'true' | 'false' | '(' <a href="#BooleanExpression" title="BooleanExpression">BooleanExpression</a> ')' )</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#RelationshipAndExpression" title="RelationshipAndExpression">RelationshipAndExpression</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="Comp">Comp:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/comp.png" height="257" width="135"><p>

<div class="ebnf"><code>

<div><a href="#Comp" title="Comp">Comp</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= 'eq'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'ne'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'lt'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'le'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'gt'</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'ge'</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="Expression">Expression:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/expression.png" height="113" width="319" usemap="#Expression.map"><map name="Expression.map"><area shape="rect" coords="119,1,289,33" href="#MultiplicativeExpression" title="MultiplicativeExpression"></map><p>

<div class="ebnf"><code>

<div><a href="#Expression" title="Expression">Expression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= ( '+' | '-' )? <a href="#MultiplicativeExpression" title="MultiplicativeExpression">MultiplicativeExpression</a></div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#RelationshipExpression" title="RelationshipExpression">RelationshipExpression</a></li>

<li><a href="#Statement" title="Statement">Statement</a></li>

<li><a href="#Term" title="Term">Term</a></li>

<li><a href="#var" title="var">var</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="MultiplicativeExpression">MultiplicativeExpression:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/multiplicative-expr.png" height="157" width="205" usemap="#MultiplicativeExpression.map"><map name="MultiplicativeExpression.map"><area shape="rect" coords="123,1,175,33" href="#Term" title="Term"></map><p>

<div class="ebnf"><code>

<div><a href="#MultiplicativeExpression" title="MultiplicativeExpression">MultiplicativeExpression</a></div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= ( '*' | '/' | '%' )? <a href="#Term" title="Term">Term</a></div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#Expression" title="Expression">Expression</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="Term">Term:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/term.png" height="273" width="507" usemap="#Term.map"><map name="Term.map"><area shape="rect" coords="155,67,195,99" href="#var" title="var"><area shape="rect" coords="201,155,291,187" href="#Expression" title="Expression"><area shape="rect" coords="237,221,327,253" href="#Expression" title="Expression"></map><p>

<div class="ebnf"><code>

<div><a href="#Term" title="Term">Term</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= '-'* ( <a href="#var" title="var">var</a> | 'number' | '(' <a href="#Expression" title="Expression">Expression</a> ')' )?</div>

<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 'identifier' '(' ( <a href="#Expression" title="Expression">Expression</a> ',' )* ')'</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#MultiplicativeExpression" title="MultiplicativeExpression">MultiplicativeExpression</a></li>
</ul>
</p><br><p style="font-size: 14px; font-weight:bold"><a name="var">var:</a></p><img border="0" src="/Users/masgh003/Documents/GitHub/MINI-L-ft.-boz/docs/img/var.png" height="69" width="383" usemap="#var.map"><map name="var.map"><area shape="rect" coords="197,33,287,65" href="#Expression" title="Expression"></map><p>

<div class="ebnf"><code>

<div><a href="#var" title="var">var</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::= 'identifier' ( '[' <a href="#Expression" title="Expression">Expression</a> ']' )?</div></code></div>
</p>

<p>referenced by:

<ul>

<li><a href="#Statement" title="Statement">Statement</a></li>

<li><a href="#Term" title="Term">Term</a></li>
</ul>
</p>