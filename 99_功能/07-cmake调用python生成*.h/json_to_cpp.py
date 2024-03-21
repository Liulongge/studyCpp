import json
import sys

def json_to_cpp(json_file, output_header):
    with open(json_file, 'r') as f:
        data = json.load(f)

    cpp_code = ''
    for key, value in data.items():
        number_string = ', '.join(map(str, value))
        cpp_code += f'static const char* {key} = {json.dumps(number_string)};\n'

    with open(output_header, 'w') as out_file:
        out_file.write(cpp_code)

if __name__ == "__main__":
    json_to_cpp(sys.argv[1], sys.argv[2])