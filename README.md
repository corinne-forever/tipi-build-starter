# About
Goals:
- Monorepo
- Try out tipi.build 
- Avoid using CMake where possible, in favor of a simpler solution.
- Local Docker container with all dependencies needed

# Building
```
tipi -t linux-cxx17 .
tipi run build/linux-cxx17/bin/src/example
```

# Test
tipi . -t linux-cxx17 --test all

# macOS
To install tipi, even with docker on mac, you need to install Rosetta. The install script tries to install rosetta itself, but fails for unclear reasons.

```
softwareupdate --install-rosetta
```
src: https://osxdaily.com/2020/12/04/how-install-rosetta-2-apple-silicon-mac/#:~:text=Another%20way%20to%20install%20Rosetta%202%20on%20the,every%20time%20we%20install%20anything%20on%20every%20device.

# TODO:
- Add Boost as described on tipi.build home page, rather than thru platform (version is very old)
- Have GoogleTest automatically pickup tests
  - Probably need to integrate CMakeLists.txt. Unsure how to have tipi pick it up. Maybe add_directory or whatever is from a top level CMakeLists.txt
- How to enable sanitizers?
- How do I run a clean if I am worried I have somehow ended up with something stale? Is there a folder I can delete?
- Running tests run other executables
- Add clang tooling (format, tidy, etc). It's not clear what compiler came with the image.
  - does tipi.build provide clang but it's not in my PATH?
- What would packaging look like?