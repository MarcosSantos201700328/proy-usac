ElectricSheet, A humble spreadsheet application.
(c) 2006 Erik Giron

Requirements
Java JRE 1.5 +


This is another little project made for the Data Structures in the beggining of my career, It is a humble spreadsheet application written in Java, that use a parser and a lexer to validate simple formulas consisting in arithmetic operations, and store using the MVC design pattern inherent of Swing Toolkit, it stores the data in a sparse array in memory ("the model"). and with the swing interfaces ("the controller") allows to show in a JPanel ("the view") the data stored and retrieved

The project was made in Netbeans IDE.  





To run the project from the command line, go to the dist folder and
type the following:

java -jar "electric_sheet.jar" 

To distribute this project, zip up the dist folder (including the lib folder)
and distribute the ZIP file.

Notes:

* If two JAR files on the project classpath have the same name, only the first
JAR file is copied to the lib folder.
* If the classpath contains a folder of classes or resources, none of the
classpath elements are copied to the dist folder.
* If a library on the projects classpath also has a Class-Path element
specified in the manifest,the content of the Class-Path element has to be on
the projects runtime path.
* To set a main class in a standard Java project, right-click the project node
in the Projects window and choose Properties. Then click Run and enter the
class name in the Main Class field. Alternatively, you can manually type the
class name in the manifest Main-Class element.
