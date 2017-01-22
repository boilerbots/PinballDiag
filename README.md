# Pinball Diag

A diagnostic tool for Pinball 2000 machines with a GUI. The program uses QT for
a simple GUI. The code is written in C++ to have good control over the timing.
Use this tool with a Linux machine to debug the Pinball 2000 driver board on a
bench.

## Dependencies

You will need a linux machine, I built this on Ubuntu 16.04.

You will need the follow packages installed to build the source code:
* qtcreator

## Building the project

You can open the project in QT Creator and build or use the following on the
command line.

Make a build directory outside of the source tree:

```
mkdir build-PinballDiag-Desktop-Debug
```

Build

```
cd build-PinballDiag-Desktop-Debug
qmake ../PinballDiag/PinballDiag.pro -r -spec linux-g++-64 CONFIG+=debug
make
```

## Run

The executable should be in the build directory. You need to run this as root or
change the permissions but running it as root is easy.

```
sudo ./PinballDiag
```

## Authors

* **Curt Meyers**

## License

This project is licensed under the BSD license - see the [LICENSE.txt] file.

