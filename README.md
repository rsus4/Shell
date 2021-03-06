# Shell
Linux shell made using Linux system calls from C programs.

										OS ASSIGNMENT 1
											TASK2

We first take input by reading from the getline method and then parse it and free the memory that was allocated.

The internal commands implemented are:cd, echo, history, pwd, exit.
The external commands implemented are:ls, cat, date, rm, mkdir.

Shell Commands
Internal-
cd

	Errors handled:
		a)If more than one directory is specified.
		b)If the directory mentioned does not exist.

	Command options provided:
		a) "~" Takes user to home directory.
		b) -L  Default state of cd.

	Assumption
	    a)If no directory is mentioned move to home directory
		b)Use options in different commands 

echo

	Errors handled:
		a)If more than one directory is specified.
		b)If the directory mentioned does not exist.

	Command options provided:
		a) -n Newline charcter removed.
		b) "*"Prints contents of the current director.

	Assumption
		a)Use options in different commands. 

history

	Errors handled:
		a)If input provided is invalid an appropriate error message is printed to stderr.

	Command options provided:
		a) -c clears history

	Assumption
		a)Use options in different commands. 

pwd
	Errors handled:
		a)If more than one directory is specified.
		b)If the directory mentioned does not exist.

	Command options provided:
		a) -P displays physical directory without symlinks.
		b) -L does not resolve symlinks.

	Assumption
		a)Use options in different commands. 


External-
ls
	Errors handled:
		a)If the input is a file and not a directory
		b)Data leaks are prevented at every stage.

	Command options provided:
		a) -1 Displays each member of the directory in a separate line.
		b) -a Also prints the files and directories whose names start with a ‘.’.

	Assumption
	    a)cat only list dirrectories of the present directory
		b)Use options in different commands 

cat

	Errors handled:
		a)Checks if atleast 1 argument is given
		b)Checks if file exists or not

	Command options provided:
		a) -c It will show content with line number.
		b) -E Will highlight the end of line.

	Assumption
	    a)cat can only access one file at a time
		b)Use options in different commands 
date

	Errors handled:
		a)Gives an error if correct input format is not handled
		b)Data leaks are prevented at every stage.

	Command options provided:
		a) -u Prints UTC time.
		b) --help Prints information regarding functionality.

	Assumption
	    a)Do not use options that are not mentioned
		b)Use options in different commands 

rm

	Errors handled:
		a)Checks if atleast 1 argument is given
		b)Checks if the argument given is a file and not a directory

	Command options provided:
		a) -i Provides an interactive prompt before removing file.
		b) -v Displays the name of each file as it is removed.
	Assumptions:
		a)can only delete one file at a time
		b)Use options in different commands 

mkdir
	Errors handled:
		a)Checks if atleast 1 argument is given
		b)Checks if the directory doesn't exist previously

	Command options provided:
		a) -help It displays the help related information and exits.
		b) -v It displays a message for every directory created..
	Assumptions:
		a)Do not use options that are not mentioned
		b)Use options in different commands 


Test Case:
cd ..
cd Ass1
pwd -L
ls1
ls1 -a
cd ..
mkdir1 NewDirectory
