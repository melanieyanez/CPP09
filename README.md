# CPP09 - BitcoinExchange, RPN & PmergeMe

## Description

This project is part of the 42 school curriculum and consists of three main exercises:

1. **BitcoinExchange** (ex00): A program that reads a CSV file containing Bitcoin exchange rates by date and allows you to convert values using these rates.
2. **RPN** (ex01): A program that evaluates expressions in Reverse Polish Notation (RPN).
3. **PmergeMe** (ex02): A program that sorts a sequence of positive integers using the "merge-insert" (Ford-Johnson) sorting algorithm. The program uses at least two different containers and displays the processing time for each container.

## Prerequisites

- C++ compiler compatible with the C++98 standard
- Makefile

## Installation

Clone this repository to your local directory:

```sh
git clone https://github.com/melanieyanez/CPP09.git
cd CPP09
```

## Compilation

Use the provided Makefile in each exercise directory to compile the programs:

### ex00 - BitcoinExchange

```sh
cd ex00
make
```

### ex01 - RPN

```sh
cd ../ex01
make
```

### ex02 - PmergeMe

```sh
cd ../ex02
make
```

## Usage

### ex00 - BitcoinExchange

The `btc` program reads a CSV file containing Bitcoin exchange rates and converts values using these rates.

#### Example usage:

```sh
./btc input.txt
```

- `input.txt`: File containing the values to convert.

### ex01 - RPN

The `RPN` program evaluates expressions in Reverse Polish Notation.

#### Example usage:

```sh
./RPN "3 4 + 2 * 7 /"
```

### ex02 - PmergeMe

The `PmergeMe` program sorts a sequence of positive integers using the "merge-insert" sorting algorithm. The program also displays the processing time for each container used.

#### Example usage:

```sh
./PmergeMe 3 5 9 7 4
```

## Project structure

```
.
├── README.md
├── ex00
│   ├── Makefile
│   ├── BitcoinExchange.cpp
│   ├── BitcoinExchange.hpp
│   ├── main.cpp
│   └── data
│       ├── data.csv
│       └── input.txt
├── ex01
│   ├── Makefile
│   ├── RPN.cpp
│   ├── RPN.hpp
│   ├── main.cpp
└── ex02
    ├── Makefile
    ├── PmergeMe.cpp
    ├── PmergeMe.hpp
    ├── main.cpp
```

- **README.md**: This documentation file.
- **ex00**: Directory containing the code and files for exercise 00 (BitcoinExchange).
- **ex01**: Directory containing the code and files for exercise 01 (RPN).
- **ex02**: Directory containing the code and files for exercise 02 (PmergeMe).

## Implementation details

### ex00 - BitcoinExchange

The `btc` program:

1. Reads Bitcoin exchange rates from a CSV file.
2. Validates and cleans the input data.
3. Uses a `std::map` to store the exchange rates by date.
4. Converts values using the corresponding exchange rates.

### ex01 - RPN

The `RPN` program:

1. Reads an expression in Reverse Polish Notation from the command line.
2. Uses a stack to evaluate the expression.
3. Handles basic arithmetic operations: addition, subtraction, multiplication, division.

### ex02 - PmergeMe

The `PmergeMe` program:

1. Reads command line arguments to get the sequence of integers to sort.
2. Sorts the sequence using the "merge-insert" algorithm for two different containers (`std::vector` and `std::list`).
3. Displays the sorted sequence and the processing time for each container.

## Author

This project was written by Melanie Yanez Pena as part of the 42 school curriculum.
