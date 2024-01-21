# Foobar-BIU
To compile ...
To execute ...

Workflow :
We worked together to convert the task into scrums in Jira, then we put them into relevant epics and decided to split the work.
Michael is working on the Main file and Asif is working on the Bloom Filter and the false positive solution, both working together on the docker file.

TDD :
Asif - I've worked on Bloom Filter class making tests for the constructor, using getters. Then, the AddItem function tested by checking if there's one's inside
the bit array using. getItem tested the most because I can test all the class function using this function.
All the tests build using google tests and the function built like studied in class, red green refactoring.

Refactoring : 
Asif - I've worked using the method we studied in class, red green refactoring.
After every green stage I did the most relevant refactoring, an example is to do less ifs or using get and set functions to use the same function to
find the value of the hash used on the URL. After that, we studied in class the correct structure of this project and we refactored the classes to 
work with less dependency with each other.
Hodaya: I joined some time after Asif and Michael had started the project, therefore I did less work. I've changed the arrays used in Bloomfilter to boolian in order to optimy the running time, extracted the UserInput class to an interface, and created a workflow that for every pull request into main will run all the tests. In addition, I've helped in the docker file part, although this is something we all did together.
