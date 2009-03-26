jflex optimizer.l  && 
#&& mv cpp.l.java CppLexer.java 
cup -parser OptParser -symbols SymOpt -dump_states -dump_grammar  optimizer.cup
#-dump_states -dump_grammar 
