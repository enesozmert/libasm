cmake_minimum_required(VERSION 3.10)
project(libasm LANGUAGES C ASM)

# Set the assembly source files
set(SRC
    src/ft_read.asm
    src/ft_strcmp.asm
    src/ft_strcpy.asm
    src/ft_write.asm
    src/ft_strlen.asm
    src/ft_strdup.asm
)

# Output library
set(NAME libasm.a)

# Add custom target for assembly files
foreach(src_file ${SRC})
    get_filename_component(src_file_we ${src_file} NAME_WE)
    add_custom_command(
        OUTPUT ${src_file_we}.o
        COMMAND nasm -f elf64 -o ${src_file_we}.o ${CMAKE_SOURCE_DIR}/${src_file}
        DEPENDS ${CMAKE_SOURCE_DIR}/${src_file}
        COMMENT "Assembling ${src_file}"
    )
    list(APPEND OBJ_FILES ${src_file_we}.o)
endforeach()

add_custom_target(asm_files ALL DEPENDS ${OBJ_FILES})

# Create the static library
add_library(${NAME} STATIC EXCLUDE_FROM_ALL ${OBJ_FILES})

# Ensure asm_files target is built before the library
add_dependencies(${NAME} asm_files)

# Add test executable
add_executable(test test_cases/main.c)
target_link_libraries(test ${NAME} c)

# Define custom targets for cleaning up
add_custom_target(clean_o
    COMMAND ${CMAKE_COMMAND} -E remove ${OBJ_FILES}
    COMMENT "Cleaning all .o files"
)

add_custom_target(fclean
    COMMAND ${CMAKE_COMMAND} -E remove ${NAME} test ${OBJ_FILES}
    COMMENT "Cleaning all .a files and test executable"
)

add_custom_target(rebuild
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target fclean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Rebuilding the project"
)

# Add custom command for running tests
add_custom_target(run_test
    COMMAND test "help"
    DEPENDS test
    COMMENT "Running test executable"
)
