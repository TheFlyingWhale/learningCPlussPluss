# learningCPlussPluss

This project serves the purpose of letting me learn C++ by actually programming
<br>

## Install and Compile

### Install boost

```console
$ [package_manager_of_your_choice] install boost
```

If you're using the provided task.json file for compiling with VS Code, remove the following flag <br>
`"-L/opt/homebrew/Cellar/boost/1.82.0_1/lib"`
<br>
<br>

### Compile with VS Code

Open the command palette

OSX: <kbd>Shift</kbd> + <kbd>Cmd</kbd> + <kbd>P</kbd>

Windows:
<kbd>Shift</kbd> + <kbd>Ctrl</kbd> + <kbd>P</kbd>

Type:
`Run Build Task`
<br>
<br>

### Compile trough the console

```console
$ clang++ -std=c++17 -fcolor-diagnostics -fansi-escape-codes -lboost_system -lboost_filesystem -I./src/** ./src/main.cpp ./src/**/*.cpp ./src/**/**/*.cpp -o main
```

<br>

## Run program

In the terminal navigate to the root folder and run it <br>

```console
$ ./main
```
