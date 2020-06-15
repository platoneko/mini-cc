# mini-cc

## Requirements

- bison
- flex

## Supported Syntax

- datatype: int, float, char (only int in generating mips)
- function define, call
- array(Not pointer! Any arbitrary memory operation is not allowed!)
- while, nested if else
- `//` & `/*...*/` style comment

## Usage

```
make
bin/mini-cc <YOUR MINI-C FILE>
```
