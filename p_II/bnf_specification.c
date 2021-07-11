/* MINI-L BNF Grammar specification
 * Melody Asghari
 * July 10, 2021
 * made by hand, diagrams generated on https://bottlecaps.de/rr/ui
 Preview  ::= 'terminals' = circle
           | nonterminals = rectangle
           | EBNF - expression
    copy for format:

         ::= 
 */
 //Program
 Program ::= (Function? )* |
 //Function
 Function
          ::= 'function' 'identifier' ';' 'beginparams' (( Declaration ';')*) 'endparams' 'beginlocals' ((Declaration ';' )* ) 'endlocals' 'beginbody' ( Statement ';' )+ 'endbody'
 //Declaration, Expression 
Declaration ::=  ( 'identifier' ';' )+ ':' ( 'array' '[' 'number' ']' 'of' ) 'integer'
 //statement, expression, return SingLe Expression
 Statement
          ::= var ':=' Expression  //maybe 'var?'
          | 'if' BooleanExpression 'then' (Statement ';' )* 'else' ( Statement ';' )+ 'endif' //otherwise then<->else is '+' which i think the diagram is wrong for?
          | 'while' BooleanExpression 'beginloop' (Statement ';' )+ 'endloop'
          | 'do' 'beginloop' ( Statement ';' )+ 'endloop' 'while' BooleanExpression
          | 'read' ( ( var ) ',' )+
          | 'write' ( ( var )  ',' )+
          | 'continue'
          | 'return' Expression
//Bool-Expr
BooleanExpression
         ::= RelationshipAndExpression | ('OR' RelationshipAndExpression)+
//Relation-And-Expr
RelationshipAndExpression
         ::= RelationshipExpression | ('AND' RelationshipExpression)+
//Reelation-Expr
RelationshipExpression
         ::= 'NOT'* ( Expression Comp Expression | 'true' | 'false' | '(' BooleanExpression ')' )
//Comp
Comp
         ::= 'eq'
         | 'ne'
         | 'lt'
         | 'le'
         | 'gt'
         | 'ge'
//Expression (unary)
Expression
          ::= MultiplicativeExpression | ('+' | '-')MultiplicativeExpression
MultiplicativeExpression
         ::= Term | ( '*' | '/' | '%' ) Term
// Term
Term
         ::= '-'* ( var? | 'number'? | '(' Expression ')' )
        | 'identifier' '(' ( Expression ( ',' ) )* ')'
// var:
var
         ::= 'identifier'
         | 'identifier' '[' Expression ']'