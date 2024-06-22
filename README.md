# pyaml - Version 1.1.1 - EXPERIMENTAL

This branch is used to develop the implementation of new functions.

## Changelog

- [X] Display the content of the YAML files if only the file name is passed as a parameter without key names whose values are to be output
-  [X] Attempts to implement syntax highlighting for displaying the content
-  [x] Configuration file created for various color themes
-  [x] Configuration file created for implementation in pyaml
-  [X] Implementing and processing the configuration file in pyaml
-  [ ] selectable color themes

## some tests
```sh
./pyaml test.yml
```
```sh
./pyaml config.yml
```
---

```sh
./pyaml test.yml main-key.keyword
```
```sh
./pyaml config.yml author.contact
```
---

```sh
./pyaml config.yml -v
```
```sh
./pyaml config.yml -v
```
---

```sh
./pyaml test.yml main-key.sub-key.inner-sub-keyword
```

```sh
./pyaml test.yml next-key.inner-sub-key.keyword
```

---
### Extensions and improvements are in the works
# it remains exciting :)
