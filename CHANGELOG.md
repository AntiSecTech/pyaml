# Changelog
All notable changes to this project will be documented in this file.
---

## Released
---

### Version 1.0.0-testing - 2024-06-16
#### ***pre-release*** `main`
- [X] Initial commit
- [X] README.md created
- [X] LICENSE created
- [X] Sourcecode 'pyaml.c'
- [X] Testfile 'test.yml'
- [X] Makefile created

Initial commit, project created
---

### Version 1.0.1-alpha stable - 2024-06-17
#### ***latest*** `main`
- [X] README.md updated
- [X] Makefile updated

##### added
- Issue [#1](https://github.com/AntiSecTech/pyaml/issues/1)

**Working release created**
- express installer 'pyaml-deb_installer.sh' created and uploaded on [gist](https://gist.github.com/AntiSecTech/79d34b3e5e049d37323c3267d136a4d5)
- updated the documentation and added link to express-installer

##### fixed
- privellegies issue in express-installer fixed
---

### Version 1.0.2-alpha stable - 2024-06-22
#### ***latest*** `main`
- [X] README.md updated

##### added
 - merged the `experimental` branch into `main` branch.
   - including `exp-features` v1.0.1-aplha and v1.1.1-alpha.
     For details view the `unreleased` section.

##### added - 2024-06-23
- [X] README.md updated
- [X] pyaml.c updated
- [X] Issue [#2](https://github.com/AntiSecTech/pyaml/issues/2)

 - Installation of the function for reading and applying color schemes.
 - Updating `README.md`, added the `Customize` section.
 - Updating `Makefile`, added Manpage in `install` section.

##### removed - 2024-06-23
 - `colors.yml` deleted.

## Unreleased
---

### Version 1.0.1-aplha unreleased - 2024-06-18
#### `experimental`

- [X] Display the content of the YAML files if only the file name is passed as a parameter without key names whose values are to be output
- [X] Attempts to implement syntax highlighting for displaying the content
- [X] Configuration file created for various color themes
- [X] Configuration file created for implementation in pyaml

##### added
 - try implementing parsing files with syntax highlighting
---

### Version 1.1.1-alpha unreleased - 2024-06-22
#### `experimental`

This state is used in the main branch under version 1.0.2

- [X] Implementing and processing the configuration file in pyaml

##### updated
 - README.md
 - config.yml was updating for merging the `experimental` branch into `main`.

##### added
 - Function added so that the version number is read from the configuration file.
 - CHANGELOG.md created.

##### fixed
 - `README.md` fixed unwanted issues in the `Table of Content` section
---
