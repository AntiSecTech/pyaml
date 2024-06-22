# pyaml - YAML Parser in C

This README provides a comprehensive guide to the project, including its features, installation steps and usage.
----------------------------------------------------------------------------------------------------------------

**pyaml** is a simple command-line tool written in C for parsing YAML files and retrieving values based on keys.

## Table of Contents
  - [Introduction](#introduction)
  - [Features](#features)
  - [Updates](#updates)
  - [Dependencies](#dependencies)
    - [Ubuntu/Debian](#ubuntudebian)
    - [Fedora](#fedora)
    - [Arch Linux](#arch-linux)
  - [Prerequisites](#prerequisites)
    - [Ubuntu/Debian](#ubuntudebian-1)
    - [Fedora](#fedora-1)
    - [Arch Linux](#arch-linux-1)
  - [Installation](#installation)
    - [Express-Installer for Debian](#express-installer)
      - [by using 'curl'](#by-using-curl)
      - [by using 'wget'](#by-using-wget)
    - [Clone the repository](#clone-the-repository)
    - [Compile the program](#compile-the-program)
    - [Install the program](#install-the-program)
  - [Uninstallation](#uninstallation)
  - [Usage](#usage)
  - [Help](#help)
  - [Files](#files)
  - [Examples](#examples)
  - [Advantages](#advantages)
  - [License](#license)

## Introduction

**pyaml** is a lightweight and efficient C program for parsing `YAML` files. It enables the extraction of values based on specific keys and is therefore ideal for configuration management and automation scripts.
It also shows you the contents of your `YAML` files with syntax highlighting if you only pass the file name as an argument.

---
## Features

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![GitHub Release](https://img.shields.io/github/v/release/AntiSecTech/pyaml)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](http://commonmark.org)
[![made-with-bash](https://img.shields.io/badge/Made%20with-Bash-1f425f.svg)](https://www.gnu.org/software/bash/)

- **Minimal Dependencies:** Only requires the `libyaml` library.
- **High Performance:** Written in C for speed and efficiency.
- **Ease of Use:** Simple command-line interface for easy integration.
- Parse YAML files.
- Retrieve nested values using dot notation for keys.
- **Syntax highlighting** file content.

* [X] supports the nested structure of embedded keywords
* [X] distinguishes in the spelling of the keywords
* [X] ![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white) hosted on [GitHub](https://github.com/AntiSecTech/pyaml)
* [X] ![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white) Version history control
* [X] ![Markdown](https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white) Markdown Documentary
* [X] ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) Installationroutine
* [X] ![Raspberry Pi](https://img.shields.io/badge/-RaspberryPi-C51A4A?style=for-the-badge&logo=Raspberry-Pi) runs on Raspberry

---
^ [UP to Index](#table-of-contents)
## Updates
This release is currently in version: ![GitHub Release](https://img.shields.io/github/v/release/AntiSecTech/pyaml)<br>
Please refer to the changelog for all information on current changes.<br>
You can view it [here](https://github.com/AntiSecTech/pyaml/blob/main/CHANGELOG.md).

---
^ [UP to Index](#table-of-contents)
## Dependencies

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

---
^ [UP to Index](#table-of-contents)
## Prerequisites

To compile the C program, you need to have the `GCC` compiler installed on your system. Below are the instructions for installing `GCC` on different Linux distributions:

### Ubuntu/Debian:

```sh
sudo apt-get update
sudo install gcc
```

### Fedora:

```sh
sudo dnf install gcc
```

### Arch Linux:

```sh
sudo pacman -S gcc
```

---
^ [UP to Index](#table-of-contents)
## Installation

### Express-Installer

You can use the following line with extended rights to perform a fully automated express installation as a shell script on Debian-based systems.<br>
***Check the [source code for the express-installer](https://gist.github.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5) shell script [here](https://gist.github.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5), if you do not have enough trust to run the script with root privileges***

#### by using ``curl``

```sh
curl -sSL https://gist.githubusercontent.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5/raw/7bcfb55ff2b186f3d960eb7366497fc4025cd532/pyaml-deb_installer.sh -o pyaml-installer.sh && chmod +x ./pyaml-installer.sh && sudo ./pyaml-installer.sh
```

#### by using ``wget``

```sh
wget -q https://gist.githubusercontent.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5/raw/7bcfb55ff2b186f3d960eb7366497fc4025cd532/pyaml-deb_installer.sh -O pyaml-installer.sh && chmod +x ./pyaml-installer.sh && sudo ./pyaml-installer.sh
```

or take the following steps for the classic route

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

If you have any further questions about the `Make` process, please refer to the source code of the [`Makefile`](https://github.com/AntiSecTech/pyaml/blob/main/Makefile).

---
^ [UP to Index](#table-of-contents)
## Uninstallation

```sh
cd pyaml
sudo make uninstall
```

---
^ [UP to Index](#table-of-contents)
## Usage

```sh
   pyaml <file.yml> [<key>]
   pyaml -v | --version
   pyaml -h | --help
```

---
^ [UP to Index](#table-of-contents)
## Help

The following options are available to help you use pyaml.
- [X] Buildin documentation
- [ ] Manpage ( [issue](https://github.com/AntiSecTech/pyaml/issues/2)  )
- [X] Online documentation on [`github.com`](https://github.com/AntiSecTech/pyaml/blob/main/README.md)
- [ ] Online documentation on [`readthedocs.com`](https://pyaml.readthedocs.io/)

**Buildin**

```sh
   pyaml --help
```

**Buildin overview**
|command|switch|argument|optional argument|result
|---|---|---|---|---|
| **pyaml** | | \<filename\> | \<key\> | outputs the current value of the key |
| | | \<filename\> |  |  displays the contents of the specified file using `less` |
| | -h \| --help | | | displays this screen |
| | -v | | | shows the current version number of the build in the short version |
| | --version | | | shows the current version number of the build and the current release in the long version |
| --- | --- | --- | --- | --- |
| man | pyaml | | | displays the **pyaml** manpage in `groff` format |
| --- | --- | --- | --- | --- |
| make | | | | has the same effect as ``make all`` |
| make | all \| compile | | | Compiles the program from the source code and generates the executable binary file |
| make | clean | | | removes only the executable binary file recursively |
| **sudo** make | install | | | Compiles the program from the source code and creates the executable binary file which is then copied to the local folder for binary files |
| **sudo** make | uninstall | | | only removes the executable binary file from the local folder for binary files recursively |

**Manpage**

 - This function is **not yet** available!
```sh
   man pyaml
```

**GitHub**

Read the [documentation](https://github.com/AntiSecTech/pyaml/blob/main/README.md) carefully.
```
https://github.com/AntiSecTech/pyaml/blob/main/README.md
```

**ReadTheDocs**

 - This function is **not yet** available!
```
https://pyaml.readthedocs.io/
```

---
^ [UP to Index](#table-of-contents)
## Files

Here you will find a small overview of the files used and their locations.
|filename|filetype|project path|install path|description|
|---|---|---|---|---|
| pyaml | binary | ./pyaml | /usr/local/bin | executable binary |
| pyaml.c | plaintext | ./pyaml | | source code |
| pyaml.1 | groff | ./pyaml | /usr/share/man/man1 | documentation |
| config.yml | yaml | ./pyaml | ~/.config/pyaml | configuration |

> **Note** at the current time it may be that some of the listed files are not yet available or used. It is also possible that they can be found under a different path.

---
^ [UP to Index](#table-of-contents)
## Examples

Given the following YAML file `test.yml` on [Gist](https://gist.github.com/AntiSecTech/322b703950592662aec176737f194d98):
```yaml
main-key:
  keyword: "value"
  sub-key:
    inner-sub-keyword: "value"
next-key:
  keyword: "another-value"
  inner-sub-key:
    keyword: "nested values"
```
retrieve the following keys:
 - keyword
 - (next-key) keyword
 - (inner-sub) keyword

```sh
   pyaml test.yml main-key.keyword
   pyaml test.yml next-key.keyword
   pyaml test.yml next-key.inner-sub-key.keyword
```

Output:

```sh
   value
   another-value
   nested values
```
You must observe the spelling and take upper and lower case into account.

**Integrating `pyaml` with Bash Scripts**

One of the primary advantages of pyaml is its seamless integration with Bash scripts. This allows for dynamic reading and setting of configuration parameters directly within your scripts.

**Example Bash Script:**

```sh
   #!/bin/bash

   # Parse YAML file and store values in variables
   config_file="testme.yml"
   author=$(pyaml $config_file Release.Author)
   contact=$(pyaml $config_file Release.Contact)

   # Use the parsed values
   echo "Author: $author"
   echo "Contact: $contact"
```
```yaml
Release:
  Author: "AntiSecTech"
  Contact: "contact.antisec@pm.me"
```

Output:

```sh
   Author: AntiSecTech
   Contact: contact.antisec@pm.me
```

---
^ [UP to Index](#table-of-contents)
## Advantages

- **Efficiency**: Written in C, ***pyaml*** provides high-speed parsing capabilities, reducing overhead in scripts.
- **Simplicity**: With its straightforward command-line interface, ***pyaml*** can be easily integrated into existing workflows and automation scripts.
- **Flexibility**: Able to parse any standard YAML file, making it versatile for various applications and configurations.

---
^ [UP to Index](#table-of-contents)
## License

This project is licensed under the `MIT License`. See the [`LICENSE`](https://raw.githubusercontent.com/AntiSecTech/pyaml/main/LICENSE) file for more details.
