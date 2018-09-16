# vcmd
#### updated to version v0.3
A simple command line written in C, when you are writing commands it's necessary to do a space between each parameters, even for calc function, so:
```c
calc 874 / 65
```
This won't work:
```c
calc 874/65
```
Command "d" is responsible for operations with directories, parameter -r is for removing directories:
```
d -r foldername
```
This command makes a directory with name "foldername":
```
d -m foldername
```
For operations with files use "f" command, for read use -rd parameter, this prints the content of "file.txt" to console:
```
f -rd file.txt
```
Same syntax is applied to this command with other parameters, even for writing to the files:
```
f -w file.txt
```
After this, you will get "prompt" to type the input, which should be written to your file.
There is also list "l" command, which has two aliases - "ll" and "ls"
```
l
```
This will make an output of the directory where the vcmd is currently running, for making an output of the directory placed two levels up from current working directory use:
```
l ../..
```
You can rename the directory or file via one command, use global command with -rn parameter
```
* -rn oldname.txt newname.txt
```
As I mentioned higher, you can do exactly the same thing with directories with this command.
