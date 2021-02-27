"""
Scripts which makes a supression file to be used with valgrind.

Requirements:
- clang++
- valgrind

Resources:
https://stackoverflow.com/a/36897737/2786884
"""


import subprocess  # nosec
from pathlib import Path
from typing import Tuple


def create_min_cxx() -> None:
    """Create min.cxx."""
    file_path = Path(__file__).parent.joinpath("min.cxx")
    if file_path.is_file():
        print(
            f"\033[91mWARNING\033[0m: {file_path} found, "
            "will not touch")
        return
    with file_path.open("w") as cxx_file:
        cxx_file.write("int main(){return 0;}")


def compile_min_cxx() -> None:
    """Compile min.cxx."""
    command = (
        r"clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow "
        r"-Wdouble-promotion -Wformat=2 -Wundef -Wconversion "
        r"-g3 -Os min.cxx -o mincxx"
    )
    run_subprocess(command)


def run_valgrind_on_program() -> None:
    """Run valgrind on min."""
    command = (
        r"valgrind --gen-suppressions=all --leak-check=full "
        r"--show-leak-kinds=all ./mincxx"
    )
    _, std_err = run_subprocess(command)

    file_path = Path(__file__).parent.joinpath("my.suppressions")
    with file_path.open("w") as suppression_file:
        suppression_file.write(std_err)


def clean_my_suppressions() -> None:
    """Clean - and = from the my.supression file."""
    file_path = Path(__file__).parent.joinpath("my.suppressions")
    with file_path.open("r") as suppression_file:
        original_lines = suppression_file.readlines()

    new_lines = list()
    for line in original_lines:
        if not (line.startswith("-") or line.startswith("=")):
            new_lines.append(line)

    new_lines_str = "".join(new_lines)

    with file_path.open("w") as suppression_file:
        suppression_file.write(new_lines_str)


def run_subprocess(command: str) -> Tuple[str, str]:
    """
    Run the subprocess.

    Parameters
    ----------
    command : str
        The command to be executed

    Returns
    -------
    std_out : str
        The standard output
    std_err : str
        The standard err

    Raises
    ------
    RuntimeError
        If the external call returns anything else than 0
    """
    process = subprocess.Popen(
        command.split(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=Path(__file__).parent,
        # https://docs.python.org/3/library/subprocess.html#security-considerations
        # https://github.com/PyCQA/bandit/issues/280
        shell=False,  # nosec
    )

    std_out_bytes, std_err_bytes = process.communicate()
    std_out = std_out_bytes.decode("utf-8")
    std_err = std_err_bytes.decode("utf-8")
    return_code = process.poll()

    if return_code != 0:
        raise RuntimeError(
            f"Command\n{command}\nfailed\n"
            f"\nstd_out reads\n{std_out}\n"
            f"\nstd_err reads\n{std_err}"
        )

    return std_out, std_err


def main() -> None:
    """Run the script."""
    create_min_cxx()
    compile_min_cxx()
    run_valgrind_on_program()
    clean_my_suppressions()
    print(
        "Compelete, test with\n"
        "valgrind --leak-check=full --show-leak-kinds=all "
        r"--suppressions=./my.suppressions ./mincxx"
    )
    print(
        "\033[91mWARNING\033[0m: STL may be leaky "
        "(in particular on OSX).\n"
        "Edit min.cxx to include code you want to supress and "
        "run this script again"
    )


if __name__ == "__main__":
    main()
