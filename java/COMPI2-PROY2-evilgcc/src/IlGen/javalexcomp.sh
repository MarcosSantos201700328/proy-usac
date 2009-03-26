jflex JavaLexer.l
# && mv JavaLexer.l.java JavaLexer.java
cup -parser JavaParser -symbols SymJava  JavaParser.cup
