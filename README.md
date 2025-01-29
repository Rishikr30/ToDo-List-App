# ToDo-List-App
# To Do List Application Using C Programming Language

A simple and efficient command-line ToDo List application written in C that helps you manage your daily tasks effectively.

## Features

- Add new tasks with descriptions
- View all tasks with their status
- Mark tasks as complete
- Delete existing tasks
- Simple and intuitive command-line interface
- Data persistence across sessions

## Installation

1. Clone this repository:
```bash
git clone https://github.com/Rishikr30/ToDo-list-App.git
cd ToDO-List-App
```

2. Compile the program:
```bash
gcc todo.c -o todo
```

3. Run the application:
```bash
./todo
```

## Usage

The application provides a menu-driven interface with the following options:

1. **Add Task**: Enter a new task description when prompted.
```bash
Select option: 1
Enter task description: Complete project documentation
Task added successfully!
```

2. **View Tasks**: Displays all tasks with their status and ID.
```bash
Select option: 2
Tasks:
1. [  ] Complete project documentation
2. [✓] Send email to team
```

3. **Mark Task as Complete**: Enter the task ID to mark it as complete.
```bash
Select option: 3
Enter task ID: 1
Task marked as complete!
```

4. **Delete Task**: Remove a task by entering its ID.
```bash
Select option: 4
Enter task ID to delete: 2
Task deleted successfully!
```

## File Structure

```
todo-list-c/
│
├── todo.c          # Main source code
├── todo.h          # Header file with structures and function declarations
├── tasks.txt       # Data file for storing tasks
└── README.md       # Documentation
```

## Technical Details

- Written in C
- Uses file handling for data persistence
- Implements dynamic memory allocation for task management
- Error handling for invalid inputs and file operations

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Author

Rishi Kumar

## Acknowledgments

- Inspired by the need for a simple task management system
- Thanks to all contributors who have helped improve this project

## Support

If you encounter any issues or have suggestions for improvements, please open an issue in the GitHub repository.
