*This project has been created as part of the 42 curriculum by lchamard*
### Description
Pipex is a project for understand how pipe work and to recode them. Pipe are using for give the result of a command to another command and with that do a chain of commandPipe are using for give the result of a command to another command and with that do a chain of commands.

### Instructions
Place you in the root directory of the project and execute make for generate `pipex` binary, make bonus for generate `pipex_bonus` binary or make re command for both.

The usage for the mandatory part is to use this structure :
```
./pipex infile cmd1 cmd2 outfile
```
And his bash equivalence is :
```
< infilde cmd1 | cmd2 > outfile
```

The usage for the bonus part with multiple command is to use this structure :
```
./pipex infile cmd1 cmd2 ... cmdx outfile
```
And his bash equivalence is :
```
< infilde cmd1 | cmd2 | ... | cmdx > outfile
```

The usage for the bonus part with herei_doc is to use this structure :
```
./pipex here_doc LIMITER cmd1 cmd2 outfile
```
And his bash equivalence is :
```
cmd1 << LIMITER | cmd2 >> outfile
```

The usage for the bonus part with multiple command and here_doc is to use this structure :
```
./pipex here_doc LIMITER cmd1 cmd2 ... cmdx outfile
```
And his bash equivalence is :
```
cmd1 << LIMITER | cmd2 | ... |cmdx > outfile
```

### Resources
My friend help me to understand the usage of functions. I use a little bit of AI for have a more precise documentation than the linux manual or the C documentation, than I also use.
