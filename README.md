# pyaml - Version 1.0.1 - YAML Parser in C
This README provides a comprehensive guide to the project, including its features, installation steps and usage.
---
**pyaml** is a simple command-line tool written in C for parsing YAML files and retrieving values based on keys.

## Table of Contents
  - [Introduction](#introduction)
  - [Features](#features)
  - [Dependencies](#dependencies)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
    - [Express-Installer](#express-installer)
    - [Clone the repository:](#clone-the-repository)
    - [Compile the program:](#compile-the-program)
    - [Install the program:](#install-the-program)
  - [Uninstallation](#uninstallation)
  - [Usage](#usage)
  - [Examples](#examples)
  - [Advantages](#advantages)
  - [License](#license)

## Introduction
**pyaml** is a lightweight and efficient C program designed for parsing YAML files. It allows users to extract values based on specified keys, making it ideal for configuration management and automation scripts.

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

* [X] supports the nested structure of embedded keywords
* [X] distinguishes in the spelling of the keywords
* [X] ![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white) hosted on [GitHub](https://github.com/AntiSecTech/pyaml)
* [X] ![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white) Version history control
* [X] ![Markdown](https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white) Markdown Documentary
* [X] ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) Installationroutine
* [X] ![Raspberry Pi](https://img.shields.io/badge/-RaspberryPi-C51A4A?style=for-the-badge&logo=Raspberry-Pi) runs on Raspberry

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

## Installation
### Express-Installer
You can use the following line with extended rights to perform a fully automatic express installation.

***Check the [source code for the express-installer](https://gist.github.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5) shell script [here](https://gist.github.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5), if you do not have enough trust to run the script with root privileges***
#### by using 'curl'
```sh
curl -sSL https://gist.githubusercontent.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5/raw/7bcfb55ff2b186f3d960eb7366497fc4025cd532/pyaml-deb_installer.sh -o pyaml-installer.sh && chmod +x ./pyaml-installer.sh && sudo ./pyaml-installer.sh
```
#### by using 'wget'
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
## Uninstallation
```sh
cd pyaml
sudo make uninstall
```

## Usage
```sh
   pyaml <file.yml> <key>
   pyaml -v | --version
   pyaml -h | --help
```

## Examples
Given the following YAML file `test.yml`:
```yaml
program:
  name: "pyaml"
  type: "parser"
  language: "C"
  architecture: "x86_64"
  system: "linux"
  build:
    version: "1.0.1"
    release: "stable"
    license: "MIT"
    author:
      name: "AntiSecTech"
      contact: "contact.antisec@pm.me"
```
To retrieve the `author` key:
```sh
   pyaml test.yml program.author.name
```
Output:
```sh
   AntiSecTech
```
**Integrating `pyaml` with Bash Scripts**
One of the primary advantages of pyaml is its seamless integration with Bash scripts. This allows for dynamic reading and setting of configuration parameters directly within your scripts.

**Example Bash Script:**
```sh
   #!/bin/bash

   # Parse YAML file and store values in variables
   config_file="test.yml"
   author=$(pyaml $config_file program.build.author.name)
   contact=$(pyaml $config_file program.build.author.contact)

   # Use the parsed values
   echo "Author: $author"
   echo "Contact: $contact"
```
Output:
```sh
   Author: AntiSecTech
   Contact: contact.antisec@pm.me
```

## Advantages
- **Efficiency**: Written in C, ***pyaml*** provides high-speed parsing capabilities, reducing overhead in scripts.
- **Simplicity**: With its straightforward command-line interface, ***pyaml*** can be easily integrated into existing workflows and automation scripts.
- **Flexibility**: Able to parse any standard YAML file, making it versatile for various applications and configurations.

## License
This project is licensed under the `MIT License`. See the [`LICENSE`](https://raw.githubusercontent.com/AntiSecTech/pyaml/main/LICENSE) file for more details.
