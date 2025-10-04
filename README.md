
# Get Next Line

## Description

This project is about programming a function that returns a line
read from a file descriptor.
Through this project, I learned how to manage buffered input, handle multiple file descriptors, and most importantly, how to use static variables to preserve data between function calls.
## Usage

Clone the repository:  

```  
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line

```
Compile the mandatory part:  
```make```

This will generate the get_next_line.a library.  
You can include it in your program like this:  
```gcc main.c get_next_line.a```

Compile the bonus part:  
```make bonus```

To clean object files:  
```make clean```

To remove all binaries:  
```make fclean```

To rebuild everything:  
```make re```
## Skills Developed

File descriptor manipulation  
Static variable usage and memory persistence  
Reading data efficiently with buffers  
Handling multiple file descriptors simultaneously  
Clean and modular C design  
## Status

Project: Complete  
Final Grade: 125/100
