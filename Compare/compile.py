from cyaron import *
import subprocess

source_file = "std.cpp"
output_file = "std.exe"
compile_command = f"g++ {source_file} -std=c++2a -o {output_file}"
subprocess.run(compile_command, check=True, shell=True)

source_file = "solve.cpp"
output_file = "solve.exe"
compile_command = f"g++ {source_file} -std=c++2a -o {output_file}"
subprocess.run(compile_command, check=True, shell=True)

# source_file = "data.cpp"
# output_file = "data.exe"
# compile_command = f"g++ {source_file} -std=c++2a -o {output_file}"
# subprocess.run(compile_command, check=True, shell=True)
