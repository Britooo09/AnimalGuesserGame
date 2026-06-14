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

## Compiling

You can compile and build the project using Qt and CMake tools. Depending on your operating system, follow the specific instructions below to generate a production-ready deployment.

### Windows (Using Qt Creator & MSVC)

For Windows, it is highly recommended to use **Visual Studio 2022 (MSVC)** as the compiler within Qt Creator to ensure full compatibility.

1. **Open the Project:** Open Qt Creator and load the root `CMakeLists.txt` file.
2. **Build in Release Mode:** Select the **Release** build configuration and run the build process.
3. **Delete unnecessary files:** The build files will have been generated in `build/Desktop_Qt_[qt_version]_MSVC2022_64bit-Release`. Delete all the contents of this folder except for the file `animalguesser_gui.exe`, which is the program's executable.
4. **Deploy Dependencies:** Open the Qt Command Prompt matching your MSVC kit and run `windeployqt` to bundle all the required Qt dynamic libraries (.dll) next to your generated executable:
   ```bash
   windeployqt path/to/build/Desktop_Qt_[qt_version]_MSVC2022_64bit-Release/animalguesser_gui.exe
   ```

---

### Linux (Using Docker & linuxdeployqt)

To guarantee compatibility across different Linux distributions, the deployment package is built using a clean **Ubuntu 22.04 (Jammy Jellyfish)** Docker container and `linuxdeployqt`. Follow these steps from the root directory of the project:

#### 1. Start the Docker Container
Run an interactive Ubuntu container and mount your current working directory inside it:
```bash
docker run -it --rm -v $(pwd):/app ubuntu:jammy
```

#### 2. Install Build Dependencies
Inside the container, update the package manager and install the required tools and Qt6 development libraries:
```bash
apt update && apt install -y build-essential cmake qt6-base-dev wget libgl1-mesa-dev
```

#### 3. Compile the Project
Navigate to the mounted application directory, create the target build folder, and compile in **Release** mode:
```bash
cd /app
mkdir build-linux && cd build-linux
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

#### 4. Bundle and Deploy with linuxdeployqt
Download the `linuxdeployqt` AppImage, set the required environment variables, and bundle the GUI application with its dependencies:
```bash
wget https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage
chmod +x linuxdeployqt-continuous-x86_64.AppImage
export APPIMAGE_EXTRACT_AND_RUN=1
./linuxdeployqt-continuous-x86_64.AppImage ./animalguesser_gui -bundle-non-qt-libs -qmake=/usr/bin/qmake6
```

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## References

- [nlohmann/json](https://github.com/nlohmann/json)
- [Qt6 Documentation](https://doc.qt.io/qt-6/)
