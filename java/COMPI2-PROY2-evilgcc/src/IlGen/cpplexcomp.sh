jflex cpp.l 
#&& mv cpp.l.java CppLexer.java 
cup -parser CppParser -symbols SymCpp -dump_states -dump_grammar  cpp.cup
#-dump_states -dump_grammar 
