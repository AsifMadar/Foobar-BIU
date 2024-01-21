# Foobar-BIU

## Compiling and Running
To locally run the program, you first need to setup your environment. Make sure you are in the root directory of the project, and run the following commands (assuming you are on Linux):
```bash
sudo apt-get update;
sudo apt-get install build-essential cmake libgtest-dev;
cmake -B build -S .
```

Afterwards, you can compile the program by executing `cmake --build build`

Finally, run the program using `./build/Foobar`

## Workflow
We worked together to convert the instructions into tasks in Jira, then we put them into relevent epics and decided on how we split the work.

Michael is working on the user-facing I/O, while Asif is working on the Bloom Filter (including verifying positive answers). Hodaya, who joined the project after Asif and Michael had already started working, worked mainly on refactoring existing code and on the workflow files.

### Development process
#### Asif
I've worked on Bloom Filter class making tests for the constructor, using getters. Then, the AddItem function tested by checking if there's one's inside
the bit array using. getItem tested the most because I can test all the class function using this function.
After that, I worked FalsePositive class, which returns true if the url is truley inside the blacklist.
Lastly I implemented two classes AddUrlToBlacklist and GetUrlFromBlacklist which implements the abstract class IAction.
All classes developed using TDD.

All the tests built using google tests and the function built like taught in class, red green refactoring.

#### Michael
I have worked on setting up the repositroy with the initial configuration files (namely `CMakeLists.txt`) and making sure everything works. After that, I have worked on reading, parsing and validating user input for the main loop, using the TDD methodology. First, I have written tests for the input-related functions using Google Test, then implemented the functions to pass those tests, and refactored those to be more generic and well-written. I later expanded my suite of functions to answer more specific needs, still using TDD.

After learning in class (pun not intended) that we are supposed to be using classes in pure OOP style, I started working on refactoring my code into OOP structures.

*Note:* I tend to prefer working with git locally rather than using the web interface, which means that my merges won't show up in the commit history or on the Pull Requests list. However, I can proudly say that apart from the very first few commits intended to set up the environment, I have only worked using feature branches (except one commit to main, c61dcea, that deleted build-related files that were pushed erroneously).

After finishing a Jira task, I would move that task to "done", choose another task from "to do" and move it to "in progress" before starting the next task.

### Refactoring
#### Asif
I've worked using the method we studied in class, red green refactoring.

After every green stage I did the most relevent refactoring, an example is to do less ifs or using get and set functions to use the same function to
find the value of the hash used on the URL. After that, we studied in class the correct structure of this project and we refactored the classes to 
work with less dependency with each other.

#### Hodaya
I joined some time after Asif and Michael had started the project, therefore I did less work. I've changed the arrays used in Bloomfilter to boolean in order to optimize the memory usage, extracted the UserInput class to an interface, and created a workflow that for every pull request into main will run all the tests. In addition, I've helped in the docker file part, although this is something we all did together.

#### Michael
I have also worked using TDD and "Red-Green-Refactor".

Some examples of my refactors would be adding comments and documentation, extracting literals into parameters and constants, making functions more generic and cleaning up code smells.
