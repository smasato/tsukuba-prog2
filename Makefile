# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = cmake

# The command to remove a file.
RM = cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = ./

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = ./bin

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start ./CMakeFiles ./CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start ./CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_ranking

# Build rule for target.
test_ranking: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_ranking
.PHONY : test_ranking

# fast build rule for target.
test_ranking/fast:
	$(MAKE) -f CMakeFiles/test_ranking.dir/build.make CMakeFiles/test_ranking.dir/build
.PHONY : test_ranking/fast

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named Timer

# Build rule for target.
Timer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Timer
.PHONY : Timer

# fast build rule for target.
Timer/fast:
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/build
.PHONY : Timer/fast

#=============================================================================
# Target rules for targets named Text

# Build rule for target.
Text: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Text
.PHONY : Text

# fast build rule for target.
Text/fast:
	$(MAKE) -f CMakeFiles/Text.dir/build.make CMakeFiles/Text.dir/build
.PHONY : Text/fast

#=============================================================================
# Target rules for targets named Ranking

# Build rule for target.
Ranking: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Ranking
.PHONY : Ranking

# fast build rule for target.
Ranking/fast:
	$(MAKE) -f CMakeFiles/Ranking.dir/build.make CMakeFiles/Ranking.dir/build
.PHONY : Ranking/fast

#=============================================================================
# Target rules for targets named Texture

# Build rule for target.
Texture: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Texture
.PHONY : Texture

# fast build rule for target.
Texture/fast:
	$(MAKE) -f CMakeFiles/Texture.dir/build.make CMakeFiles/Texture.dir/build
.PHONY : Texture/fast

lib/Ranking.o: lib/Ranking.c.o

.PHONY : lib/Ranking.o

# target to build an object file
lib/Ranking.c.o:
	$(MAKE) -f CMakeFiles/Ranking.dir/build.make CMakeFiles/Ranking.dir/lib/Ranking.c.o
.PHONY : lib/Ranking.c.o

lib/Ranking.i: lib/Ranking.c.i

.PHONY : lib/Ranking.i

# target to preprocess a source file
lib/Ranking.c.i:
	$(MAKE) -f CMakeFiles/Ranking.dir/build.make CMakeFiles/Ranking.dir/lib/Ranking.c.i
.PHONY : lib/Ranking.c.i

lib/Ranking.s: lib/Ranking.c.s

.PHONY : lib/Ranking.s

# target to generate assembly for a file
lib/Ranking.c.s:
	$(MAKE) -f CMakeFiles/Ranking.dir/build.make CMakeFiles/Ranking.dir/lib/Ranking.c.s
.PHONY : lib/Ranking.c.s

lib/Text.o: lib/Text.c.o

.PHONY : lib/Text.o

# target to build an object file
lib/Text.c.o:
	$(MAKE) -f CMakeFiles/Text.dir/build.make CMakeFiles/Text.dir/lib/Text.c.o
.PHONY : lib/Text.c.o

lib/Text.i: lib/Text.c.i

.PHONY : lib/Text.i

# target to preprocess a source file
lib/Text.c.i:
	$(MAKE) -f CMakeFiles/Text.dir/build.make CMakeFiles/Text.dir/lib/Text.c.i
.PHONY : lib/Text.c.i

lib/Text.s: lib/Text.c.s

.PHONY : lib/Text.s

# target to generate assembly for a file
lib/Text.c.s:
	$(MAKE) -f CMakeFiles/Text.dir/build.make CMakeFiles/Text.dir/lib/Text.c.s
.PHONY : lib/Text.c.s

lib/Texture.o: lib/Texture.c.o

.PHONY : lib/Texture.o

# target to build an object file
lib/Texture.c.o:
	$(MAKE) -f CMakeFiles/Texture.dir/build.make CMakeFiles/Texture.dir/lib/Texture.c.o
.PHONY : lib/Texture.c.o

lib/Texture.i: lib/Texture.c.i

.PHONY : lib/Texture.i

# target to preprocess a source file
lib/Texture.c.i:
	$(MAKE) -f CMakeFiles/Texture.dir/build.make CMakeFiles/Texture.dir/lib/Texture.c.i
.PHONY : lib/Texture.c.i

lib/Texture.s: lib/Texture.c.s

.PHONY : lib/Texture.s

# target to generate assembly for a file
lib/Texture.c.s:
	$(MAKE) -f CMakeFiles/Texture.dir/build.make CMakeFiles/Texture.dir/lib/Texture.c.s
.PHONY : lib/Texture.c.s

lib/Timer.o: lib/Timer.c.o

.PHONY : lib/Timer.o

# target to build an object file
lib/Timer.c.o:
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/lib/Timer.c.o
.PHONY : lib/Timer.c.o

lib/Timer.i: lib/Timer.c.i

.PHONY : lib/Timer.i

# target to preprocess a source file
lib/Timer.c.i:
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/lib/Timer.c.i
.PHONY : lib/Timer.c.i

lib/Timer.s: lib/Timer.c.s

.PHONY : lib/Timer.s

# target to generate assembly for a file
lib/Timer.c.s:
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/lib/Timer.c.s
.PHONY : lib/Timer.c.s

src/main.o: src/main.c.o

.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.s
.PHONY : src/main.c.s

test/ranking.o: test/ranking.c.o

.PHONY : test/ranking.o

# target to build an object file
test/ranking.c.o:
	$(MAKE) -f CMakeFiles/test_ranking.dir/build.make CMakeFiles/test_ranking.dir/test/ranking.c.o
.PHONY : test/ranking.c.o

test/ranking.i: test/ranking.c.i

.PHONY : test/ranking.i

# target to preprocess a source file
test/ranking.c.i:
	$(MAKE) -f CMakeFiles/test_ranking.dir/build.make CMakeFiles/test_ranking.dir/test/ranking.c.i
.PHONY : test/ranking.c.i

test/ranking.s: test/ranking.c.s

.PHONY : test/ranking.s

# target to generate assembly for a file
test/ranking.c.s:
	$(MAKE) -f CMakeFiles/test_ranking.dir/build.make CMakeFiles/test_ranking.dir/test/ranking.c.s
.PHONY : test/ranking.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... test_ranking"
	@echo "... main"
	@echo "... Timer"
	@echo "... Text"
	@echo "... Ranking"
	@echo "... Texture"
	@echo "... lib/Ranking.o"
	@echo "... lib/Ranking.i"
	@echo "... lib/Ranking.s"
	@echo "... lib/Text.o"
	@echo "... lib/Text.i"
	@echo "... lib/Text.s"
	@echo "... lib/Texture.o"
	@echo "... lib/Texture.i"
	@echo "... lib/Texture.s"
	@echo "... lib/Timer.o"
	@echo "... lib/Timer.i"
	@echo "... lib/Timer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... test/ranking.o"
	@echo "... test/ranking.i"
	@echo "... test/ranking.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

