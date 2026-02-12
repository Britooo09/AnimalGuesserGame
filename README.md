# Animal Guesser Game

A C++20 project that implements a classic animal guessing game using a binary tree structure. The game can be played via a Qt-based GUI. The project is modular, separating core logic from the user interface, and is designed for easy extension and portability.

## Features

- **Animal guessing game**: The program tries to guess the animal you are thinking of by asking yes/no questions.
- **Persistence**: The decision tree is saved and loaded in JSON format.
- **Modern C++**: Uses C++20 features and best practices.
- **Cross-platform**: Built with CMake and Ninja, compatible with major platforms.

## How to Play

1. The program will ask you a series of yes/no questions to guess your animal.
2. If it fails, you can go back to a question you were not sure about.
3. The tree of knowledge grows with each new animal learned.

## Contribution Guidelines

- Follow the naming and formatting conventions described in [CONTRIBUTING.md](CONTRIBUTING.md).
- Do not perform I/O operations in core logic; keep UI and logic separated.
- Use branches for each feature or fix, and submit pull requests for review.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## References

- [nlohmann/json](https://github.com/nlohmann/json)
- [Qt6 Documentation](https://doc.qt.io/qt-6/)
