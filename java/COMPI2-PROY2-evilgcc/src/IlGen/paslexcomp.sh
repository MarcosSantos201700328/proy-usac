jflex pascal.l && mv pascal.l.java PascalLexer.java
cup -parser PascalParser -symbols SymPascal -dump_states -dump_grammar pascal.cup
#-dump_states -dump_grammar