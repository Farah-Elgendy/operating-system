# Backup Directory
## Overview of the code 
this project shows how to copy the contents of a directory such as files and subdirectories to another one as a Backup, then we have the source and the destination directory , and we have two files that store in it the names of the files inside the source directory to compare every interval of time if there is a modification.
If there is a modification in the source directory , we repeat the backup opertation with the new contents but there is a maximum number of backups that if it is exceeded , it automatically deletes the oldest backup directory.
To run the bash script, we use a makefile that helps us to pass the arguments and run the code when writing the command line.
## Steps that the user should do to run the code
The user should just open the terminal and write make as following: "make"
and it will run using the makefile.
If the user does not want to run it using the makefile , he can just type the following in the terminal:"./lab2.sh ~/(source_directory) ~/(destination_direcctory) time_interval max_backups".
But the user should be aware while entering the parameters and follow these rules: entering only 4 parameters , the source destination should already exist and the time and the maximum nuber of backups should be integer.
## Installation needed
If the user wants to run the program through the makefile, then he should install the make command by writing the following in the terminal:
```sudo apt install make```




