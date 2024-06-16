# pyaml

pyaml is a simple C program for parsing YAML files. It allows the extraction of values based on specified keys.

## Files in the Repository

- `pyaml.c`: The source code of the C program that parses YAML files and outputs values.
- `Makefile`: A makefile to manage the compilation process, installation, and uninstallation of the program.
- `test.yml`: A sample YAML file to demonstrate the functionality of the program.

## Prerequisites

The `libyaml` library is required to compile this project. It can be installed as follows:

### Ubuntu/Debian:
```sh
sudo apt-get update
sudo apt-get install libyaml-dev
```
### Fedora:

```sh
sudo dnf install libyaml-devel
```
### Arch Linux:
```sh
sudo pacman -S libyaml
```

## Installation
### Clone the repository:
```sh
git clone https://github.com/AntiSecTech/pyaml.git
cd pyaml
```

### Compile the program:
```sh
make compile
```
### Install the program:
```sh
sudo make install
```

## Usage

The program expects the filename of the YAML configuration file and the key whose value is to be output:

```sh
./pyaml <file.yaml> <key>
```

### Example:
```sh
./pyaml test.yml version
```

## Makefile Options
The Makefile provides the following commands:

- **make compile**: Compiles the source code and creates the executable yaml_parser.
- **make clean**: Removes the created executable file yaml_parser.
- **sudo make install**: Installs the program to `/usr/local/bin`, if the file does not already exist there.
- **sudo make uninstall**: Removes the program from `/usr/local/bin`, if it exists there.

## Example YAML File ***test.yml***
```yaml
program:
  name: "pyaml"
  type: "parser"
  language: "C"
  architecture: "x86_64"
  system: "linux"
  build:
    version: "1.0.0"
    release: "testing"
    license: "MIT"
    author:
      name: "AntiSecTech"
      contact: "contact.antisec@pm.me"
```

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
